
#include "Queue.h"
#include <iostream>
using namespace std;

int i = 0;

Queue::Queue()
{
}
Queue::~Queue()
{
}

void Queue::enqueue(int value)
{
	insertAtBack(value);
}

int Queue::dequeue()
{
	if (isEmpty()) throw -1;
	int value = first->val;
	removeFromFront();
	return value;
}

int& Queue::front()
{
	if (isEmpty()) throw 1;
	return (first->val);
}
