#pragma once
#include <cstddef>
#include <vector>



class CircularQueue 
{
private:
   std::vector<int> buffer;  // это, крч, буфер!!! мдаааа, документации я буду писать топовые
   size_t max_razmer;        // максимум сайз оф куеуе
   size_t now_rozmer;        // мама сказала, что этот параметр показывает сколько сейчас элементов в очереди
   size_t pered;             // красивое, аки крабовый салат на новогоднем столе, лицо очереди
   size_t zad;               // попа очереди

public:
   CircularQueue(size_t size) : max_razmer(size), now_rozmer(0), pered(0), zad(0)
   {
      buffer.resize(size);  
   }
   bool Push(int value); // добавить значение в конец очереди (false, если очередь заполнена)
   bool Pop(); // удалить значение из начала очереди (false, если очередь пустая)
   int Front() const; // получить значение из начала очереди (-1, если очередь пустая)
   int Back() const; // получить значение из конца очереди (-1, если очередь пустая)
   bool Empty() const; // проверить пустая ли очередь
   bool Full() const; // проверить заполнена ли очередь
};

