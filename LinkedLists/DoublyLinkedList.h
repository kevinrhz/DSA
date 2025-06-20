#pragma once

namespace dsa {
    /**
     * @brief A node for a doubly linked list.
     * @tparam T The type of data stored in the node.
     */
    template<typename T>
    class DoublyNode {
    public:
        T data;
        DoublyNode* prev;
        DoublyNode* next;

        /**
         * @brief Constructs a new DoublyNode.
         * @param d The data to store in the node.
         */
        explicit DoublyNode(const T& d);
    };

    /**
     * @brief A doubly linked list implementation.
     *
     * This list uses dummy head and tail nodes (sentinels) to simplify
     * insertion and deletion logic by removing the need for null checks
     * at the list's boundaries.
     * @tparam T The type of element stored in the list.
     */
    template<typename T>
    class DoublyLinkedList {
    private:
        DoublyNode<T>* head;        // Points to the actual first element.
        DoublyNode<T>* tail;        // Points to the actual last element.
        DoublyNode<T>* dummyHead;   // Sentinel node at the beginning.
        DoublyNode<T>* dummyTail;   // Sentinel node at the end.

    public:
        using NodePtr = DoublyNode<T>*;

        // Constructor & Destructor
        DoublyLinkedList();
        ~DoublyLinkedList();

        // Core Operations
        /// @brief Appends an element to the end of the list. O(1).
        void append(const T& d);
        /// @brief Prepends an element to the beginning of the list. O(1).
        void prepend(const T& d);
        /// @brief Prints the list contents to standard output. For debugging. O(n).
        void printList() const;

        // Accessors
        /// @brief Returns the data of the first element. O(1).
        /// @throws std::runtime_error if the list is empty.
        T front() const;
        /// @brief Returns the data of the last element. O(1).
        /// @throws std::runtime_error if the list is empty.
        T back() const;
        /// @brief Checks if the list is empty. O(1).
        bool isEmpty() const;
        /// @brief Returns the number of elements in the list. O(n).
        int size() const;
        /// @brief Returns a pointer to the first node. O(1).
        NodePtr getHead() const;
        /// @brief Returns a pointer to the last node. O(1).
        NodePtr getTail() const;

        // Search
        /// @brief Checks if the list contains a given element. O(n).
        bool contains(const T& d) const;
        /// @brief Finds the first node containing the given data. O(n).
        /// @return NodePtr to the found node, or nullptr if not found.
        NodePtr find(const T& d) const;

        // Modifiers
        /// @brief Removes the first occurrence of an element. O(n).
        void remove(const T& d);
        /// @brief Inserts an element after a specified node. O(1).
        /// @param target A pointer to the node after which to insert.
        void insertAfter(NodePtr target, const T& d);
        /// @brief Removes the element after a specified node. O(1).
        /// @param target A pointer to the node whose successor will be removed.
        void removeAfter(NodePtr target);
        /// @brief Removes all elements from the list. O(n).
        void clear();
        /// @brief Reverses the list in-place. O(n).
        void reverse();
    };
}

#include "DoublyLinkedList.tpp"
