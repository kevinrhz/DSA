#pragma once
#include "../LinkedLists/SinglyLinkedList.h"

namespace dsa {
    template<typename T>
    class Stack {
    private:
        dsa::SinglyLinkedList<T> list;

    public:
        Stack() = default;
        ~Stack() = default;

        void push(const T& value);
        void pop();
        T top() const;
        bool isEmpty() const;
        int size() const;
        void clear();
    };
} // namespace dsa

#include "Stack.tpp"