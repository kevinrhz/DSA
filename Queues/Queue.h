#pragma once
#include "../LinkedLists/SinglyLinkedList.h"

namespace dsa {

    template<typename T>
    class Queue {
    private:
        dsa::SinglyLinkedList<T> list;

    public:
        void enqueue(const T& value);
        void dequeue();
        T front() const;
        T back() const;
        bool isEmpty() const;
        int size() const;
        void clear ();
    };

} // namespace dsa

#include "Queue.tpp"