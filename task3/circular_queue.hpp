#pragma once

#include <vector>
#include <stdexcept>

class CircularQueue {
private:
    std::vector<int> elements; // Хранилище для элементов очереди
    size_t maxSize;            // Максимальная вместимость очереди
    size_t currentSize;        // Текущий размер очереди
    size_t headIndex;          // Индекс первого элемента
    size_t tailIndex;          // Индекс последнего элемента

public:
    explicit CircularQueue(size_t size); // Конструктор с заданным размером очереди
    bool enqueue(int value);              // Добавить элемент в очередь (возвращает false, если очередь полна)
};

CircularQueue::CircularQueue(size_t size) 
    : maxSize(size), currentSize(0), headIndex(0), tailIndex(0), elements(size) {}

bool CircularQueue::enqueue(int value) {
    if (currentSize >= maxSize) {
        return false; // Очередь полна
    }
    elements[tailIndex] = value; // Добавляем элемент
    tailIndex = (tailIndex + 1) % maxSize; // Обновляем индекс конца очереди
    ++currentSize; // Увеличиваем текущий размер
    return true; // Успешное добавление
}
