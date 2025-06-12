#pragma once

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

namespace dsa {
    template<typename T>
    class Node {
    public:
        T data;
        Node<T>* next;

        Node(const T& d);
    };

    template<typename T>
    class SinglyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* dummy;

    public:
        using NodePtr = Node<T>*;

        SinglyLinkedList();
        ~SinglyLinkedList();

        // Core operations
        void append(const T& d);
        void prepend(const T& d);
        void printList() const;

        // Accessors
        T front() const;
        T back() const;
        bool isEmpty() const;
        int size() const;
        Node<T>* getHead() const;
        Node<T>* getTail() const;

        // Search + Find
        bool contains(const T& d) const;
        Node<T>* find(const T& d) const;

        // Modifiers
        void remove(const T& d);
        void insertAfter(Node<T>* target, const T& d);
        void removeAfter(Node<T>* target);
        void clear();
        void reverse();
    };
}

#include "SinglyLinkedList.tpp"

#endif // SINGLY_LINKED_LIST_H
