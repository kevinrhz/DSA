#include "DoublyLinkedList.h"
#include <iostream>

namespace dsa {
    template<typename T>
    DoublyNode<T>::DoublyNode(const T& d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }

    // Constructor + Destructor
    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList() {
        dummyHead = new DoublyNode<T>(T());
        dummyTail = new DoublyNode<T>(T());
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
        head = nullptr;
        tail = nullptr;
    }

    template<typename T>
    DoublyLinkedList<T>::~DoublyLinkedList() {
        DoublyNode<T>* curNode = dummyHead;
        while (curNode != nullptr) {
            DoublyNode<T>* nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
    }

    // Core operations
    template<typename T>
    void DoublyLinkedList<T>::append(const T& d) {
        DoublyNode<T>* newNode = new DoublyNode<T>(d);
        if (!head) {
            dummyHead->next = newNode;
            newNode->prev = dummyHead;
            newNode->next = dummyTail;
            dummyTail->prev = newNode;
            head = tail = newNode;
        } else {
            DoublyNode<T>* prevNode = dummyTail->prev;
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = dummyTail;
            dummyTail->prev = newNode;
            tail = newNode;
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::prepend(const T& d) {
        DoublyNode<T>* newNode = new DoublyNode<T>(d);
        DoublyNode<T>* nextNode = dummyHead->next;

        dummyHead->next = newNode;
        newNode->prev = dummyHead;
        newNode->next = nextNode;
        nextNode->prev = newNode;
        head = newNode;

        if (!tail) {
            tail = newNode;
        }
    }

    template<typename T>
    void DoublyLinkedList<T>::printList() const {
        DoublyNode<T>* curNode = dummyHead->next;
        while (curNode != dummyTail) {
            std::cout << curNode->data << " <-> ";
            curNode = curNode->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Accessors
    template<typename T>
    T DoublyLinkedList<T>::front() const {
        if (dummyHead->next == dummyTail) return T();
        return dummyHead->next->data;
    }

    template<typename T>
    T DoublyLinkedList<T>::back() const {
        if (dummyTail->prev == dummyHead) return T();
        return dummyTail->prev->data;
    }

    template<typename T>
    bool DoublyLinkedList<T>::isEmpty() const {
        return dummyHead->next == dummyTail;
    }

    template<typename T>
    int DoublyLinkedList<T>::size() const {
        int count = 0;
        DoublyNode<T>* curNode = dummyHead->next;
        while (curNode != dummyTail) {
            count++;
            curNode = curNode->next;
        }
        return count;
    }

    template<typename T>
    DoublyNode<T>* DoublyLinkedList<T>::getHead() const {
        return (dummyHead->next == dummyTail) ? nullptr : dummyHead->next;
    }

    template<typename T>
    DoublyNode<T>* DoublyLinkedList<T>::getTail() const {
        return (dummyTail->prev == dummyHead) ? nullptr : dummyTail->prev;
    }

    // Search + Find
    template<typename T>
    bool DoublyLinkedList<T>::contains(const T& d) const {
        DoublyNode<T>* curNode = dummyHead->next;
        while (curNode != dummyTail) {
            if (curNode->data == d) return true;
            curNode = curNode->next;
        }
        return false;
    }

    template<typename T>
    DoublyNode<T>* DoublyLinkedList<T>::find(const T& d) const {
        DoublyNode<T>* curNode = dummyHead->next;
        while (curNode != dummyTail) {
            if (curNode->data == d) return curNode;
            curNode = curNode->next;
        }
        return nullptr;
    }

    // Modifiers
    template<typename T>
    void DoublyLinkedList<T>::remove(const T& d) {
        DoublyNode<T>* curNode = dummyHead->next;
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

    template<typename T>
    void DoublyLinkedList<T>::insertAfter(DoublyNode<T> *target, const T& d) {
        if (!target) return;
        DoublyNode<T>* newNode = new DoublyNode<T>(d);
        newNode->next = target->next;
        newNode->prev = target;
        target->next->prev = newNode;
        target->next = newNode;
    }

    template<typename T>
    void DoublyLinkedList<T>::removeAfter(DoublyNode<T> *target) {
        if (!target || target->next == dummyTail) return;
        DoublyNode<T>* tempNode = target->next;
        target->next = tempNode->next;
        tempNode->next->prev = target;
        delete tempNode;
    }

    template<typename T>
    void DoublyLinkedList<T>::clear() {
        DoublyNode<T>* curNode = dummyHead->next;
        while (curNode != dummyTail) {
            DoublyNode<T>* nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    template<typename T>
    void DoublyLinkedList<T>::reverse() {
        for (DoublyNode<T>* curNode = dummyHead; curNode != nullptr;) {
            DoublyNode<T>* nextNode = curNode->next;
            curNode->next = curNode->prev;
            curNode->prev = nextNode;
            curNode = nextNode;
        }
        DoublyNode<T>* tempNode = dummyHead;
        dummyHead = dummyTail;
        dummyTail = tempNode;
    }
}