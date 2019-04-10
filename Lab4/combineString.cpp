#include <iostream>
using namespace std;

string combineStr(string, int);

int main()
{
	string value;
	int number;
	while (true)
	{
		cout << "\nEnter a string: ";
		cin >> value;
		cout << "\nEnter a number of times: ";
		cin >> number;
		if (number <= 0) break;
		else
		{
			cout << "The resulting string is: " + combineStr(value,number);
		}
	}
}

string combineStr(string string_in, int number_repetitions)
{
	string string_out = "";
	for (int i = 0; i < number_repetitions; i++)
	{
		string_out += string_in;
	}
	return string_out;
}
