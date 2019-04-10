#include <iostream>
#include "LinkedList.h"
#include "Queue.h"

using namespace std;

int main()
{
	Queue item;
	//Checking if item is empty
	if (item.isEmpty())
	{
		cout << "Queue is EMPTY!\n";
	}
	else
	{
		cout << "Queue is NOT empty\n";
	}

	//Printing the front of the Queue if there is one.
	try
	{
		cout << "Queue's front is " << item.front() << "\n";
	}
	catch (int n)
	{
		cout << "Call to front() generated an exception, because the queue is empty\n";
	}

	
	cout << "ADDING VALUES\n";
	//Adding 10 elements	
	for (int i = 0; i < 10; i++)
	{
		item.enqueue((100*(i+1)));
	}

	//Checking if item is empty
	if (item.isEmpty())
	{
		cout << "Queue is EMPTY!\n";
	}
	else
	{
		cout << "Queue is NOT empty\n";
	}

	//Printing size of Queue
	cout << "Queue has " << item.size() << " items\n";

	//Printing the front of the Queue if there is one.
	try
	{
		cout << "Queue's front is " << item.front() << "\n";
	}
	catch (int n)
	{
		cout << "Call to front() generated an exception, because the queue is empty\n";
	}

	//Printing the Queue
	cout << "Queue has the following items: {";
	item.print();
	cout << "}\n";

	//Removing 11 items
	for (int i = 0; i < 11; i++)
	{
		//Dequeueing if possible
		try
		{
			cout << "Dequeueing Queue: " << item.dequeue() << "\n";
		}
		catch (int n)
		{
			cout << "Call to dequeue() generated an exception, because the queue is empty\n";
		}	
		
		//Printing the Queue
		cout << "Queue has the following items: {";
		item.print();
		cout << "}\n";	
	}

	cout << "Queue has " << item.size() << " items\n";

	cout << "Queue has the following items: {";
	item.print();
	cout << "}\n";

}
