#pragma once
#include "HashTableOpenAddressingBase.h"

namespace dsa {
    /**
     * @brief Open addressing hash table using quadratic probing.
     *
     * Collision resolution is handled by checking subsequent buckets at quadratically
     * increasing offsets. The probe sequence is h(k), h(k)+1^2, h(k)+2^2, ...
     * (mod capacity). This helps mitigate the primary clustering issue found in
     * linear probing.
     */
    template<typename K, typename V, typename Hash = Hash<K>, typename KeyEqual = std::equal_to<K>>
    class QuadraticProbingHashTable
      : public HashTableOpenAddressingBase<K,V,Hash,KeyEqual>
    {
    public:
        using Base = HashTableOpenAddressingBase<K,V,Hash,KeyEqual>;
        using Base::Base;

    protected:
        /**
         * @brief Computes the next probe index using a quadratic sequence.
         * @return `(h(key) + attempt^2) % capacity`
         */
        size_t probeIndex(const K& key, size_t attempt) const override {
            size_t cap = this->table_.size();
            size_t h   = this->hasher_(key) % cap;
            // e.g. h + 1^2, h + 2^2, h + 3^2, ...
            return (h + attempt * attempt) % cap;
        }
    };
} // namespace dsa
