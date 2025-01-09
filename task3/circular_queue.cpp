#include "circular_queue.hpp"

CircularQueue::CircularQueue(size_t size)
    : buffer_(size), head_(0), tail_(0), capacity_(size), count_(0) {}

bool CircularQueue::Push(int value) {
    if (Full()) {
        return false;
    }
    buffer_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    ++count_;
    return true;
}

bool CircularQueue::Pop() {
    if (Empty()) {
        return false;
    }
    head_ = (head_ + 1) % capacity_;
    --count_;
    return true;
}

int CircularQueue::Front() const {
    if (Empty()) {
        return -1;
    }
    return buffer_[head_];
}

int CircularQueue::Back() const {
    if (Empty()) {
        return -1;
    }
    return buffer_[(tail_ + capacity_ - 1) % capacity_];
}

bool CircularQueue::Empty() const {
    return count_ == 0;
}

bool CircularQueue::Full() const {
    return count_ == capacity_;
}
