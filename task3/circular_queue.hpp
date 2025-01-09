#pragma once

#include <cstddef>

class CircularQueue {
private:   
    int* buffer; 
    size_t capacity;
    size_t front;
    size_t rear;
    size_t count;

public:
    explicit CircularQueue(size_t size); // Создать очередь с определённым размером буфера
    ~CircularQueue(); // Деструктор для освобождения памяти

    // Удаляем копирование
    CircularQueue(const CircularQueue&) = delete;
    CircularQueue& operator=(const CircularQueue&) = delete;

    // Разрешаем перемещение
    CircularQueue(CircularQueue&& other) noexcept;
    CircularQueue& operator=(CircularQueue&& other) noexcept;

    bool Push(int value); // Добавить значение в конец очереди (false, если очередь заполнена)
    bool Pop(); // Удалить значение из начала очереди (false, если очередь пустая)
    int Front() const; // Получить значение из начала очереди (-1, если очередь пустая)
    int Back() const; // Получить значение из конца очереди (-1, если очередь пустая)
    bool Empty() const; // Проверить, пустая ли очередь
    bool Full() const; // Проверить, заполнена ли очередь
};

