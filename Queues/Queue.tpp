namespace dsa {

    template<typename T>
    void Queue<T>::enqueue(const T& value) {
        list.append(value);
    }

    template<typename T>
    void Queue<T>::dequeue() {
        if (isEmpty()) throw std::runtime_error("Queue is empty. Cannot dequeue.");
        list.removeFront();
    }

    template<typename T>
    T Queue<T>::front() const {
        return list.front();
    }

    template<typename T>
    T Queue<T>::back() const {
        return list.back();
    }

    template<typename T>
    bool Queue<T>::isEmpty() const {
        return list.isEmpty();
    }

    template<typename T>
    int Queue<T>::size() const {
        return list.size();
    }

    template<typename T>
    void Queue<T>::clear() {
        list.clear();
    }

} // namespace dsa