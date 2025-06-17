#pragma once

#include <cstddef>
#include <stdexcept>

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

namespace dsa {

    template<typename T>
    class DynamicArray {
    private:
        T* data;
        size_t sz;  // size
        size_t cap; // capacity

        void resize(size_t newCap);

    public:
        // Constructors & Destructor
        DynamicArray();                                 // default
        ~DynamicArray();                                // destructor
        DynamicArray(const DynamicArray& other);        // copy constructor
        DynamicArray(DynamicArray&& other) noexcept;    // move constructor

        // Assignment Operators
        DynamicArray& operator=(const DynamicArray& other);     // copy assignment
        DynamicArray& operator=(DynamicArray&& other) noexcept; // move assignment

        // Core operations
        void pushFront(const T& value);
        void popFront();
        void pushBack(const T& value);
        void popBack();
        void insert(size_t index, const T& value);
        void erase(size_t index);
        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        T& at(size_t index);
        const T& at(size_t index) const;

        T& front();
        T& back();
        const T& front() const;
        const T& back() const;

        size_t size() const;
        size_t capacity() const;
        bool isEmpty() const;
        void clear();
        void reserve(size_t newCap);
        void shrinkToFit();
    };

} // namespace dsa

#include "DynamicArray.tpp"
#endif // DYNAMICARRAY_H
