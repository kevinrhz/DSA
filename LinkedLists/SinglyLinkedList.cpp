#include "SinglyLinkedList.h"
#include <iostream>

Node::Node(int d) {
    data = d;
    next = nullptr;
}

// Constructor + Destructor
SinglyLinkedList::SinglyLinkedList() {
    dummy = new Node(0);
    head = tail = nullptr;
}

SinglyLinkedList::~SinglyLinkedList() {
    Node* curNode = dummy;
    while (curNode != nullptr) {
        Node* nextNode = curNode->next;
        delete curNode;
        curNode = nextNode;
    }
}

// Core operations
void SinglyLinkedList::append(int d) {
    Node* newNode = new Node(d);
    if (!head) {
        dummy->next = newNode;
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void SinglyLinkedList::prepend(int d) {
    Node* newNode = new Node(d);
    newNode->next = dummy->next;
    dummy->next = newNode;
    if (!head) {
        head = tail = newNode;
    } else {
        head = newNode;
    }
}

void SinglyLinkedList::printList() const {
    Node* curNode = dummy->next;
    while(curNode != nullptr) {
        std::cout << curNode->data << " -> ";
        curNode = curNode->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Accessors
int SinglyLinkedList::front() const {
    return dummy->next ? dummy->next->data : -1;
}

int SinglyLinkedList::back() const {
    return tail ? tail->data : -1;
}

bool SinglyLinkedList::isEmpty() const {
    return dummy->next == nullptr;
}

int SinglyLinkedList::size() const {
    int count = 0;
    Node* curNode = dummy->next;
    while (curNode != nullptr) {
        count++;
        curNode = curNode->next;
    }
    return count;
}

Node* SinglyLinkedList::getHead() const {
    return dummy->next;
}

Node* SinglyLinkedList::getTail() const {
    return tail;
}

// Search + Find
bool SinglyLinkedList::contains(int d) const {
    Node* curNode = dummy->next;
    while (curNode != nullptr) {
        if (curNode->data == d) return true;
        curNode = curNode->next;
    }
    return false;
}

Node* SinglyLinkedList::find(int d) const {
    Node* curNode = dummy->next;
    while (curNode != nullptr) {
        if (curNode->data == d) return curNode;
        curNode = curNode->next;
    }
    return nullptr;
}

// Modifiers
void SinglyLinkedList::remove(int d) {
    Node* curNode = dummy->next;
    Node* prevNode = dummy;

    while (curNode != nullptr) {
        if (curNode->data == d) {
            prevNode->next = curNode->next;
            delete curNode;
            return;
        }
        prevNode = curNode;
        curNode = curNode->next;
    }
}

void SinglyLinkedList::insertAfter(Node *target, int d) {
    if (!target) return;

    Node* newNode = new Node(d);
    newNode->next = target->next;
    target->next = newNode;

    if (target == tail) {
        tail = newNode;
    }
}

void SinglyLinkedList::removeAfter(Node *target) {
    if (!target || !target->next) return;

    Node* tempNode = target->next;
    target->next = tempNode->next;

    if (target == tail) {
        tail = target;
    }
    delete tempNode;
}

void SinglyLinkedList::clear() {
    Node* curNode = dummy->next;
    while (curNode != nullptr) {
        Node* nextNode = curNode->next;
        delete curNode;
        curNode = nextNode;
    }
    dummy->next = nullptr;
    tail = dummy;
}

void SinglyLinkedList::reverse() {
    Node* prevNode = nullptr;
    Node* curNode = dummy->next;
    Node* nextNode = nullptr;
    tail = curNode;

    while (curNode!= nullptr) {
        nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
    }
    dummy->next = prevNode;
}