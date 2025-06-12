#pragma once

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

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
        DoublyNode<T>* getHead() const;
        DoublyNode<T>* getTail() const;

        // Search
        bool contains(const T& d) const;
        DoublyNode<T>* find(const T& d) const;

        // Modifiers
        void remove(const T& d);
        void insertAfter(DoublyNode<T>* target, const T& d);
        void removeAfter(DoublyNode<T>* target);
        void clear();
        void reverse();
    };
}

#include "DoublyLinkedList.tpp"

#endif //DOUBLYLINKEDLIST_H
