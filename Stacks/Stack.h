#pragma once

#include "../LinkedLists/SinglyLinkedList.h"

#ifndef STACK_H
#define STACK_H

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
#endif //STACK_H
