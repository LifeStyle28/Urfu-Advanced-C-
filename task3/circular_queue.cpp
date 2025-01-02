#include "circular_queue.hpp"
#include <vector>
CircularQueue::CircularQueue(size_t size): n(0) , size(size) , start(0) , end(0)
{
	Mass.resize(size);
}
bool CircularQueue::Push(int value)
{
	if (Full()) 
	{
        	return false;
	}
	Mass[end] = value;
	end = (end + 1) % size;
	n++;
	return true;
}

bool CircularQueue::Pop()
{
	if (Empty())
    	{
        	return false;
    	}
	start = (start + 1) % size;
    	n--;
    	return true;
}

int CircularQueue::Front() const
{
	if (Empty()) 
	{
	return -1;
	}
	return Mass[start];
}

int CircularQueue::Back() const
{
	if (Empty())
	{
		return -1;
	}
	return Mass[(end - 1 + size) % size];
}

bool CircularQueue::Empty() const
{
    return (n == 0);
}

bool CircularQueue::Full() const
{
    return (n == size);
}
