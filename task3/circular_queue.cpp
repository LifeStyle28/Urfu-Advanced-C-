#include "circular_queue.hpp"

CircularQueue::CircularQueue(size_t size) : 
    maxSize(size), 
    head(0), 
    tail(0), 
    currentSize(0) {
    buffer.resize(size);
}

bool CircularQueue::Push(int value) {
    if (Full()) {
        return false; // очередь заполнена
    }
    buffer[tail] = value;
    tail = (tail + 1) % maxSize; // перемещаемся по кругу
    currentSize++;
    return true;
}

bool CircularQueue::Pop() {
    if (Empty()) {
        return false; // очередь пустая
    }
    head = (head + 1) % maxSize; // перемещаемся по кругу
    currentSize--;
    return true;
}

int CircularQueue::Front() const {
    if (Empty()) {
        return -1; // очередь пустая
    }
    return buffer[head];
}

int CircularQueue::Back() const {
    if (Empty()) {
        return -1; // очередь пустая
    }
    return buffer[(tail - 1 + maxSize) % maxSize]; // последний элемент
}

bool CircularQueue::Empty() const {
    return currentSize == 0;
}

bool CircularQueue::Full() const {
    return currentSize == maxSize;
}
