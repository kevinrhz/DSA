#pragma once

#include <cstddef>      // for size_t
#include <vector>       // for std::vector
#include <stdexcept>    // for std::out_of_range
#include <functional>   // for std::equal_to
#include "../Hash.h"    // your hash functor(s)

namespace dsa {

/**
 * @brief Base class handling storage, resizing, and common ops for
 *        open-addressing hash tables.
 *
 * Subclasses must implement probeIndex() to decide how collisions are probed.
 */
template<
    typename K,
    typename V,
    typename Hash     = Hash<K>,
    typename KeyEqual = std::equal_to<K>
>
class HashTableOpenAddressingBase {
protected:
    // ---- slot states ----
    enum class State { Empty, Occupied, Tombstone };

    struct Bucket {
        K     key;
        V     value;
        State state = State::Empty;
    };

    std::vector<Bucket> table_;              ///< underlying bucket array
    size_t              elementCount_ = 0;   ///< number of live entries
    float               maxLoadFactor_;      ///< when to trigger rehash
    Hash                hasher_;             ///< primary hash function
    KeyEqual            keyEqual_;           ///< key equality check

public:
    /**
     * @param capacity        initial number of slots (default 16)
     * @param maxLoadFactor  load factor threshold for rehash (default .5)
     */
    explicit
    HashTableOpenAddressingBase(size_t capacity = 16,
                                float  maxLoadFactor = 0.5f);

    /// Insert key/value. Returns false if key already exists.
    bool insert(const K& key, const V& value);

    /// Remove key. Returns false if not found.
    bool remove(const K& key);

    /// Find by key. Returns pointer to value or nullptr if missing.
    V* find(const K& key);
    const V* find(const K& key) const;

    /// Number of elements currently stored.
    size_t size() const;

    /// Remove all elements, reset to initial state.
    void clear();

protected:
    /**
     * @brief Compute the next index given a key & attempt number.
     * @param key     the key being probed
     * @param attempt 0-based probe count
     * @return index in [0..table_.size()) to inspect next
     */
    virtual size_t probeIndex(const K& key, size_t attempt) const = 0;

    /// Grow or shrink the underlying vector and re-insert occupied entries.
    void rehash(size_t newCapacity);

    /// Helper to pick the next capacity (e.g., double current).
    size_t nextCapacity() const;
};

} // namespace dsa

#include "HashTableOpenAddressingBase.tpp"