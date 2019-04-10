#include "LinkedList.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList()
{
	first = NULL;
	new_last = NULL; //NOTE:: new_last replaces all instances of "last", because "last" threw weird memory errors with the exact same code
}

LinkedList::~LinkedList()
{
	//Same as remove(), while there are items in the list, remove item
	while (isEmpty() == false)
	{
		removeFromBack();
	}
}

void LinkedList::insertAtBack(int valueToInsert)
{
	//If it's the first item, set the "first" pointer as well
	if (isEmpty())
	{
		Node* item = new Node();
		item->val = valueToInsert;
		item->next = NULL;
		new_last = item;
		first = item;
	}
	else
	{
		Node* item = new Node();
		item->val = valueToInsert;
		item->next = NULL;
		new_last->next = item;		
		new_last = item;
	}

}

bool LinkedList::removeFromBack()
{
	if (isEmpty() == false)
	{
		Node* item = first;
		//If there is only one item, remove it and set first pointer == null
		if (item->next == NULL)
		{
			delete item;
			first = NULL;
			new_last = NULL;
		}
		//Else run through list, deleting item before "null" and setting last == two before null
		else 
		{
			while ((item->next)->next != NULL)
			{
				item = item->next;
			} 
			delete item->next;
			item->next = NULL;
			new_last = item;
		}

		return true;
	}
	else
	{
		return false;
	}
}

void LinkedList::print()
{
	//Run through all items, and print them
	if (isEmpty() == false)
	{
		Node* pointer = first;
		cout << pointer->val;
		pointer = pointer->next;
		while (pointer != NULL)
		{
			cout << ", " << pointer->val;
			pointer = pointer->next;
		}
	}
}

bool LinkedList::isEmpty()
{
	return (first == NULL);
}

int LinkedList::size()
{
	//Count items in list
	int count = 0;
	Node* pointer = first;
	while (pointer != NULL)
	{
		count++;
		pointer = pointer->next;
	}
	return count;
}

void LinkedList::clear()
{
	while (isEmpty() == false)
	{
		removeFromBack();
	}
}

void LinkedList::insertAtFront(int valueToInsert)
{
	Node* item = new Node();
	item->val = valueToInsert;
	item->next = first;
	first = item;
}

bool LinkedList::removeFromFront()
{
	//Can't remove if empty
	if (isEmpty())
	{
		return false;
	}
	else
	{
		Node* old = first;
		first=first->next;
		delete old;
		return true;
	}	


}
