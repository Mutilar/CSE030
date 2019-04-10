#include <iostream>
#include <string>
using namespace std;

int main()
{

	//Take in a string to reverse
	cout << "Enter a string to reverse: ";

	string value = "";
	cin >> value;

	//Run through the characters in the array
	for (int i = 0; i < value.length() / 2; i++)
	{
		//Switch two characters, reversing them (from  index i to index string.length-1-i
		//Temp value, needed for swap
		char swapping_value = value[i];
		//Set right index to left
		value[i] = value[value.length()-1-i];
		//Set left index to right
		value[value.length() -1- i] = swapping_value;
	}

	//Output reversed string
	cout << "\nThe reverse of the string is: " << value;



}
