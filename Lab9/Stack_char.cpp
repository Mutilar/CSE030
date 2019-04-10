#include "Stack_char.h"
#include <iostream>
using namespace std;


Stack_char::Stack_char()
{
}

Stack_char::~Stack_char()
{
}

void Stack_char::push(char value)
{
	insertAtBack(value);
}

char Stack_char::pop()
{
	if (!isEmpty())
	{
		char value = new_last->val;
		removeFromBack();
		return value;
	}
	return -1;
}

char& Stack_char::top()
{
	return (new_last->val);
}
