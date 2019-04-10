#include <iostream>
#include "LinkedList_char.h"
#include "Queue_char.h"

using namespace std;

int main()
{
	Queue_char item;

	try	
	{
		cout << "\ndequeue()\t"; cout << item.dequeue() << "\t"; 
	}
	catch (int n)
	{
		cout << "exception\t";
	}
	item.print();

	cout << "\nenqueue(D)\t\t\t"; item.enqueue('D'); item.print();

	cout << "\nenqueue(A)\t\t\t"; item.enqueue('A'); item.print();
	try
	{
		cout << "\ndequeue(t)\t"; cout << item.dequeue() << "\t\t";
	}
	catch (int n)
	{
		cout << "exception\t";
	}
 	item.print();
	
	cout << "\nsize()\t\t" << item.size() << "\t\t"; item.print();

	cout << "\nenqueue(D)\t\t\t"; item.enqueue('D'); item.print();

	cout << "\nisEmpty()\t";
	if (item.isEmpty()) cout <<"true\t";
	else cout << "false\t\t";
 	item.print();

	cout << "\nfront()\t\t" << item.front() << "\t\t"; item.print();

	cout << "\nenqueue(T)\t\t\t"; item.enqueue('T'); item.print();

	cout << "\nfront()\t\t" << item.front() << "\t\t"; item.print();

}
