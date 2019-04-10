#include <iostream>
using namespace std;

int main()
{
	//INPUT ARRAY SIZE
	cout << "Enter the size of the array: ";
	int array_size = 0;
	cin >> array_size;
	if (array_size <= 0)
	{
		cout << "\nERROR, enter a correct size for the array";
	}
	else
	{
		int values[array_size];
		cout << "\nEnter the numbers in the array, separated by a space, and press enter: ";
		//INPUT VALUES
		for (int i = 0; i < array_size; i++)
		{
			cin>> values[i];
		}

		//SORTING
		for (int i = 0; i < array_size; i++)
		{
			int index_of_max = 0;

			for (int j = 1; j < array_size - i; j++)
			{
				if (values[j] > values[index_of_max])
				{
					index_of_max = j;
				}
			}
			int temp_value_holder = values[array_size-i-1];
			values[array_size-i-1] = values[index_of_max];
			values[index_of_max] = temp_value_holder;
		}

		cout << "This is the sorted array in ascending order: ";
		//OUTPUT VALUES
		for (int i = 0; i < array_size; i++)
		{
			cout << values[i] << " ";
		}
		cout << "\nThe algorithm selected the maximum for the traverse of the array.";
	}
}
