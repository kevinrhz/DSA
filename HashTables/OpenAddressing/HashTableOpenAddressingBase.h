#pragma once
#include <cstddef>
#include <vector>
#include <stdexcept>
#include <functional>
#include "../Chaining/IHashTable.h"  // your existing interface
#include "../Hash.h"

namespace dsa {

//------------------------------------------------------------------------------
// Base class for all open-addressing tables
//------------------------------------------------------------------------------
template<
    typename K,
    typename V,
    typename Hash     = Hash<K>,
    typename KeyEqual = std::equal_to<K>
>
class HashTableOpenAddressingBase : public IHashTable<K,V,Hash,KeyEqual> {
protected:
    enum class State { Empty, Occupied, Tombstone };
    struct Bucket {
        K       key;
        V       value;
        State   state = State::Empty;
    };

    std::vector<Bucket> table_;
    size_t              elementCount_ = 0;
    float               maxLoadFactor_;
    Hash                hasher_;
    KeyEqual            keyEqual_;

public:
    /**
     * @param capacity        starting # of slots
     * @param maxLoadFactor   when (size_/capacity) > this, we rehash
     */
    explicit
    HashTableOpenAddressingBase(size_t capacity = 16,
                                float  maxLoadFactor = 0.5f);

    bool   insert(const K& key, const V& value) override;
    bool   remove(const K& key)                 override;
    V*     find(const K& key)                   override;
    size_t size() const                         override;
    void   clear()                              override;

protected:
    /**
     * @brief Given a key and attempt count, return the next index.
     * @param key     the lookup key
     * @param attempt which probe (0,1,2,...)
     */
    virtual size_t probeIndex(const K& key, size_t attempt) const = 0;

    /** @brief Expand & re-insert all Occupied entries into a bigger table. */
    void rehash(size_t newCapacity);

    /** @brief Compute next capacity (e.g. double current size) */
    size_t nextCapacity() const;
};

} // namespace dsa
