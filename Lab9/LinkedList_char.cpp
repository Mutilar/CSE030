#include "LinkedList_char.h"
#include <iostream>
using namespace std;


LinkedList_char::LinkedList_char()
{
	first = NULL;
	new_last = NULL; //NOTE:: new_last replaces all instances of "last", because "last" threw weird memory errors with the exact same code
}

LinkedList_char::~LinkedList_char()
{
	//Same as remove(), while there are items in the list, remove item
	while (isEmpty() == false)
	{
		removeFromBack();
	}
}

void LinkedList_char::insertAtBack(char valueToInsert)
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

bool LinkedList_char::removeFromBack()
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

void LinkedList_char::print()
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

bool LinkedList_char::isEmpty()
{
	return (first == NULL);
}

int LinkedList_char::size()
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

void LinkedList_char::clear()
{
	while (isEmpty() == false)
	{
		removeFromBack();
	}
}

void LinkedList_char::insertAtFront(char valueToInsert)
{
	Node* item = new Node();
	item->val = valueToInsert;
	item->next = first;
	first = item;
}

bool LinkedList_char::removeFromFront()
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
