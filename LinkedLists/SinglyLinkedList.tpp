#include <iostream>

namespace dsa {
    template<typename T>
    Node<T>::Node(const T& d) {
        data = d;
        next = nullptr;
    }

    template<typename T>
    SinglyLinkedList<T>::SinglyLinkedList() {
        dummy = new Node<T>(0);
        head = tail = nullptr;
    }

    template<typename T>
    SinglyLinkedList<T>::~SinglyLinkedList() {
        Node<T>* curNode = dummy;
        while (curNode != nullptr) {
            Node<T>* nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
    }

    template<typename T>
    void SinglyLinkedList<T>::append(const T& d) {
        Node<T>* newNode = new Node<T>(d);
        if (!head) {
            dummy->next = newNode;
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    template<typename T>
    void SinglyLinkedList<T>::prepend(const T& d) {
        Node<T>* newNode = new Node<T>(d);
        newNode->next = dummy->next;
        dummy->next = newNode;
        if (!head) {
            head = tail = newNode;
        } else {
            head = newNode;
        }
    }

    template<typename T>
    void SinglyLinkedList<T>::printList() const {
        Node<T>* curNode = dummy->next;
        while(curNode != nullptr) {
            std::cout << curNode->data << " -> ";
            curNode = curNode->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    template<typename T>
    T SinglyLinkedList<T>::front() const {
        if (isEmpty()) throw std::runtime_error("List is empty. No front element.");
        return dummy->next->data;
    }

    template<typename T>
    T SinglyLinkedList<T>::back() const {
        if (isEmpty()) throw std::runtime_error("List is empty. No back element.");
        return tail->data;
    }

    template<typename T>
    bool SinglyLinkedList<T>::isEmpty() const {
        return dummy->next == nullptr;
    }

    template<typename T>
    int SinglyLinkedList<T>::size() const {
        int count = 0;
        Node<T>* curNode = dummy->next;
        while (curNode != nullptr) {
            count++;
            curNode = curNode->next;
        }
        return count;
    }

    template<typename T>
    Node<T>* SinglyLinkedList<T>::getHead() const {
        return dummy->next;
    }

    template<typename T>
    Node<T>* SinglyLinkedList<T>::getTail() const {
        return tail;
    }

    template<typename T>
    bool SinglyLinkedList<T>::contains(const T& d) const {
        Node<T>* curNode = dummy->next;
        while (curNode != nullptr) {
            if (curNode->data == d) return true;
            curNode = curNode->next;
        }
        return false;
    }

    template<typename T>
    Node<T>* SinglyLinkedList<T>::find(const T& d) const {
        Node<T>* curNode = dummy->next;
        while (curNode != nullptr) {
            if (curNode->data == d) return curNode;
            curNode = curNode->next;
        }
        return nullptr;
    }

    template<typename T>
    void SinglyLinkedList<T>::remove(const T& d) {
        Node<T>* curNode = dummy->next;
        Node<T>* prevNode = dummy;

        while (curNode != nullptr) {
            if (curNode->data == d) {
                prevNode->next = curNode->next;
                delete curNode;
                return;
            }
            prevNode = curNode;
            curNode = curNode->next;
        }
        throw std::runtime_error("Element not found. Cannot remove.");
    }

    template<typename T>
    void SinglyLinkedList<T>::insertAfter(Node<T>* target, const T& d) {
        if (!target) throw std::invalid_argument("Target node is null.");

        Node<T>* newNode = new Node<T>(d);
        newNode->next = target->next;
        target->next = newNode;

        if (target == tail) {
            tail = newNode;
        }
    }

    template<typename T>
    void SinglyLinkedList<T>::removeAfter(Node<T>* target) {
        if (!target || !target->next) throw std::invalid_argument("Invalid target node.");

        Node<T>* tempNode = target->next;
        target->next = tempNode->next;

        if (target == tail) {
            tail = target;
        }
        delete tempNode;
    }

    template<typename T>
    void SinglyLinkedList<T>::clear() {
        Node<T>* curNode = dummy->next;
        while (curNode != nullptr) {
            Node<T>* nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
        dummy->next = nullptr;
        tail = dummy;
    }

    template<typename T>
    void SinglyLinkedList<T>::reverse() {
        Node<T>* prevNode = nullptr;
        Node<T>* curNode = dummy->next;
        Node<T>* nextNode = nullptr;
        tail = curNode;

        while (curNode!= nullptr) {
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        dummy->next = prevNode;
    }
}