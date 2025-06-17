#pragma once
#include "HashTableOpenAddressingBase.h"

namespace dsa {

    /**
     * @brief secondary hash: must never return zero, and < cap.
     * A simple choice: 1 + (h2(key) % (cap-1))
     */
    static size_t secondaryHash(size_t h2, size_t cap) {
        return 1 + (h2 % (cap - 1));
    }

    template<typename K, typename V, typename Hash = Hash<K>, typename KeyEqual = std::equal_to<K>>
    class DoubleHashingHashTable
      : public HashTableOpenAddressingBase<K,V,Hash,KeyEqual>
    {
    public:
        using Base = HashTableOpenAddressingBase<K,V,Hash,KeyEqual>;
        using Base::Base;

    protected:
        size_t probeIndex(const K& key, size_t attempt) const override {
            size_t cap = this->table_.size();
            size_t h1  = this->hasher_(key) % cap;
            size_t h2  = secondaryHash(this->hasher_(key) >> 1, cap);
            return (h1 + attempt * h2) % cap;
        }
    };

} // namespace dsa
