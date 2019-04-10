#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the number of lines for the punishment: ";
	int number = 0;
	cin >> number;
	cout << "\nEnter the line for which we want to make a typo: ";
	int typoLine = 0;
	cin >> typoLine;
	if (number > 0)
	{
		if (typoLine > 0 && typoLine <= number)
		{
			for (int i = 1; i <= number; i++)
			{
				if (typoLine == i) cout << "I will always use object oriented programing";
				else cout << "I will always use object oriented programming";
			}

		}

	}
	else cout << "You have entered an incorrect value for the number of lines!";

	return 0;

}
