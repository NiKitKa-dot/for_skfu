#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <list>
#include <string>
#include <stdexcept> // For exceptions
#include <limits> // For numeric_limits

template <typename T>
class Deque {
private:
    std::list<T> data; // Use std::list as the server class for storage
    size_t maxSize; // Optional max size for the deque

public:
    // Constructor with optional maximum size
    Deque(size_t max = std::numeric_limits<size_t>::max());

    // Add an element to the front of the deque
    void push_front(const T& value);

    // Add an element to the back of the deque
    void push_back(const T& value);

    // Remove the element from the front of the deque
    void pop_front();

    // Remove the element from the back of the deque
    void pop_back();

    // Access the element at the front of the deque
    T& front();
    const T& front() const;

    // Access the element at the back of the deque
    T& back();
    const T& back() const;

    // Check if the deque is empty
    bool empty() const;

    // Get the number of elements in the deque
    size_t size() const;
};

#endif // DEQUE_H