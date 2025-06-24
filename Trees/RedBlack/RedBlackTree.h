#pragma once
#include <cstddef>

namespace dsa {
    /**
     * @brief Represents the color of a node in a Red-Black Tree.
     */
    enum class Color { RED, BLACK };

    /**
     * @brief A self-balancing binary search tree using the Red-Black Tree algorithm.
     *
     * This implementation uses a single, shared sentinel node (`nil_`) to represent all
     * leaves, which simplifies the logic for handling boundary conditions. The sentinel
     * is always black. This design guarantees O(log n) time complexity for search,
     * insertion, and deletion operations.
     *
     * @tparam T The type of data to be stored. Must be comparable.
     */
    template<typename T>
    class RedBlackTree {
    public:
        /// @brief Constructs an empty Red-Black Tree.
        RedBlackTree();
        /// @brief Destructor, cleans up all nodes.
        ~RedBlackTree();

        /**
         * @brief Inserts a value, maintaining Red-Black properties. O(log n).
         * @param value The value to insert.
         */
        void insert(const T& value);

        /**
         * @brief Removes a value, maintaining Red-Black properties. O(log n).
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
         * @brief Returns the total number of elements in the tree. O(1).
         * @return The number of internal nodes.
         */
        std::size_t size() const;

        /**
         * @brief Returns the height of the tree. O(n).
         * The height of an empty tree is -1.
         * @return The number of edges on the longest path from the root to a leaf.
         */
        int height() const;

        /**
         * @brief Checks if the tree is empty. O(1).
         * @return true if the tree has no elements, false otherwise.
         */
        bool isEmpty() const;

        /**
         * @brief Removes all elements from the tree. O(n).
         */
        void clear();

        /**
         * @brief Validates the tree against all Red-Black properties. For debugging. O(n).
         * @return true if the tree is a valid Red-Black tree, false otherwise.
         */
        bool validate() const;

    private:
        /**
         * @brief Represents a node in the Red-Black Tree.
         */
        struct Node {
            T      data;
            Color  color;
            Node* left;
            Node* right;
            Node* parent;

            /**
             * @brief Constructs a new Node.
             * @param v The data value.
             * @param c The node's color.
             * @param nil A pointer to the sentinel nil node.
             */
            Node(const T& v, Color c, Node* nil)
                : data(v), color(c), left(nil), right(nil), parent(nil) {}
        };

        Node* nil_;    // A single, shared sentinel node for all leaves. It is always BLACK.
        Node* root_;   // The root of the tree. Points to nil_ if the tree is empty.
        std::size_t  size_;   // The current number of internal nodes in the tree.

        // --- Core Algorithm Helpers ---
        /// @brief Performs a left rotation on the subtree rooted at x.
        void    leftRotate(Node* x);
        /// @brief Performs a right rotation on the subtree rooted at x.
        void    rightRotate(Node* x);
        /// @brief Restores Red-Black properties after an insertion.
        void    insertFixup(Node* z);
        /// @brief Restores Red-Black properties after a deletion.
        void    removeFixup(Node* x);

        // --- Deletion and Search Helpers ---
        /**
         * @brief Replaces the subtree rooted at 'u' with the subtree rooted at 'v'.
         * @param u The node to be replaced.
         * @param v The node to replace with.
         */
        void    transplant(Node* u, Node* v);
        /// @brief Finds the node with the minimum value in a subtree.
        Node* treeMinimum(Node* x) const;
        /// @brief Finds the node containing a specific value.
        Node* findNode(const T& value) const;


        // --- Utility Helpers ---
        /// @brief Recursive helper to clear all nodes.
        void    clearHelper(Node* x);
        /// @brief Recursive helper to calculate the height of a subtree.
        int     heightHelper(Node* x) const;
        /// @brief Recursive helper to validate Red-Black properties.
        bool    validateHelper(Node* x, int blackCount, int& expected) const;
    };

} // namespace dsa

#include "RedBlackTree.tpp"