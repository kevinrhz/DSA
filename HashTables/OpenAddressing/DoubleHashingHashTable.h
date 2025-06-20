#pragma once
#include "HashTableOpenAddressingBase.h"

namespace dsa {
    /**
     * @brief A secondary hash function for double hashing.
     *
     * It's crucial that this function never returns zero and is less than the capacity.
     * A common formula is `1 + (h2(key) % (capacity - 1))`.
     * @param h2 The result of a secondary hash calculation on the key.
     * @param cap The current capacity of the table.
     * @return The step size for probing.
     */
    static size_t secondaryHash(size_t h2, size_t cap) {
        // The secondary hash must not be 0 and should be relatively prime to the capacity.
        // A prime capacity and this formula help ensure this.
        return 1 + (h2 % (cap - 1));
    }

    /**
     * @brief Open addressing hash table using double hashing.
     *
     * This method uses a second hash function to determine the step size for
     * probing, which helps to eliminate both primary and secondary clustering.
     * The probe sequence is `(h1(k) + attempt * h2(k)) % capacity`.
     */
    template<typename K, typename V, typename Hash = Hash<K>, typename KeyEqual = std::equal_to<K>>
    class DoubleHashingHashTable
      : public HashTableOpenAddressingBase<K,V,Hash,KeyEqual>
    {
    public:
        using Base = HashTableOpenAddressingBase<K,V,Hash,KeyEqual>;
        using Base::Base;

    protected:
        /**
         * @brief Computes the next probe index using a second hash function.
         * @return `(h1(key) + attempt * h2(key)) % capacity`
         */
        size_t probeIndex(const K& key, size_t attempt) const override {
            size_t cap = this->table_.size();
            size_t h1  = this->hasher_(key) % cap;
            size_t h2  = secondaryHash(this->hasher_(key) >> 5, cap);
            return (h1 + attempt * h2) % cap;
        }
    };
} // namespace dsa
