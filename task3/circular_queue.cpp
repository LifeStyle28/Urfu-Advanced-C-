#include "circular_queue.hpp"
#include <stdexcept>

CircularQueue::CircularQueue(size_t size)
{
	// your implementation here
CircularQueue::CircularQueue(size_t size) : capacity(size), front(0), rear(0), count(0) {
    buffer = new int[size];
}

bool CircularQueue::Push(int value)
{
    // your implementation here
bool CircularQueue::Push(int value) {
    if (Full()) {
        return false;
    }
    buffer[rear] = value;
    rear = (rear + 1) % capacity;
    count++;
    return true;
}

bool CircularQueue::Pop()
{
    // your implementation here
bool CircularQueue::Pop() {
    if (Empty()) {
        return false;
    }
    front = (front + 1) % capacity;
    count--;
    return true;
}

int CircularQueue::Front() const
{
    // your implementation here
int CircularQueue::Front() const {
    if (Empty()) {
        return -1;
    }
    return buffer[front];
}

int CircularQueue::Back() const
{
    // your implementation here
int CircularQueue::Back() const {
    if (Empty()) {
        return -1;
    }
    return buffer[(rear - 1 + capacity) % capacity];
}

bool CircularQueue::Empty() const
{
    // your implementation here
bool CircularQueue::Empty() const {
    return count == 0;
}

bool CircularQueue::Full() const
{
    // your implementation here
bool CircularQueue::Full() const {
    return count == capacity;
}
