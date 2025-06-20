#pragma once
#include "../LinkedLists/SinglyLinkedList.h"

namespace dsa {
    /**
     * @brief A FIFO (First-In, First-Out) container adaptor.
     *
     * This Queue is implemented using an underlying dsa::SinglyLinkedList.
     * It provides a standard queue interface for enqueue and dequeue operations.
     *
     * @tparam T The type of element to be stored.
     */
    template<typename T>
    class Queue {
    private:
        dsa::SinglyLinkedList<T> list;  // The underlying container

    public:
        /**
         * @brief Adds an element to the back of the queue. O(1).
         * @param value The value to enqueue.
         */
        void enqueue(const T& value);

        /**
         * @brief Removes the element from the front of the queue. O(1).
         * @throws std::runtime_error if the queue is empty.
         */
        void dequeue();

        /**
         * @brief Returns a const reference to the element at the front of the queue. O(1).
         * @return Const reference to the front element.
         * @throws std::runtime_error if the queue is empty.
         */
        T front() const;

        /**
         * @brief Returns a const reference to the element at the back of the queue. O(1).
         * @return Const reference to the back element.
         * @throws std::runtime_error if the queue is empty.
         */
        T back() const;

        /**
         * @brief Checks if the queue is empty. O(1).
         * @return true if the queue is empty, false otherwise.
         */
        bool isEmpty() const;

        /**
         * @brief Returns the number of elements in the queue. O(n).
         * Note: Complexity is O(n) due to the underlying SinglyLinkedList::size().
         * @return The number of elements.
         */
        int size() const;

        /**
         * @brief Clears all elements from the queue. O(n).
         */
        void clear ();
    };

} // namespace dsa

#include "Queue.tpp"