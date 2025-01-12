#pragma once
#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#include <vector>
#include <stdexcept>

class CircularQueue {
public:
    CircularQueue(size_t size);

    bool Push(int value);
    bool Pop();
    int Front() const;
    int Back() const;
    bool Empty() const;
    bool Full() const;

private:
    std::vector<int> buffer;
    size_t maxSize;
    size_t frontIndex;
    size_t backIndex;
    size_t count; // текущее количество элементов в очереди
};

#endif // CIRCULAR_QUEUE_HPP
