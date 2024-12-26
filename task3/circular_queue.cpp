#include "circular_queue.hpp"
#include <stdexcept>

// Конструктор. Инициализация параметров.
CircularQueue::CircularQueue(size_t size)
    : data(size), head(0), tail(0), maxSize(size), currentSize(0) {}

// Метод для добавления элемента в очередь
bool CircularQueue::Push(int value) {
    if (Full()) {
        return false; // Если очередь заполнена, вернуть false
    }
    data[tail] = value; // Добавить значение в очередь
    tail = (tail + 1) % maxSize; // Обновить конец очереди
    currentSize++; // Увеличить текущее количество элементов
    return true; // Успешно добавлено
}

// Метод для удаления элемента из очереди
bool CircularQueue::Pop() {
    if (Empty()) {
        return false; // Если очередь пуста, вернуть false
    }
    head = (head + 1) % maxSize; // Обновить начало очереди
    currentSize--; // Уменьшить текущее количество элементов
    return true; // Успешно удалено
}

// Метод для получения элемента из начала очереди
int CircularQueue::Front() const {
    if (Empty()) {
        return -1; // Если очередь пуста, вернуть -1
    }
    return data[head]; // Вернуть значение из начала очереди
}

// Метод для получения элемента из конца очереди
int CircularQueue::Back() const {
    if (Empty()) {
        return -1; // Если очередь пуста, вернуть -1
    }
    return data[(tail - 1 + maxSize) % maxSize]; // Вернуть последнее добавленное значение
}

// Метод для проверки, пуста ли очередь
bool CircularQueue::Empty() const {
    return currentSize == 0; // Очередь пуста, если количество элементов = 0
}

// Метод для проверки, заполнена ли очередь
bool CircularQueue::Full() const {
    return currentSize == maxSize; // Очередь заполнена, если текущее количество элементов равно максимальному
}
