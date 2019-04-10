#include <iostream>
using namespace std;

int main()
{

	//Get length of array
	cout << "Enter the size of the array: ";

	int array_length = 0;
	cin >> array_length;

	//Make sure length is possible
	if (array_length < 1)
	{
		cout << "This is NOT an increasing array!";
	}
	else
	{
		int values[array_length];

		bool isIncreasing = true;

		cout << "\nEnter the numbers in the array, separated by a space, and press enter: ";

		//Take in array values, and check if value is larger than previous one
		for (int i = 0; i < array_length; i++)
		{
			cin >> values[i];

			if (i > 0)
			{
				if (!(values[i] > values[i-1]))
				{
					isIncreasing = false;
				}
			}
		}

		//Output whether or not array is increasing
		if (isIncreasing)
		{
			cout << "\nThis IS an increasing array!\n";
		}
		else cout << "\nThis is NOT an increasing array!\n";

		//Output array values
		for (int i = 0; i < array_length; i++)
		{
			cout << values[i] << " ";
		}

	}




}
