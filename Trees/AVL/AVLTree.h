#pragma once
#include <memory>
#include <algorithm>

namespace dsa {
    /**
     * @brief A self-balancing binary search tree using the AVL algorithm.
     *
     * An AVL Tree maintains a balanced state by ensuring that the heights of the two
     * child subtrees of any node differ by at most one. This guarantees a worst-case
     * time complexity of O(log n) for search, insertion, and deletion operations.
     * This implementation uses std::unique_ptr for automatic memory management.
     *
     * @tparam T The type of data to be stored. Must be comparable.
     */
    template<typename T>
    class AVLTree {
    public:
        /// @brief Default constructor. Creates an empty AVL tree.
        AVLTree();
        /// @brief Destructor. Cleans up all nodes automatically via std::unique_ptr.
        ~AVLTree();

        /**
         * @brief Inserts a value into the tree and performs rotations to maintain balance. O(log n).
         * @param value The value to insert.
         */
        void insert(const T& value);

        /**
         * @brief Removes a value from the tree and performs rotations to maintain balance. O(log n).
         * @param value The value to remove.
         */
        void remove(const T& value);

        /**
         * @brief Checks if a value exists in the tree. O(log n).
         * @param value The value to search for.
         * @return true if the value is found, false otherwise.
         */
        bool contains(const T& value) const;

        /**
         * @brief Returns the height of the tree.
         * An empty tree has a height of 0, a tree with one node has a height of 1.
         * @return The height of the root node.
         */
        int height() const;

    private:
        /**
         * @brief Represents a node in the AVL tree.
         */
        struct Node {
            T data;
            int height; // Height of the subtree rooted at this node
            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;
            explicit Node(const T& val) : data(val), height(1), left(nullptr), right(nullptr) {}
        };

        // The root of the tree.
        std::unique_ptr<Node> root_;

        // --- Recursive Helpers ---
        std::unique_ptr<Node> insertNode(std::unique_ptr<Node> node, const T& value);
        std::unique_ptr<Node> removeNode(std::unique_ptr<Node> node, const T& value);
        bool containsNode(const Node* node, const T& value) const;

        // --- AVL Utilities ---
        /// @brief Returns the height of a node, handling nullptr cases.
        int getHeight(const Node* node) const;
        /// @brief Calculates the balance factor of a node (height(left) - height(right)).
        int getBalance(const Node* node) const;
        /// @brief Recalculates and updates a node's height based on its children's heights.
        void updateHeight(Node* node);
        /// @brief Finds the node with the minimum value in a subtree.
        Node* findMin(Node* node) const;

        // --- Rotation Operations ---
        /// @brief Performs a left rotation on the subtree rooted at x.
        std::unique_ptr<Node> rotateLeft(std::unique_ptr<Node> x);
        /// @brief Performs a right rotation on the subtree rooted at y.
        std::unique_ptr<Node> rotateRight(std::unique_ptr<Node> y);
        /// @brief Balances a node by performing necessary rotations based on its balance factor.
        std::unique_ptr<Node> balanceNode(std::unique_ptr<Node> node);
    };

} // namespace dsa

#include "AVLTree.tpp"