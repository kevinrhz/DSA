#pragma once

namespace dsa {
    template<typename T>
    class DoublyNode {
    public:
        T data;
        DoublyNode* prev;
        DoublyNode* next;

        explicit DoublyNode(const T& d);
    };

    template<typename T>
    class DoublyLinkedList {
    private:
        DoublyNode<T>* head;
        DoublyNode<T>* tail;
        DoublyNode<T>* dummyHead;
        DoublyNode<T>* dummyTail;

    public:
        using NodePtr = DoublyNode<T>*;

        // Constructor & Destructor
        DoublyLinkedList();
        ~DoublyLinkedList();

        // Core Operations
        void append(const T& d);
        void prepend(const T& d);
        void printList() const;

        // Accessors
        T front() const;
        T back() const;
        bool isEmpty() const;
        int size() const;
        NodePtr getHead() const;
        NodePtr getTail() const;

        // Search
        bool contains(const T& d) const;
        NodePtr find(const T& d) const;

        // Modifiers
        void remove(const T& d);
        void insertAfter(NodePtr target, const T& d);
        void removeAfter(NodePtr target);
        void clear();
        void reverse();
    };
}

#include "DoublyLinkedList.tpp"
