#include <iostream>
#include <string>
#include "deque.h"

int main() {
    try {
        // Instantiate Deque for different types
        Deque<int> intDeque(5);
        Deque<double> doubleDeque;
        Deque<std::string> stringDeque;

        // Test with int
        intDeque.push_back(10);
        intDeque.push_front(5);
        std::cout << "Int Deque Front: " << intDeque.front() << ", Back: " << intDeque.back() << std::endl;

        // Test with double
        doubleDeque.push_back(3.14);
        doubleDeque.push_front(2.71);
        std::cout << "Double Deque Front: " << doubleDeque.front() << ", Back: " << doubleDeque.back() << std::endl;

        // Test with string
        stringDeque.push_back("World");
        stringDeque.push_front("Hello");
        std::cout << "String Deque Front: " << stringDeque.front() << ", Back: " << stringDeque.back() << std::endl;

        // Test exceptions: Overflow
        try {
            intDeque.push_back(15);
            intDeque.push_back(20);
            intDeque.push_back(25); // This will throw an exception (size = 5)
        }
        catch (const std::overflow_error& e) {
            std::cerr << "Overflow Exception: " << e.what() << std::endl;
        }

        // Test exceptions: Underflow
        try {
            while (!intDeque.empty()) {
                intDeque.pop_back();
            }
            intDeque.pop_back(); // This will throw an exception (deque is empty)
        }
        catch (const std::underflow_error& e) {
            std::cerr << "Underflow Exception: " << e.what() << std::endl;
        }

        // Test exception: out_of_range
        try {
            std::cout << "Front of empty intDeque: " << intDeque.front() << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Out of Range Exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Unhandled Exception: " << e.what() << std::endl;
    }

    return 0;
}