#pragma once

#ifndef HASH_H
#define HASH_H

#include <string>

namespace dsa {
    // Base case (compile time error)
    template<typename K>
    struct Hash {
        size_t operator()(const K& key) const {
            static_assert(sizeof(K) == 0, "No hash function defined for this key type.");
        }
    };

    // Specialize for int
    template<>
    struct Hash<int> {
        size_t operator()(int key) const {
            return static_cast<size_t>(key);
        }
    };

    // Specialize for string
    template<>
    struct Hash<std::string> {
        size_t operator()(const std::string& key) const {
            size_t hash = 0;
            for (char c : key)
                hash = 31 * hash + c;
            return hash;
        }
    };


} // namespace dsa

#endif //HASH_H
