#pragma once

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyNode {
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(int d);
};

class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;
    DoublyNode* dummyHead;
    DoublyNode* dummyTail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Core operations
    void append(int d);
    void prepend(int d);
    void printList() const;

    // Accessors
    int front() const;
    int back() const;
    bool isEmpty() const;
    int size() const;
    DoublyNode* getHead() const;
    DoublyNode* getTail() const;

    // Search + Find
    bool contains(int d) const;
    DoublyNode* find(int d) const;

    // Modifiers
    void remove(int d);
    void insertAfter(DoublyNode* target, int d);
    void removeAfter(DoublyNode* target);
    void clear();
    void reverse();
};

#endif //DOUBLYLINKEDLIST_H
