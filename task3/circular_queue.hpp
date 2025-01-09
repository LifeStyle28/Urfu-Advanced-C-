#pragma once

#include <cstddef>

class CircularQueue {
private:   
    int* buffer; 
    size_t capacity;
    size_t front;
    size_t rear;
    size_t count;

public:
    explicit CircularQueue(size_t size); 
    ~CircularQueue(); 

    
    CircularQueue(const CircularQueue&) = delete;
    CircularQueue& operator=(const CircularQueue&) = delete;

   
    CircularQueue(CircularQueue&& other) noexcept;
    CircularQueue& operator=(CircularQueue&& other) noexcept;

    bool Push(int value); 
    bool Pop(); 
    int Front() const; 
    int Back() const;
    bool Empty() const; 
    bool Full() const; 
};
