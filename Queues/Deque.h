#ifndef DSA_DEQUE_H
#define DSA_DEQUE_H
#include "../LinkedLists/DoublyLinkedList.h"

namespace dsa {
    template<typename T>
    class Deque {
    private:
        DoublyLinkedList<T> list;

    public:
        void pushFront(const T& value);
        void pushBack(const T& value);
        T popFront();
        T popBack();
        T peekFront() const;
        T peekBack() const;
        bool isEmpty() const;
        int getLength() const;
    };

} // namespace dsa

#include "Deque.tpp"
#endif // DEQUE_H