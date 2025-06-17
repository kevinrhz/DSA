#include <iterator>

namespace dsa {

    template<typename T>
    DynamicArray<T>::DynamicArray() : data(nullptr), sz(0), cap(0) {}

    template<typename T>
    DynamicArray<T>::~DynamicArray() {
        delete[] data;
        data = nullptr;
        sz = 0;
        cap = 0;
    }

    // Copy constructor
    template<typename T>
    DynamicArray<T>::DynamicArray(const DynamicArray& other) : data(new T[other.cap]), sz(other.size()), cap(other.cap) {
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    // Move constructor
    template<typename T>
    DynamicArray<T>::DynamicArray(DynamicArray&& other) noexcept : data(other.data), sz(other.sz), cap(other.cap) {
        other.data = nullptr;
        other.sz = 0;
        other.cap = 0;
    }

    // Copy assignment operator
    template<typename T>
    DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
        if (this == &other) return *this;

        T* newData = new T[other.cap];
        for (size_t i = 0; i < other.sz; ++i) {
            newData[i] = other.data[i];
        }

        delete[] data;
        data = newData;
        sz = other.sz;
        cap = other.cap;

        return *this;
    }

    // Move assignment operator
    template<typename T>
    DynamicArray<T> &DynamicArray<T>::operator=(DynamicArray &&other) noexcept {
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        sz = other.sz;
        cap = other.cap;

        other.data = nullptr;
        other.sz = 0;
        other.cap = 0;

        return *this;
    }

    template<typename T>
    void DynamicArray<T>::resize(size_t newCap) {
        T* newData = new T[newCap];
        for (size_t i = 0; i < sz; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cap = newCap;
    }

    template<typename T>
    void DynamicArray<T>::pushFront(const T& value) {
        if (sz == cap) { resize(cap == 0 ? 1 : cap * 2); }

        // Shift all elements right
        for (size_t i = sz; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = value;
        ++sz;
    }

    template<typename T>
    void DynamicArray<T>::popFront() {
        if (isEmpty()) throw std::out_of_range("Cannot pop from empty DynamicArray");

        // Shift all elements left
        for (size_t i = 0; i < sz - 1; ++i) {
            data[i] = data[i + 1];
        }
        --sz;
    }

    template<typename T>
    void DynamicArray<T>::pushBack(const T& value) {
        if (sz == cap) {
            resize(cap == 0 ? 1 : cap * 2);
        }
        data[sz++] = value;
    }

    template<typename T>
    void DynamicArray<T>::popBack() {
        if (sz == 0) throw std::out_of_range("Cannot pop from empty DynamicArray.");
        --sz;
    }

    template<typename T>
    void DynamicArray<T>::insert(size_t index, const T& value) {
        if (index > sz) throw std::out_of_range("Insert index out of bounds");

        if (sz == cap) {
            resize(cap == 0 ? 1 : cap * 2);
        }

        for (size_t i = sz; i > index; --i) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        ++sz;
    }

    template<typename T>
    void DynamicArray<T>::erase(size_t index) {
        if (index >= sz) throw std::out_of_range("Erase index out of bounds");

        for (size_t i = index; i < sz - 1; ++i) {
            data[i] = data[i + 1];
        }
        --sz;
    }


    template<typename T>
    T &DynamicArray<T>::operator[](size_t index) {
        if (index >= sz) throw std::out_of_range("Index out of bounds.");
        return data[index];
    }

    template<typename T>
    const T &DynamicArray<T>::operator[](size_t index) const {
        if (index >= sz) throw std::out_of_range("Index out of bounds.");
        return data[index];
    }

    template<typename T>
    T& DynamicArray<T>::at(size_t index) {
        if (index >= sz) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    template<typename T>
    const T& DynamicArray<T>::at(size_t index) const {
        if (index >= sz) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    template<typename T>
    T& DynamicArray<T>::front() {
        if (isEmpty()) throw std::out_of_range("Cannot access front of empty DynamicArray");
        return data[0];
    }

    template<typename T>
    T& DynamicArray<T>::back() {
        if (isEmpty()) throw std::out_of_range("Cannot access back of empty DynamicArray");
        return data[sz - 1];
    }

    template<typename T>
    const T& DynamicArray<T>::front() const {
        if (isEmpty()) throw std::out_of_range("Cannot access front of empty DynamicArray");
        return data[0];
    }

    template<typename T>
    const T& DynamicArray<T>::back() const {
        if (isEmpty()) throw std::out_of_range("Cannot access back of empty DynamicArray");
        return data[sz - 1];
    }


    template<typename T>
    size_t DynamicArray<T>::size() const { return sz; }

    template<typename T>
    size_t DynamicArray<T>::capacity() const { return cap; }

    template<typename T>
    bool DynamicArray<T>::isEmpty() const { return sz == 0; }

    template<typename T>
    void DynamicArray<T>::clear() { sz = 0; }

    template<typename T>
    void DynamicArray<T>::reserve(size_t newCap) {
        if (newCap <= cap) return;

        T* newData = new T[newCap];
        for (size_t i = 0; i < sz; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cap = newCap;
    }

    template<typename T>
    void DynamicArray<T>::shrinkToFit() {
        if (sz == cap) return;

        T* newData = new T[sz];
        for (size_t i = 0; i < sz; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cap = sz;
    }

} // namespace dsa