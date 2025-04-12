#pragma once

#include <iostream>
#include <limits.h>

using namespace std;

class Queue {
private:
    int front, rear, size;
    unsigned capacity;
    int* array;
public:
    Queue(unsigned capacity)
    {
        this->capacity = capacity;
        this->front = this->size = 0;
        this->rear = capacity - 1;
        this->array = new int[capacity];
    }
    bool IsFull()
    {
        return (size == capacity);
    }
    bool IsEmpty()
    {
        return (size == 0);
    }
    void Enqueue(int item)
    {
        if (IsFull())
        {
            cout << "Queue is full\n";
            return;
        }
        this->rear = (this->rear + 1) % this->capacity;
        this->array[this->rear] = item;
        this->size = this->size + 1;
    }
    int Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        int item = this->array[this->front];
        this->front = (this->front + 1) % this->capacity;
        this->size = this->size - 1;
        return item;
    }
    void Display()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        int i = this->front;
        for (int j = 0; j < this->size; j++)
        {
            cout << this->array[i] << " ";
            i = (i + 1) % this->capacity;
        }
        cout << endl;
    }
    int DequeueElement(int position)
    {
        if (IsEmpty())
        {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        if (position > this->size)
        {
            cout << "Position is out of range\n";
            return INT_MIN;
        }
        int item = this->array[position];
        for (int j = position; j < this->rear; j++)
        {
            this->array[j] = this->array[j + 1];
        }
        this->size = this->size - 1;
        this->front = (this->front) % this->capacity;
        this->rear = (this->rear - 1) % this->capacity;
        return item;
    }

	Queue operator+(Queue& q)
	{
		Queue temp(this->capacity + q.capacity);
		for (int i = 0; i < this->size; i++)
		{
			temp.Enqueue(this->array[i]);
		}
		for (int i = 0; i < q.size; i++)
		{
			temp.Enqueue(q.array[i]);
		}
		return temp;
	}
	Queue& operator=(Queue& q)
	{
		this->capacity = q.capacity;
		this->front = q.front;
		this->rear = q.rear;
		this->size = q.size;
		this->array = new int[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->array[i] = q.array[i];
		}
		return *this;
	}
	friend bool operator==(Queue& q1, Queue& q2)
	{
		if (q1.size != q2.size)
		{
			return false;
		}
		for (int i = 0; i < q1.size; i++)
		{
			if (q1.array[i] != q2.array[i])
			{
				return false;
			}
		}
		return true;
	}
    friend bool operator!=(Queue& q1, Queue& q2)
    {
		return !(q1 == q2);
    }
    friend bool operator<(Queue& q1, Queue& q2)
    {
		if (q1.size < q2.size)
		{
			return true;
		}
		else if (q1.size > q2.size)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < q1.size; i++)
			{
				if (q1.array[i] < q2.array[i])
				{
					return true;
				}
				else if (q1.array[i] > q2.array[i])
				{
					return false;
				}
			}
			return false;
		}
    }
	friend bool operator>(Queue& q1, Queue& q2)
	{
		return !(q1 < q2);
	}
	friend ostream& operator<<(ostream& out, Queue& q)
	{
		for (int i = 0; i < q.size; i++)
		{
			out << q.array[i] << " ";
		}
		return out;
	}
	friend istream& operator>>(istream& in, Queue& q)
	{
		int item;
		in >> item;
		q.Enqueue(item);
		return in;
	}
};

