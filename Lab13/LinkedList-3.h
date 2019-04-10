#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

// Representation of an element in the linked list
template<class T>
struct Node
{
    T val; // Value of the node
    Node *next; // Pointer to the next node
};

template<class T>
class LinkedList
{
    // Public Functions/Variables
    public:
        /* IMPLEMENT THESE FUNCTIONS FOR EXERCISE1 */
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(T valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();

        /* IMPLEMENT THSES FUNCTIONS FOR EXERCISE2 */
        void insertAtFront(T valueToInsert);
        bool removeFromFront();

        Node<T> *first; // Pointer pointing to the begining of the list
        Node<T> *last; // Pointer pointing to the end of the list
};

// Implement your functions here:
template<class T>
LinkedList<T>::LinkedList()
{
	first = NULL;
	last = NULL;
}
template<class T>
LinkedList<T>::~LinkedList()
{
	//Same as remove(), while there are items in the list, remove item
	while (isEmpty() == false)
	{
		removeFromBack();
	}
}
template<class T>
void LinkedList<T>::insertAtBack(T valueToInsert)
{
	//If it's the first item, set the "first" pointer as well
	if (isEmpty())
	{
		Node<T>* item = new Node<T>();
		item->val = valueToInsert;
		item->next = NULL;
		last = item;
		first = item;
	}
	else
	{
		Node<T>* item = new Node<T>();
		item->val = valueToInsert;
		item->next = NULL;
		last->next = item;		
		last = item;
	}

}
template<class T>
bool LinkedList<T>::removeFromBack()
{
	if (isEmpty() == false)
	{
		Node<T>* item = first;
		//If there is only one item, remove it and set first pointer == null
		if (item->next == NULL)
		{
			delete item;
			first = NULL;
			last = NULL;
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
			last = item;
		}
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
void LinkedList<T>::print()
{
	//Run through all items, and print them
	if (isEmpty() == false)
	{
		Node<T>* pointer = first;
		cout << pointer->val;
		pointer = pointer->next;
		while (pointer != NULL)
		{
			cout << ", " << pointer->val;
			pointer = pointer->next;
		}
	}
}
template<class T>
bool LinkedList<T>::isEmpty()
{
	return (first == NULL);
}
template<class T>
int LinkedList<T>::size()
{
	
	int count = 0;
	Node<T>* pointer = first;
	while (pointer != NULL)
	{
		count++;
		pointer = pointer->next;
	}
	return count;
}

template<class T>
void LinkedList<T>::clear()
{
	while (isEmpty() == false)
	{
		removeFromBack();
	}
}
template <class T>
void LinkedList<T>::insertAtFront(T valueToInsert)
{
	Node<T>* item = new Node<T>();
	item->val = valueToInsert;
	item->next = first;
	first = item;
}
template <class T>
bool LinkedList<T>::removeFromFront()
{
	//Can't remove if empty
	if (isEmpty())
	{
		return false;
	}
	else
	{
		Node<T>* old = first;
		first=first->next;
		delete old;
		return true;
	}	
}





#endif

