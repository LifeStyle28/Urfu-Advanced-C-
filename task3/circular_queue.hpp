#pragma once

#include <vector>

class CircularQueue {
private:
    std::vector<int> data_buffer;   
    size_t max_capacity;           
    size_t current_size;         
    size_t head;                  
    size_t tail;                   

public:
    CircularQueue(size_t max_size); 

    bool Push(int element);      
    bool Pop();                   
    int Front() const;           
    int Back() const;            

    bool Empty() const;            
    bool Full() const;              
};
