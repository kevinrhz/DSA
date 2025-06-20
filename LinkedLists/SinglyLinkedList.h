#pragma once

namespace dsa {
    /**
    * @brief A node for a singly linked list.
    * @tparam T The type of data stored in the node.
    */
    template<typename T>
    class Node {
    public:
        T data;
        Node<T>* next;

        /**
        * @brief Constructs a new Node.
        * @param d The data to store in the node.
        */
        Node(const T& d);
    };

    /**
     * @brief A singly linked list implementation.
     *
     * This list uses a dummy head node to simplify insertion and deletion logic,
     * especially for operations at the beginning of the list.
     * @tparam T The type of element stored in the list.
     */
    template<typename T>
    class SinglyLinkedList {
    private:
        Node<T>* head;   // Points to the actual first element, after the dummy node.
        Node<T>* tail;   // Points to the last element in the list.
        Node<T>* dummy;  // A sentinel node before the head to simplify edge cases.

    public:
        using NodePtr = Node<T>*;

        // Constructor & Destructor
        SinglyLinkedList();
        ~SinglyLinkedList();

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

        // Search + Find
        /// @brief Checks if the list contains a given element. O(n).
        bool contains(const T& d) const;
        /// @brief Finds the first node containing the given data. O(n).
        /// @return NodePtr to the found node, or nullptr if not found.
        NodePtr find(const T& d) const;

        // Modifiers
        /// @brief Removes the first occurrence of an element. O(n).
        void remove(const T& d);
        /// @brief Removes the element at the front of the list. O(1).
        void removeFront();
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

#include "SinglyLinkedList.tpp"
