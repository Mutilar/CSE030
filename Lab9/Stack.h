#ifndef STACK_H 
#define STACK_H

#include "LinkedList.h"

class Stack : public LinkedList 
{
    // Public Functions/Variables
    public:
        Stack(); // Constructor
        ~Stack(); // Destructor
        void push(int value);
	int pop ();
	int& top();
};

#endif

