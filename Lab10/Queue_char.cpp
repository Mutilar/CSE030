
#include "Queue_char.h"
#include <iostream>
using namespace std;

Queue_char::Queue_char()
{
}
Queue_char::~Queue_char()
{
}

void Queue_char::enqueue(char value)
{
	insertAtBack(value);
}

char Queue_char::dequeue()
{
	if (isEmpty()) throw -1;
	char value = first->val;
	removeFromFront();
	return value;
}

char& Queue_char::front()
{
	if (isEmpty()) throw 1;
	return (first->val);
}
