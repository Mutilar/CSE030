#ifndef STACK_CHAR_H 
#define STACK_CHAR_H

#include "LinkedList_char.h"

class Stack_char : public LinkedList_char 
{
    // Public Functions/Variables
    public:
        Stack_char(); // Constructor
        ~Stack_char(); // Destructor
        void push(char value);
	char pop ();
	char& top();
};

#endif

