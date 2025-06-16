#pragma once

#include <vector>
#include "../../LinkedLists/DoublyLinkedList.h"

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

namespace dsa {

    template<typename K, typename V>
    struct HashEntry {
        K key;
        V value;

        bool operator==(const HashEntry& other) const {
            return key == other.key;
        }
    };

    template<typename K, typename V>
    class HashTableChaining {
    private:
        using Entry = HashEntry<K, V>;

        std::vector<DoublyLinkedList<Entry>> buckets;
        size_t numElements;
        size_t getBucketIndex(const K& key) const;

    public:
        HashTableChaining(size_t initialCapacity = 16);

        void insert(const K& key, const V& value);
        bool remove(const K& key);
        V* get(const K& key);
        bool containsKey(const K& key) const;
        size_t size() const;
        bool isEmpty() const;

    };
} // namespace dsa

#include "HashTableChaining.tpp"
#endif //HASHTABLECHAINING_H
