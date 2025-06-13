#ifndef DEQUE_TPP
#define DEQUE_TPP

namespace dsa {
    template<typename T>
    void Deque<T>::pushFront(const T& value) {
        list.prepend(value);
    }

    template<typename T>
    void Deque<T>::pushBack(const T& value) {
        list.append(value);
    }

    template<typename T>
    T Deque<T>::popFront() {
        if (list.isEmpty()) throw std::runtime_error("Deque is empty. Cannot pop front.");
        T value = list.front();
        list.remove(value);
        return value;
    }

    template<typename T>
    T Deque<T>::popBack() {
        if (list.isEmpty()) throw std::runtime_error("Deque is empty. Cannot pop back.");
        T value = list.back();
        list.remove(value);
        return value;
    }

    template<typename T>
    T Deque<T>::peekFront() const {
        if (list.isEmpty()) throw std::runtime_error("Deque is empty. Cannot peek front.");
        return list.front();
    }

    template<typename T>
    T Deque<T>::peekBack() const {
        if (list.isEmpty()) throw std::runtime_error("Deque is empty. Cannot peek back.");
        return list.back();
    }

    template<typename T>
    bool Deque<T>::isEmpty() const {
        return list.isEmpty();
    }

    template<typename T>
    int Deque<T>::getLength() const {
        return list.size();
    }


} // namespace dsa

#endif // DEQUE_TPP