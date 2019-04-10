#include <iostream>
#include "LinkedList_char.h"
#include "Stack_char.h"

using namespace std;

int main()
{
	Stack_char item;

	cout << "isEmpty()\t";
	if (item.isEmpty()) cout <<"true\t";
	else cout << "false\t";
 	item.print();
	cout << "\npush(A)\t\t\t"; item.push('A'); item.print();

	cout << "\npush(Y)\t\t\t"; item.push('Y'); item.print();

	cout << "\nsize()\t\t" << item.size() << "\t"; item.print();

	cout << "\npop()\t\t" << item.pop() << "\t"; item.print();

	cout << "\nisEmpty()\t";
	if (item.isEmpty()) cout <<"true\t";
	else cout << "false\t";
 	item.print();
	
	
	cout << "\npush(D)\t\t\t"; item.push('D'); item.print();

	cout << "\ntop()\t\t" << item.top() << "\t"; item.print();

	cout << "\npush(T)\t\t\t"; item.push('T'); item.print();

	cout << "\npop()\t\t" << item.pop() << "\t"; item.print();


}
