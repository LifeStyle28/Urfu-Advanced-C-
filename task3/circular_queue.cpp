#include "circular_queue.hpp"
#include <stdexcept>
#include <utility>

CircularQueue::CircularQueue(size_t size) 
    : capacity(size), front(0), rear(0), count(0) {
    if (size == 0) {
        throw std::invalid_argument("Size of the queue must be greater than 0");
    }
    buffer = new int[size];
}

CircularQueue::~CircularQueue() {
    delete[] buffer;
}

CircularQueue::CircularQueue(CircularQueue&& other) noexcept 
    : buffer(nullptr), capacity(0), front(0), rear(0), count(0) {
    *this = std::move(other);
}

CircularQueue& CircularQueue::operator=(CircularQueue&& other) noexcept {
    if (this != &other) {
        delete[] buffer;

        buffer = other.buffer;
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        count = other.count;

        other.buffer = nullptr;
        other.capacity = 0;
        other.front = 0;
        other.rear = 0;
        other.count = 0;
    }
    return *this;
}

bool CircularQueue::Push(int value) {
    if (Full()) {
        return false;
    }
    buffer[rear] = value;
    rear = (rear + 1) % capacity;
    count++;
    return true;
}

bool CircularQueue::Pop() {
    if (Empty()) {
        return false;
    }
    front = (front + 1) % capacity;
    count--;
    return true;
}

int CircularQueue::Front() const {
    if (Empty()) {
        return -1;
    }
    return buffer[front];
}

int CircularQueue::Back() const {
    if (Empty()) {
        return -1;
    }
    return buffer[(rear == 0 ? capacity : rear) - 1];
}

bool CircularQueue::Empty() const {
    return count == 0;
}

bool CircularQueue::Full() const {
    return count == capacity;
}



