#pragma once
#include <memory>
#include <functional>
#include <cstddef>

namespace dsa {
    /**
     * @brief A Binary Search Tree (BST) storing key-value pairs.
     *
     * This implementation uses std::unique_ptr for automatic and exception-safe
     * memory management of its nodes. The BST maintains the property that for any
     * given node, all keys in its left subtree are smaller, and all keys in its
     * right subtree are larger.
     *
     * Average-case time complexity for search, insertion, and deletion is O(log n).
     * Worst-case (unbalanced tree) is O(n).
     *
     * @tparam K Key type (must be comparable with <).
     * @tparam V Value type.
     */
    template<typename K, typename V>
    class BinarySearchTree {
    private:
        /**
         * @brief Represents a node in the BST.
         */
        struct Node {
            K key;
            V value;
            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;

            Node(const K& k, const V& v) : key(k), value(v), left(nullptr), right(nullptr) {}
        };

        std::unique_ptr<Node> root_;
        size_t size_ = 0;

    public:
        BinarySearchTree() = default;
        ~BinarySearchTree() = default;

        // --- Rule of Five ---
        // Disable copy semantics to avoid complex deep copies.
        BinarySearchTree(const BinarySearchTree&) = delete;
        BinarySearchTree& operator=(const BinarySearchTree&) = delete;

        // Enable move semantics for efficient transfers of ownership.
        BinarySearchTree(BinarySearchTree&&) noexcept = default;
        BinarySearchTree& operator=(BinarySearchTree&&) noexcept = default;


        // --- Traversals ---
        /// @brief Performs an in-order traversal of the tree.
        /// @return A std::vector of key-value pairs, sorted by key.
        std::vector<std::pair<K, V>> inOrderTraversal() const;


        // --- Modifiers ---
        /// @brief Inserts a key-value pair. Average O(log n), Worst O(n).
        /// @return true if insertion took place, false if key already existed.
        bool     insert(const K& key, const V& value);
        /// @brief Removes a node by its key. Average O(log n), Worst O(n).
        /// @return true if the key was found and removed, false otherwise.
        bool     remove(const K& key);
        /// @brief Removes all nodes from the tree. O(n).
        void     clear();


        // --- Search & Lookup ---
        /// @brief Finds a value by its key. Average O(log n), Worst O(n).
        /// @return A pointer to the value, or nullptr if not found.
        V*       find(const K& key);
        /// @brief Finds a value by its key (const version).
        const V* find(const K& key) const;

        /// @brief Finds the value with the minimum key. Average O(log n), Worst O(n).
        V*       findMin();
        /// @brief Finds the value with the minimum key (const version).
        const V* findMin() const;

        /// @brief Finds the value with the maximum key. Average O(log n), Worst O(n).
        V*       findMax();
        /// @brief Finds the value with the maximum key (const version).
        const V* findMax() const;


        // --- State & Capacity ---
        /// @brief Returns the height of the tree. O(n).
        /// Height of an empty tree is -1, a tree with one node is 0.
        int      height() const;
        /// @brief Returns the number of nodes in the tree. O(1).
        size_t   size()  const { return size_; }
        /// @brief Checks if the tree is empty. O(1).
        bool     empty() const { return size_ == 0; }

    private:
        // --- Recursive Helpers ---
        bool     insertHelper(std::unique_ptr<Node>& node, const K& key, const V& value);
        bool     removeHelper(std::unique_ptr<Node>& node, const K& key);
        V*       findHelper(const std::unique_ptr<Node>& node, const K& key);
        const V* findHelper(const std::unique_ptr<Node>& node, const K& key) const;
        int      heightHelper(const std::unique_ptr<Node>& node) const;
        void     inOrderHelper(const std::unique_ptr<Node>& node, std::vector<std::pair<K, V>>& result) const;
    };
} // namespace dsa

#include "BinarySearchTree.tpp"