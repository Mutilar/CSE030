#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

class Queue : public LinkedList 
{
    // Public Functions/Variables
    public:
        Queue(); // Constructor
        ~Queue(); // Destructor
        void enqueue(int value);
	int dequeue();
	int& front();
};

#endif

