#pragma once
#include <memory>
#include <functional>
#include <cstddef>

namespace dsa {

    /**
     * @brief A simple Binary Search Tree storing key-value pairs.
     *
     * @tparam K Key type (must be comparable with <)
     * @tparam V Value type
     */
    template<typename K, typename V>
    class BinarySearchTree {
    private:
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

        // Disable copy to avoid deep tree copy complexities
        BinarySearchTree(const BinarySearchTree&) = delete;
        BinarySearchTree& operator=(const BinarySearchTree&) = delete;

        // Allow move
        BinarySearchTree(BinarySearchTree&&) noexcept = default;
        BinarySearchTree& operator=(BinarySearchTree&&) noexcept = default;

        std::vector<std::pair<K, V>> inOrderTraversal() const;
        bool     insert(const K& key, const V& value);
        bool     remove(const K& key);
        V*       find(const K& key);
        const V* find(const K& key) const;
        V*       findMin();
        const V* findMin() const;
        V*       findMax();
        const V* findMax() const;


        void     clear();
        int      height() const;
        size_t   size()  const { return size_; }
        bool     empty() const { return size_ == 0; }

    private:
        bool     insertHelper(std::unique_ptr<Node>& node, const K& key, const V& value);
        bool     removeHelper(std::unique_ptr<Node>& node, const K& key);
        V*       findHelper(const std::unique_ptr<Node>& node, const K& key);
        const V* findHelper(const std::unique_ptr<Node>& node, const K& key) const;
        int      heightHelper(const std::unique_ptr<Node>& node) const;
        void     inOrderHelper(const std::unique_ptr<Node>& node, std::vector<std::pair<K, V>>& result) const;

    };

} // namespace dsa

#include "BinarySearchTree.tpp"