namespace dsa {

    template<typename T>
    void Stack<T>::push(const T& value) {
        list.prepend(value);
    }

    template<typename T>
    void Stack<T>::pop() {
        if (list.isEmpty())
            throw std::runtime_error("Stack underflow: cannot pop from empty stack");
        list.remove(list.front());
    }

    template<typename T>
    T Stack<T>::top() const {
        return list.front();
    }

    template<typename T>
    bool Stack<T>::isEmpty() const {
        return list.isEmpty();
    }

    template<typename T>
    int Stack<T>::size() const {
        return list.size();
    }

    template<typename T>
    void Stack<T>::clear() {
        list.clear();
    }

} // namespace dsa