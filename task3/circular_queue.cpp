#include "circular_queue.hpp"
#include <stdexcept>
#include <vector>

CircularQueue::CircularQueue(size_t size) : capacity(size), front(0), rear(0)  {
    data = std::vector(size);
}

bool CircularQueue::Push(int value) {
    if (Full()) {
        return false;
    }
    data[rear] = value;
    rear = (rear + 1) % capacity;
    return true;
}

bool CircularQueue::Pop() {
    if (Empty()) {
        return false;
    }
    front = (front + 1) % capacity;
    return true;
}

int CircularQueue::Front() const {
    if (Empty()) {
        return -1;
    }
    return data[front];
}

int CircularQueue::Back() const {
    if (Empty()) {
        return -1;
    }
    return data[(rear - 1 + capacity) % capacity];
}

bool CircularQueue::Empty() const {
    return data.size() == 0;
}

bool CircularQueue::Full() const {
    return data.size() == capacity;
}
