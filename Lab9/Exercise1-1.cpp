#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

using namespace std;

int main()
{
	Stack item;
	//Checking if item is empty
	if (item.isEmpty())
	{
		cout << "Stack is EMPTY!\n";
	}
	else
	{
		cout << "Stack is NOT empty\n";
	}

	//Adding 10 elements	
	for (int i = 0; i < 10; i++)
	{
		item.push((100*(i+1)));
	}

	//Checking if item is empty
	if (item.isEmpty())
	{
		cout << "Stack is EMPTY!\n";
	}
	else
	{
		cout << "Stack is NOT empty\n";
	}

	//Printing size of Stack
	cout << "Stack has " << item.size() << " items\n";

	cout << "Stack's top is " << item.top() << "\n";
	//Printing the Stack
	cout << "Stack has the following items: {";
	item.print();
	cout << "}\n";

	//Removing 5 items
	for (int i = 0; i < 5; i++)
	{
		cout << "Popping stack: " << item.pop() << "\n";
	}

	cout << "Stack has " << item.size() << " items\n";

	cout << "Stack has the following items: {";
	item.print();
	cout << "}\n";

}
