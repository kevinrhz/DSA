#pragma once
#include <vector>
#include "../../LinkedLists/DoublyLinkedList.h"

namespace dsa {
    /**
     * @brief A simple key-value pair entry for the hash table.
     */
    template<typename K, typename V>
    struct HashEntry {
        K key;
        V value;

        // Equality operator used by the linked list's find/remove operations.
        bool operator==(const HashEntry& other) const {
            return key == other.key;
        }
    };

    /**
     * @brief A hash table implementation using separate chaining for collision resolution.
     *
     * Each bucket in the table is a dsa::DoublyLinkedList. When a collision occurs,
     * the new entry is simply added to the list at that bucket index.
     * The average time complexity for insert, remove, and get is O(1 + α), where
     * α is the load factor (size/capacity).
     *
     * @tparam K The key type.
     * @tparam V The value type.
     */
    template<typename K, typename V>
    class HashTableChaining {
    private:
        using Entry = HashEntry<K, V>;

        std::vector<DoublyLinkedList<Entry>> buckets;
        size_t numElements;

        /**
         * @brief Computes the bucket index for a given key.
         * @param key The key to hash.
         * @return The index in the buckets vector.
         */
        size_t getBucketIndex(const K& key) const;

    public:
        /**
         * @brief Constructs the hash table.
         * @param initialCapacity The initial number of buckets.
         */
        HashTableChaining(size_t initialCapacity = 16);

        /**
         * @brief Inserts a key-value pair. If the key already exists, updates the value. O(1) average.
         * @param key The key of the element.
         * @param value The value of the element.
         */
        void insert(const K& key, const V& value);

        /**
         * @brief Removes a key-value pair. O(1) average.
         * @param key The key to remove.
         * @return true if the key was found and removed, false otherwise.
         */
        bool remove(const K& key);

        /**
         * @brief Retrieves a pointer to the value associated with a key. O(1) average.
         * @param key The key to find.
         * @return A pointer to the value, or nullptr if the key is not found.
         */
        V* get(const K& key);

        /**
         * @brief Checks if a key exists in the table. O(1) average.
         * @param key The key to check.
         * @return true if the key exists, false otherwise.
         */
        bool containsKey(const K& key) const;

        /// @brief Returns the number of elements stored in the table. O(1).
        size_t size() const;

        /// @brief Checks if the table is empty. O(1).
        bool isEmpty() const;
    };
} // namespace dsa

#include "HashTableChaining.tpp"