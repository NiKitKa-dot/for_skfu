#include "deque.h"

template <typename T>
Deque<T>::Deque(size_t max) : maxSize(max) {}

template <typename T>
void Deque<T>::push_front(const T& value) {
    if (size() >= maxSize) {
        throw std::overflow_error("Deque is full (push_front)");
    }
    data.push_front(value);
}

template <typename T>
void Deque<T>::push_back(const T& value) {
    if (size() >= maxSize) {
        throw std::overflow_error("Deque is full (push_back)");
    }
    data.push_back(value);
}

template <typename T>
void Deque<T>::pop_front() {
    if (empty()) {
        throw std::underflow_error("Deque is empty (pop_front)");
    }
    data.pop_front();
}

template <typename T>
void Deque<T>::pop_back() {
    if (empty()) {
        throw std::underflow_error("Deque is empty (pop_back)");
    }
    data.pop_back();
}

template <typename T>
T& Deque<T>::front() {
    if (empty()) {
        throw std::out_of_range("Deque is empty (front)");
    }
    return data.front();
}

template <typename T>
const T& Deque<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Deque is empty (front)");
    }
    return data.front();
}

template <typename T>
T& Deque<T>::back() {
    if (empty()) {
        throw std::out_of_range("Deque is empty (back)");
    }
    return data.back();
}

template <typename T>
const T& Deque<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Deque is empty (back)");
    }
    return data.back();
}

template <typename T>
bool Deque<T>::empty() const {
    return data.empty();
}

template <typename T>
size_t Deque<T>::size() const {
    return data.size();
}