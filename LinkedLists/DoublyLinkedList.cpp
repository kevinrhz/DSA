#include "DoublyLinkedList.h"
#include <iostream>

DoublyNode::DoublyNode(int d) {
    data = d;
    next = nullptr;
    prev = nullptr;
}

// Constructor + Destructor
DoublyLinkedList::DoublyLinkedList() {
    dummyHead = new DoublyNode(0);
    dummyTail = new DoublyNode(0);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    DoublyNode* curNode = dummyHead;
    while (curNode != nullptr) {
        DoublyNode* nextNode = curNode->next;
        delete curNode;
        curNode = nextNode;
    }
}

// Core operations
void DoublyLinkedList::append(int d) {
    DoublyNode* newNode = new DoublyNode(d);
    if (!head) {
        dummyHead->next = newNode;
        newNode->prev = dummyHead;
        newNode->next = dummyTail;
        dummyTail->prev = newNode;
        head = tail = newNode;
    } else {
        DoublyNode* prevNode = dummyTail->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = dummyTail;
        dummyTail->prev = newNode;
        tail = newNode;
    }
}

void DoublyLinkedList::prepend(int d) {
    DoublyNode* newNode = new DoublyNode(d);
    DoublyNode* nextNode = dummyHead->next;

    dummyHead->next = newNode;
    newNode->prev = dummyHead;
    newNode->next = nextNode;
    nextNode->prev = newNode;
    head = newNode;

    if (!tail) {
        tail = newNode;
    }
}

void DoublyLinkedList::printList() const {
    DoublyNode* curNode = dummyHead->next;
    while (curNode != dummyTail) {
        std::cout << curNode->data << " <-> ";
        curNode = curNode->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Accessors
int DoublyLinkedList::front() const {
    if (dummyHead->next == dummyTail) return -1;
    return dummyHead->next->data;
}

int DoublyLinkedList::back() const {
    if (dummyTail->prev == dummyHead) return -1;
    return dummyTail->prev->data;
}

bool DoublyLinkedList::isEmpty() const {
    return dummyHead->next == dummyTail;
}

int DoublyLinkedList::size() const {
    int count = 0;
    DoublyNode* curNode = dummyHead->next;
    while (curNode != dummyTail) {
        count++;
        curNode = curNode->next;
    }
    return count;
}

DoublyNode* DoublyLinkedList::getHead() const {
    return (dummyHead->next == dummyTail) ? nullptr : dummyHead->next;
}

DoublyNode* DoublyLinkedList::getTail() const {
    return (dummyTail->prev == dummyHead) ? nullptr : dummyTail->prev;
}

// Search + Find
bool DoublyLinkedList::contains(int d) const {
    DoublyNode* curNode = dummyHead->next;
    while (curNode != dummyTail) {
        if (curNode->data == d) return true;
        curNode = curNode->next;
    }
    return false;
}

DoublyNode* DoublyLinkedList::find(int d) const {
    DoublyNode* curNode = dummyHead->next;
    while (curNode != dummyTail) {
        if (curNode->data == d) return curNode;
        curNode = curNode->next;
    }
    return nullptr;
}

// Modifiers
void DoublyLinkedList::remove(int d) {
    DoublyNode* curNode = dummyHead->next;
    while (curNode != dummyTail) {
        if (curNode->data == d) {
            curNode->prev->next = curNode->next;
            curNode->next->prev = curNode->prev;
            delete curNode;
            return;
        }
        curNode = curNode->next;
    }
}

void DoublyLinkedList::insertAfter(DoublyNode *target, int d) {
    if (!target) return;
    DoublyNode* newNode = new DoublyNode(d);
    newNode->next = target->next;
    newNode->prev = target;
    target->next->prev = newNode;
    target->next = newNode;
}

void DoublyLinkedList::removeAfter(DoublyNode *target) {
    if (!target || target->next == dummyTail) return;
    DoublyNode* tempNode = target->next;
    target->next = tempNode->next;
    tempNode->next->prev = target;
    delete tempNode;
}

void DoublyLinkedList::clear() {
    DoublyNode* curNode = dummyHead->next;
    while (curNode != dummyTail) {
        DoublyNode* nextNode = curNode->next;
        delete curNode;
        curNode = nextNode;
    }
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

void DoublyLinkedList::reverse() {
    for (DoublyNode* curNode = dummyHead; curNode != nullptr;) {
        DoublyNode* nextNode = curNode->next;
        curNode->next = curNode->prev;
        curNode->prev = nextNode;
        curNode = nextNode;
    }
    DoublyNode* tempNode = dummyHead;
    dummyHead = dummyTail;
    dummyTail = tempNode;
}