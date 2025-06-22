#pragma once
#include <array>
#include <memory>
#include <string>

namespace dsa {
    /**
     * @brief A Trie (Prefix Tree) for efficient string storage and retrieval.
     *
     * This implementation is optimized for lowercase English alphabet strings ('a'-'z').
     * It supports efficient insertion, search, and prefix-based searching with time
     * complexity proportional to the length of the string, not the number of strings
     * stored. It uses std::unique_ptr for automatic memory management of its nodes.
     */
    class Trie {
    public:
        /**
         * @brief Constructs an empty Trie with a root node.
         */
        Trie();

        /**
         * @brief Inserts a word into the Trie. O(L) where L is the word length.
         * @param word The string to insert.
         */
        void insert(const std::string& word);

        /**
         * @brief Searches for a complete word in the Trie. O(L).
         * @param word The word to search for.
         * @return true if the word exists as a complete entry, false otherwise.
         */
        bool search(const std::string& word) const;

        /**
         * @brief Checks if there is any word in the Trie that starts with the given prefix. O(L).
         * @param prefix The prefix to check.
         * @return true if there is at least one word with the prefix, false otherwise.
         */
        bool startsWith(const std::string& prefix) const;

        /**
         * @brief Removes a word from the Trie. O(L).
         * If the word is a prefix of other words, only its 'isWord' flag is unset.
         * If the word is not a prefix, its unused nodes are pruned from the tree.
         * @param word The word to remove.
         * @return true if the word was found and removed, false otherwise.
         */
        bool remove(const std::string& word);

    private:
        /**
         * @brief Represents a single node in the Trie.
         */
        struct Node {
            std::array<std::unique_ptr<Node>, 26> children{};
            bool isWord = false;
        };

        // The root of the Trie. It is an empty node.
        std::unique_ptr<Node> root_;

        /**
         * @brief Finds the node corresponding to the end of a prefix.
         * @param prefix The prefix to search for.
         * @return A pointer to the node, or nullptr if the prefix does not exist.
         */
        Node* findNode(const std::string& prefix) const;

        /**
         * @brief A recursive helper to remove a word and prune unused nodes.
         * @param node The current node in the recursion.
         * @param word The word being removed.
         * @param depth The current character depth in the word.
         * @return true if the current node can be safely deleted.
         */
        bool  removeHelper(Node* node, const std::string& word, int depth);
    };
} // namespace dsa