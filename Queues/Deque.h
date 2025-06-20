#pragma once
#include "../LinkedLists/DoublyLinkedList.h"

namespace dsa {
    /**
     * @brief A double-ended queue (deque) container adaptor.
     *
     * This Deque allows for efficient insertion and deletion at both its front
     * and back. It is implemented using an underlying dsa::DoublyLinkedList
     * to ensure O(1) performance for these operations.
     *
     * @tparam T The type of element stored in the deque.
     */
    template<typename T>
    class Deque {
    private:
        DoublyLinkedList<T> list;   // The underlying container

    public:
        /**
         * @brief Inserts an element at the front of the deque. O(1).
         * @param value The value to insert.
         */
        void pushFront(const T& value);

        /**
         * @brief Inserts an element at the back of the deque. O(1).
         * @param value The value to insert.
         */
        void pushBack(const T& value);

        /**
         * @brief Removes and returns the element at the front of the deque. O(1).
         * @return The value of the front element.
         * @throws std::runtime_error if the deque is empty.
         */
        T popFront();

        /**
         * @brief Removes and returns the element at the back of the deque. O(1).
         * @return The value of the back element.
         * @throws std::runtime_error if the deque is empty.
         */
        T popBack();

        /**
         * @brief Returns a const reference to the element at the front. O(1).
         * @return Const reference to the front element.
         * @throws std::runtime_error if the deque is empty.
         */
        T peekFront() const;

        /**
         * @brief Returns a const reference to the element at the back. O(1).
         * @return Const reference to the back element.
         * @throws std::runtime_error if the deque is empty.
         */
        T peekBack() const;

        /**
         * @brief Checks if the deque is empty. O(1).
         * @return true if empty, false otherwise.
         */
        bool isEmpty() const;

        /**
         * @brief Returns the number of elements in the deque. O(n).
         * Note: Complexity is O(n) due to the underlying DoublyLinkedList::size().
         * @return The number of elements.
         */
        int getLength() const;
    };

} // namespace dsa

#include "Deque.tpp"