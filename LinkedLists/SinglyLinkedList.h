#pragma once

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

class Node {
public:
    int data;
    Node* next;

    Node(int d);
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
    Node* dummy;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    // Core operations
    void append(int d);
	void prepend(int d);
	void printList() const;

    // Accessors
    int front() const;
    int back() const;
    bool isEmpty() const;
    int size() const;
    Node* getHead() const;
    Node* getTail() const;

    // Search + Find
    bool contains(int d) const;
    Node* find(int d) const;

    // Modifiers
    void remove(int d);
    void insertAfter(Node* target, int d);
    void removeAfter(Node* target);
    void clear();
    void reverse();
};

#endif // SINGLY_LINKED_LIST_H
