#pragma once
#include <cstddef>
#include <stdexcept>

namespace dsa {

     /**
     * @brief A template-based dynamic array that manages a contiguous block of memory.
     *
     * This class provides an implementation of a dynamic array, similar to std::vector.
     * It automatically handles resizing when elements are added or removed. It is designed
     * to showcase manual memory management, pointer arithmetic, and the Rule of Five.
     *
     * @tparam T The type of element to be stored.
     */
    template<typename T>
    class DynamicArray {
    private:
        T* data;    // Pointer to the underlying array of elements.
        size_t sz;  // The number of elements currently stored in the array.
        size_t cap; // The total number of elements the array can hold (its capacity).

        /**
         * @brief Resizes the array to a new capacity.
         * @param newCap The new capacity. If newCap is 0, it deallocates memory.
         * If newCap < sz, data is truncated.
         */
        void resize(size_t newCap);

    public:
        //
        // Constructors & Destructor (Rule of Five)
        //
        /// @brief Default constructor. Creates an empty array with zero capacity.
        DynamicArray();
        /// @brief Destructor. Releases all allocated memory.
        ~DynamicArray();
        /// @brief Copy constructor. Creates a deep copy of another array.
        DynamicArray(const DynamicArray& other);
        /// @brief Move constructor. Takes ownership of another array's resources.
        DynamicArray(DynamicArray&& other) noexcept;

        //
        // Assignment Operators (Rule of Five)
        //
        /// @brief Copy assignment operator. Replaces content with a deep copy of another array.
        DynamicArray& operator=(const DynamicArray& other);
        /// @brief Move assignment operator. Takes ownership of another array's resources.
        DynamicArray& operator=(DynamicArray&& other) noexcept;

        //
        // Core Operations
        //
        /**
         * @brief Inserts an element at the beginning of the array. O(n).
         * @param value The value to insert.
         */
        void pushFront(const T& value);

        /**
         * @brief Removes the first element of the array. O(n).
         * @throws std::out_of_range if the array is empty.
         */
        void popFront();

        /**
         * @brief Appends an element to the end of the array. Amortized O(1).
         * @param value The value to append.
         */
        void pushBack(const T& value);

        /**
         * @brief Removes the last element from the array. O(1).
         * @throws std::out_of_range if the array is empty.
         */
        void popBack();

        /**
         * @brief Inserts an element at a specific index. O(n).
         * @param index The position to insert at.
         * @param value The value to insert.
         * @throws std::out_of_range if index > size().
         */
        void insert(size_t index, const T& value);

        /**
         * @brief Erases an element at a specific index. O(n).
         * @param index The position of the element to erase.
         * @throws std::out_of_range if index >= size().
         */
        void erase(size_t index);

        //
        // Accessors
        //
        /// @brief Accesses an element by index without bounds checking. O(1).
        T& operator[](size_t index);
        /// @brief Accesses an element by index without bounds checking (const version). O(1).
        const T& operator[](size_t index) const;

        /// @brief Accesses an element by index with bounds checking. O(1).
        /// @throws std::out_of_range if index >= size().
        T& at(size_t index);
        /// @brief Accesses an element by index with bounds checking (const version). O(1).
        /// @throws std::out_of_range if index >= size().
        const T& at(size_t index) const;

        /// @brief Returns a reference to the first element. O(1).
        /// @throws std::out_of_range if the array is empty.
        T& front();
        /// @brief Returns a reference to the last element. O(1).
        /// @throws std::out_of_range if the array is empty.
        T& back();
        /// @brief Returns a const reference to the first element. O(1).
        /// @throws std::out_of_range if the array is empty.
        const T& front() const;
        /// @brief Returns a const reference to the last element. O(1).
        /// @throws std::out_of_range if the array is empty.
        const T& back() const;

        //
        // Capacity & State
        //
        /// @brief Returns the number of elements in the array. O(1).
        size_t size() const;
        /// @brief Returns the storage capacity of the array. O(1).
        size_t capacity() const;
        /// @brief Checks if the array is empty. O(1).
        bool isEmpty() const;

        /**
         * @brief Clears the array, removing all elements. O(1).
         * Note: Does not release memory. Capacity remains unchanged.
         */
        void clear();

        /**
         * @brief Requests a change in capacity. O(n).
         * @param newCap The desired new capacity. If newCap > capacity(), reallocates.
         */
        void reserve(size_t newCap);

        /**
         * @brief Reduces capacity to fit the size. O(n).
         * Releases unused memory.
         */
        void shrinkToFit();
    };

} // namespace dsa

#include "DynamicArray.tpp"
