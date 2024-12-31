#include "circular_queue.hpp"
#include <vector>

CircularQueue::CircularQueue(size_t size) : capacity(size), front(0), rear(0), size(0) {
    buffer.resize(capacity);
}

bool CircularQueue::Push(int value) {
    if (IsFull()) {
        return false; // Очередь полна
    }
    buffer[rear] = value; // Добавляем элемент в очередь
    rear = (rear + 1) % capacity; // Обновляем заднюю границу
    ++size; // Увеличиваем размер очереди
    return true;
}

bool CircularQueue::Pop() {
    if (IsEmpty()) {
        return false; // Очередь пуста
    }
    front = (front + 1) % capacity; // Удаляем элемент из очереди
    --size; // Уменьшаем размер очереди
    return true;
}

int CircularQueue::Front() const {
    if (IsEmpty()) {
        return -1; // Если очередь пуста, возвращаем -1
    }
    return buffer[front]; // Возвращаем элемент на передней границе
}

int CircularQueue::Back() const {
    if (IsEmpty()) {
        return -1; // Если очередь пуста, возвращаем -1
    }
    return buffer[(rear + capacity - 1) % capacity]; // Возвращаем последний элемент
}

bool CircularQueue::IsEmpty() const {
    return size == 0; // Проверка на пустоту
}

bool CircularQueue::IsFull() const {
    return size == capacity; // Проверка на полноту
