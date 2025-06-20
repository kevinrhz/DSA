#pragma once

#include <cstddef>
#include <vector>
#include <stdexcept>
#include <functional>
#include "../Hash.h"

namespace dsa {
    /**
     * @brief An abstract base class for open addressing hash tables.
     *
     * This class handles the common logic for open addressing schemes, including
     * storage, resizing, and managing the state of each bucket (Empty, Occupied,
     * or Tombstone). The specific collision resolution strategy is deferred to
     * subclasses through the pure virtual `probeIndex` method.
     *
     * @tparam K The key type.
     * @tparam V The value type.
     * @tparam Hash The hash function object type.
     * @tparam KeyEqual The key equality comparison object type.
     */
    template<
        typename K,
        typename V,
        typename Hash     = Hash<K>,
        typename KeyEqual = std::equal_to<K>
    >
    class HashTableOpenAddressingBase {
    protected:
        /// @brief Represents the state of a bucket in the hash table.
        enum class State { Empty, Occupied, Tombstone };

        /**
         * @brief A bucket in the hash table, storing the key, value, and state.
         */
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
         * @brief Constructs the hash table.
         * @param capacity Initial number of buckets.
         * @param maxLoadFactor The load factor at which to trigger a rehash.
         */
        explicit
        HashTableOpenAddressingBase(size_t capacity = 16,
                                    float  maxLoadFactor = 0.5f);

        /// @brief Inserts a key/value pair. Returns false if key already exists.
        bool insert(const K& key, const V& value);

        /// @brief Removes a key. Uses a tombstone to mark the bucket as deleted.
        /// @return false if key is not found.
        bool remove(const K &key);

        /// @brief Finds a key and returns a pointer to its value.
        /// @return Pointer to the value, or nullptr if not found.
        V* find(const K& key);
        const V* find(const K& key) const;

        /// @brief Returns the number of elements in the table.
        size_t size() const;

        /// @brief Clears the hash table, resetting it to its initial state.
        void clear();

    protected:
        /**
         * @brief (Pure Virtual) The probing function to be implemented by subclasses.
         *
         * This function defines the specific open addressing strategy (linear, quadratic, etc.).
         * @param key The key being probed.
         * @param attempt The current probe attempt number (0-based).
         * @return The next bucket index to check.
         */
        virtual size_t probeIndex(const K& key, size_t attempt) const = 0;

        /// @brief Doubles the table capacity and re-inserts all elements.
        void rehash(size_t newCapacity);

        /// @brief Calculates the next capacity for the table, typically by doubling.
        size_t nextCapacity() const;
    };
} // namespace dsa

#include "HashTableOpenAddressingBase.tpp"