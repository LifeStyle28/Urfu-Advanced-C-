#include "circular_queue.hpp"
#include <iostream>
CircularQueue::CircularQueue(size_t size) : maxSize(size), frontIndex(0), backIndex(0), count(0) {
    if (size == 0) {
        throw std::invalid_argument("Size of the queue must be greater than zero.");
    }
    buffer.resize(size);
}

bool CircularQueue::Push(int value) {
    if (Full()) {
        return false; // Очередь заполнена
    }
    buffer[backIndex] = value;
    backIndex = (backIndex + 1) % maxSize; // Циклическое перемещение индекса
    ++count;
    return true;
}

bool CircularQueue::Pop() {
    if (Empty()) {
        return false; // Очередь пуста
    }
    frontIndex = (frontIndex + 1) % maxSize; // Циклическое перемещение индекса
    --count;
    return true;
}

int CircularQueue::Front() const {
    if (Empty()) {
        return -1; // Очередь пуста
    }
    return buffer[frontIndex];
}

int CircularQueue::Back() const {
    if (Empty()) {
        return -1; // Очередь пуста
    }
    // backIndex указывает на следующий пустой элемент, поэтому вычитаем 1 для получения последнего элемента
    return buffer[(backIndex - 1 + maxSize) % maxSize];
}

bool CircularQueue::Empty() const {
    return count == 0;
}

bool CircularQueue::Full() const {
    return count == maxSize;
}
int main() {
    CircularQueue queue(5);

    // Добавляем элементы
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);
    queue.Push(5);

    std::cout << "Front: " << queue.Front() << std::endl; 
    std::cout << "Back: " << queue.Back() << std::endl;   

    // Попробуем добавить еще один элемент (должно вернуть false)
    if (!queue.Push(6)) {
        std::cout << "Queue is full!" << std::endl; 
    }

    // Удаляем элементы
    queue.Pop();
    queue.Pop();

    std::cout << "Front: " << queue.Front() << std::endl; 
    std::cout << "Back: " << queue.Back() << std::endl;  

    // Добавляем новый элемент
    queue.Push(6); 
    std::cout << "Back after adding 6: " << queue.Back() << std::endl; 

    return 0;
}
