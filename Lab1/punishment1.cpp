#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the number of lines for the punishment: ";
	int number = 0;
	cin >> number;

	if (number >= 0)
	{
		for (int i = 0; i < number; i++)
		{
			cout << "I will always use object oriented programming. ";
		}
	}
	else
	{
		cout << "You have entered an incorrect value for the number of lines";
	}
	return 0;
}
