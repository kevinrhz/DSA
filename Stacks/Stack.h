#pragma once
#include "../LinkedLists/SinglyLinkedList.h"

namespace dsa {
    /**
     * @brief A LIFO (Last-In, First-Out) container adaptor.
     *
     * This Stack provides a classic LIFO interface but is implemented using an
     * underlying dsa::SinglyLinkedList container. It restricts the interface
     * to standard stack operations.
     *
     * @tparam T The type of element to be stored.
     */
    template<typename T>
    class Stack {
    private:
        dsa::SinglyLinkedList<T> list;  // The underlying container

    public:
        Stack() = default;
        ~Stack() = default;

        /**
         * @brief Pushes a new element onto the top of the stack. O(1).
         * @param value The value to be pushed.
         */
        void push(const T& value);

        /**
         * @brief Removes the top element from the stack. O(1).
         * @throws std::runtime_error if the stack is empty.
         */
        void pop();

        /**
         * @brief Returns a const reference to the top element of the stack. O(1).
         * @return Const reference to the top element.
         * @throws std::runtime_error if the stack is empty.
         */
        T top() const;

        /**
         * @brief Checks if the stack is empty. O(1).
         * @return true if the stack contains no elements, false otherwise.
         */
        bool isEmpty() const;

        /**
         * @brief Returns the number of elements in the stack. O(n).
         * Note: Complexity is O(n) due to the underlying SinglyLinkedList::size().
         * @return The number of elements.
         */
        int size() const;

        /**
         * @brief Clears all elements from the stack. O(n).
         */
        void clear();
    };
} // namespace dsa

#include "Stack.tpp"