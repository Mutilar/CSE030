#include "Stack.h"
#include <iostream>
using namespace std;


Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::push(int value)
{
	insertAtFront(value);
}

int Stack::pop()
{
	if (!isEmpty())
	{
		int value = first->val;
		removeFromFront();
		return value;
	}
	return -1;
}

int& Stack::top()
{
	return (first->val);
}
