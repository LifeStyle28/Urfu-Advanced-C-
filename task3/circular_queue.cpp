#include "circular_queue.hpp"

CircularQueue::CircularQueue(size_t size)
{
        V.resize(size);
}

bool CircularQueue::Push(int value)
{
        if (Full())
        {
            return false;
        }
        else
        {
            if (s == -1) s = 0; 
            e = (e + 1) % V.size();
            V[e] = value;
            return true;
        }
}

bool CircularQueue::Pop()
{
        if (Empty()) 
        {
            return false;
        }
        else 
        {
            if (s == e) 
	    {
                s = -1;
                e = -1;
            }
            else 
            {
                s = (s + 1) % V.size();
            }
            return true;
        }
}

int CircularQueue::Front() const
{
    if (Empty())
    {
        return -1;
    }
    else
    {
        return V[s];
    }
}

int CircularQueue::Back() const
{
    if (Empty())
    {
        return -1;
    }
    else
    {
        return V[e];
    }
}

bool CircularQueue::Empty() const
{
    if (s == -1)
        return true;
    else
        return false;
}

bool CircularQueue::Full() const
{
	if (s == 0 && e == V.size() - 1) 
	{
	    return true;
	}
	if (s == (e + 1) % V.size()) 
	{
	    return true;
	}
	return false;
}
