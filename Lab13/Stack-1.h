#ifndef STACK_H 
#define STACK_H

#include "LinkedList.h"

template<class T>
class Stack : public LinkedList<T>
{
    // Public Functions/Variables
    public:
        Stack(); // Constructor
        ~Stack(); // Destructor
        void push(T value);
	T pop();
	T& top();
};

//Functions
template<class T>
Stack<T>::Stack()
{
}
template<class T>
Stack<T>::~Stack()
{
}
template<class T>
void Stack<T>::push(T value)
{
	LinkedList<T>::insertAtFront(value);
}
template<class T>
T Stack<T>::pop()
{
	if (!LinkedList<T>::isEmpty())
	{
		T value = LinkedList<T>::first->val;
		LinkedList<T>::removeFromFront();
		return value;
	}
	return -1;
}
template<class T>
T& Stack<T>::top()
{
	return (LinkedList<T>::first->val);
}



#endif

