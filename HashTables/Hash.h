#pragma once
#include <string>

namespace dsa {
    /**
     * @brief A basic hash functor.
     *
     * This template provides a default hash implementation that will cause a
     * compile-time error if no specialization is available for the given key type.
     * This forces the user to provide a valid hash function for their custom types.
     *
     * @tparam K The key type to hash.
     */
    template<typename K>
    struct Hash {
        size_t operator()(const K& key) const {
            // This static_assert provides a clear error message at compile time
            // if a Hash specialization for type K has not been defined.
            static_assert(sizeof(K) == 0, "No hash function defined for this key type.");
            return 0; // Unreachable code
        }
    };

    /**
     * @brief Hash functor specialization for integers.
     */
    template<>
    struct Hash<int> {
        size_t operator()(int key) const {
            // A simple identity hash for integer types.
            return static_cast<size_t>(key);
        }
    };

    /**
     * @brief Hash functor specialization for std::string.
     */
    template<>
    struct Hash<std::string> {
        size_t operator()(const std::string& key) const {
            // A classic polynomial rolling hash function (djb2-like).
            size_t hash = 0;
            for (char c : key)
                // Use 31, a common prime number, for string hashing.
                hash = hash * 31 + static_cast<unsigned char>(c);
            return hash;
        }
    };


} // namespace dsa