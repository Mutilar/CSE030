#ifndef QUEUE_CHAR_H
#define QUEUE_CHAR_H

#include "LinkedList_char.h"

class Queue_char : public LinkedList_char
{
    // Public Functions/Variables
    public:
        Queue_char(); // Constructor
        ~Queue_char(); // Destructor
        void enqueue(char value);
	char dequeue();
	char& front();
};

#endif

