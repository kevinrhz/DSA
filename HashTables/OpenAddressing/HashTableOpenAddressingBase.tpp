#include "HashTableOpenAddressingBase.h"

namespace dsa {

    template<typename K, typename V, typename Hash, typename KeyEqual>
    HashTableOpenAddressingBase<K, V, Hash, KeyEqual>::HashTableOpenAddressingBase(
        size_t capacity,
        float maxLoadFactor
    )
        : table_(capacity),    // vector of default-initialized Buckets
          elementCount_(0),
          maxLoadFactor_(maxLoadFactor),
          hasher_(),
          keyEqual_()
    {}

    template<typename K, typename V, typename Hash, typename KeyEqual>
    void HashTableOpenAddressingBase<K, V, Hash, KeyEqual>::rehash(size_t newCapacity) {
        std::vector<Bucket> oldTable = std::move(table_);

        table_.clear();
        table_.resize(newCapacity);
        elementCount_ = 0;

        for (const auto& bucket : oldTable) {
            if (bucket.state == State::Occupied) {
                insert(bucket.key, bucket.value);
            }
        }
    }

    template<typename K, typename V, typename Hash, typename KeyEqual>
    bool HashTableOpenAddressingBase<K, V, Hash, KeyEqual>::insert(const K& key, const V& value) {
        // Rehash if over load factor
        if ((elementCount_ + 1.0f) / table_.size() > maxLoadFactor_) {
            rehash(nextCapacity());
        }

        size_t firstTombstone = table_.size(); // no tombstone found yet

        for (size_t attempt = 0; attempt < table_.size(); ++attempt) {
            size_t idx = probeIndex(key, attempt);
            auto& bucket = table_[idx];

            if (bucket.state == State::Empty) {
                // If tombstone found earlier, insert there
                size_t insertIdx = (firstTombstone != table_.size()) ? firstTombstone : idx;
                table_[insertIdx] = Bucket{ key, value, State::Occupied };
                ++elementCount_;
                return true;
            }

            if (bucket.state == State::Tombstone) {
                if (firstTombstone == table_.size()) {
                    firstTombstone = idx;
                }
                continue;
            }

            if (bucket.state == State::Occupied && keyEqual_(bucket.key, key)) {
                // Duplicate key
                return false;
            }
        }
        return false;
    }

    template<typename K, typename V, typename Hash, typename KeyEqual>
    bool HashTableOpenAddressingBase<K, V, Hash, KeyEqual>::remove(const K& key) {
        for (size_t attempt = 0; attempt < table_.size(); ++attempt) {
            size_t idx = probeIndex(key, attempt);
            auto& bucket = table_[idx];

            if (bucket.state == State::Empty) return false; // key not found, stop
            if (bucket.state == State::Occupied && keyEqual_(bucket.key, key)) {
                bucket.state = State::Tombstone;
                --elementCount_;
                return true;
            }
            // Tombstone or mismatch -> keep probing
        }
        return false; // full scan, key not found
    }

    template<typename K, typename V, typename Hash, typename KeyEqual>
    V* HashTableOpenAddressingBase<K, V, Hash, KeyEqual>::find(const K& key) {
        for (size_t attempt = 0; attempt < table_.size(); ++attempt) {
            size_t idx = probeIndex(key, attempt);
            auto& bucket = table_[idx];

            if (bucket.state == State::Empty) return nullptr;
            if (bucket.state == State::Occupied && keyEqual_(bucket.key, key)) return &bucket.value;

            // else: keep probing (Tombstone or mismatch)
        }
        return nullptr;
    }

    template<typename K, typename V, typename Hash, typename KeyEqual>
    const V* HashTableOpenAddressingBase<K, V, Hash, KeyEqual>::find(const K& key) const {
        for (size_t attempt = 0; attempt < table_.size(); ++attempt) {
            size_t idx = probeIndex(key, attempt);
            const auto& bucket = table_[idx];

            if (bucket.state == State::Empty) return nullptr;
            if (bucket.state == State::Occupied && keyEqual_(bucket.key, key)) return &bucket.value;

            // else: keep probing (Tombstone or mismatch)
        }
        return nullptr;
    }

    template<typename K, typename V, typename Hash, typename KeyEqual>
    size_t HashTableOpenAddressingBase<K, V, Hash, KeyEqual>::size() const {
        return elementCount_;
    }

    template<typename K, typename V, typename Hash, typename KeyEqual>
    void HashTableOpenAddressingBase<K, V, Hash, KeyEqual>::clear() {
        for (auto& bucket : table_) { bucket.state = State::Empty; }
        elementCount_ = 0;
    }

    template<typename K, typename V, typename Hash, typename KeyEqual>
    size_t HashTableOpenAddressingBase<K, V, Hash, KeyEqual>::nextCapacity() const {
        return table_.size() == 0 ? 1 : table_.size() * 2;
    }

} // namespace dsa