#pragma once
#include "HashTableOpenAddressingBase.h"

namespace dsa {
    /**
     * @brief Open addressing hash table using linear probing.
     *
     * Collision resolution is handled by checking the next bucket sequentially.
     * The probe sequence is h(k), h(k)+1, h(k)+2, ... (mod capacity).
     * This method is simple but can suffer from primary clustering.
     */
    template<typename K, typename V, typename Hash = Hash<K>, typename KeyEqual = std::equal_to<K>>
    class LinearProbingHashTable
      : public HashTableOpenAddressingBase<K,V,Hash,KeyEqual>
    {
    public:
        using Base = HashTableOpenAddressingBase<K,V,Hash,KeyEqual>;
        using Base::Base;  // Inherit constructors

    protected:
        /**
         * @brief Computes the next probe index using a linear sequence.
         * @return `(h(key) + attempt) % capacity`
         */
        size_t probeIndex(const K& key, size_t attempt) const override {
            size_t cap = this->table_.size();
            size_t h   = this->hasher_(key) % cap;
            return (h + attempt) % cap;
        }
    };
} // namespace dsa
