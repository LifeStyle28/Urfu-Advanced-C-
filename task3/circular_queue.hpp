#pragma once

#include <vector>

class CircularQueue {
private:
    std::vector<int> buffer;            // Dynamic array to store elements
    size_t capacity;        // Maximum size of the queue
    size_t size;           // Current count of elements
    size_t front;          // Index of the front element
    size_t rear;           // Index of the rear element

public:
    CircularQueue(size_t size);

    bool Push(int value);
    bool Pop();
    int Front() const;
    int Back() const;
    
    bool Empty() const;
    bool Full() const;
};
