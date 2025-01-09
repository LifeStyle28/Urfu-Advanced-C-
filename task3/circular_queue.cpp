#include "circular_queue.hpp"
#include <stdexcept>

CircularQueue::CircularQueue(size_t size) : buffer(new int[size]), capacity(size), front(0), rear(0), count(0) {}

bool CircularQueue::Push(int value) {
    if (count == capacity) {
        return false;
    }
    buffer[rear] = value;
    rear = (rear + 1) % capacity;
    ++count;
    return true;
}

bool CircularQueue::Pop() {
    if (count == 0) {
        return false;
    }
    front = (front + 1) % capacity;
    --count;
    return true;
}

int CircularQueue::Front() const {
    return count == 0 ? -1 : buffer[front];
}

int CircularQueue::Back() const {
    return count == 0 ? -1 : buffer[(rear - 1 + capacity) % capacity];
}

bool CircularQueue::Empty() const {
    return count == 0;
}

bool CircularQueue::Full() const {
    return count == capacity;
}
