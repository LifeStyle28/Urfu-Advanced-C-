#include "circular_queue.hpp"

CircularQueue::CircularQueue(size_t size)
{
	CircularQueue::CircularQueue(size_t max_size) : {
    mass.resize(max_size); 
}

bool CircularQueue::Push(int value)
{
    if (Full()) {
        return false;
    }
    else{
    mass[end] = value;
    end = (end + 1) % capacity;
    end++;
    return true;
    }
}

bool CircularQueue::Pop()
{
    if (Full()) {
        return false;
    }
    else{
    end = (end - 1) % capacity;
    size--;
    return true;
    }
}

int CircularQueue::Front() const
{
    if(Empty())
    {
	    return -1;
    }
	else
    {
	    return mass[front];
    }
}

int CircularQueue::Back() const
{
     if(Empty())
    {
	    return -1;
    }
	else
    {
	    return mass[end];
    }
}

bool CircularQueue::Empty() const
{
    
    return size == 0;
}

bool CircularQueue::Full() const
{
    return size == capacity;
}
