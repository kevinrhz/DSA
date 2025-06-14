#pragma once

#include "HashTableChaining.h"
#include "Hash.h"

namespace dsa {
    // Get hash bucket index
    template<typename K, typename V>
    size_t HashTableChaining<K, V>::getBucketIndex(const K& key) const {
        return Hash<K>{}(key) % buckets.size();
    }

    // Constructor
    template<typename K, typename V>
    HashTableChaining<K, V>::HashTableChaining(size_t initialCapacity) : buckets(initialCapacity), numElements(0) {}

    // Insert key-value pair
    template<typename K, typename V>
    void HashTableChaining<K, V>::insert(const K& key, const V& value) {
        size_t bucketIndex = getBucketIndex(key);
        Entry newEntry{key, value};

        DoublyLinkedList<Entry>& bucket = buckets[bucketIndex];
        typename DoublyLinkedList<Entry>::NodePtr node = bucket.find(newEntry);

        if (node != nullptr) {
            node->data.value = value; // update
        } else {
            bucket.append(newEntry); // insert new
            ++numElements;
        }
    }

    // Remove key-value pair
    template<typename K, typename V>
    bool HashTableChaining<K, V>::remove(const K& key) {
        size_t bucketIndex = getBucketIndex(key);
        Entry target{key, V{}};
        DoublyLinkedList<Entry>& bucket = buckets[bucketIndex];

        if (bucket.contains(target)) {
            bucket.remove(target);
            --numElements;
            return true;
        }
        return false;
    }

    // Get value from key
    template<typename K, typename V>
    V* HashTableChaining<K, V>::get(const K& key) {
        size_t bucketIndex = getBucketIndex(key);
        Entry target{key, V{}};
        typename DoublyLinkedList<Entry>::NodePtr node = buckets[bucketIndex].find(target);

        if (node != nullptr) {
            return &(node->data.value);
        }
        return nullptr;
    }

    // Check if table contains entry with key
    template<typename K, typename V>
    bool HashTableChaining<K, V>::containsKey(const K& key) const {
        size_t bucketIndex = getBucketIndex(key);
        Entry target{key, V{}};

        const DoublyLinkedList<Entry>& bucket = buckets[bucketIndex];
        return bucket.contains(target);
    }

    // Get table size
    template<typename K, typename V>
    size_t HashTableChaining<K, V>::size() const {
        return numElements;
    }

    // Check if table is empty
    template<typename K, typename V>
    bool HashTableChaining<K, V>::isEmpty() const {
        return numElements == 0;
    }

} // namespace dsa