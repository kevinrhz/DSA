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
        NodePtr getHead() const;
        NodePtr getTail() const;

        // Search + Find
        bool contains(const T& d) const;
        NodePtr find(const T& d) const;

        // Modifiers
        void remove(const T& d);
        void removeFront();
        void insertAfter(NodePtr target, const T& d);
        void removeAfter(NodePtr target);
        void clear();
        void reverse();
    };
}

#include "SinglyLinkedList.tpp"
#endif // SINGLY_LINKED_LIST_H
