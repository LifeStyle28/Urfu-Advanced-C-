#include "circular_queue.hpp"
#include <vector>

CircularQueue::CircularQueue(size_t max_size) : max_capacity(max_size), current_size(0), head(0), tail(0) {
    data_buffer.resize(max_size);  // Pre-allocate exact size
}

bool CircularQueue::Push(int element) {
    if (Full()) {
        return false;
    }
    data_buffer[tail] = element;
    tail = (tail + 1) % max_capacity;
    current_size++;
    return true;
}

bool CircularQueue::Pop() {
    if (Empty()) {
        return false;
    }
    head = (head + 1) % max_capacity;
    current_size--;
    return true;
}

int CircularQueue::Front() const {
    if (Empty()) {
        return -1;
    }
    return data_buffer[head];
}

int CircularQueue::Back() const {
    if (Empty()) {
        return -1;
    }
    return data_buffer[(tail - 1 + max_capacity) % max_capacity];
}

bool CircularQueue::Empty() const {
    return current_size == 0;
}

bool CircularQueue::Full() const {
    return current_size == max_capacity;
}
