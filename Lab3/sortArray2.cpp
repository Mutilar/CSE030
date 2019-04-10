
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
		int number_of_swaps = 0;
		for (int i = 0; i < array_size; i++)
		{
			int index_of_min = i;

			for (int j = i+1; j < array_size; j++)
			{
				if (values[j] < values[index_of_min])
				{
					index_of_min = j;
				}
			}
			if (i != index_of_min)
			{
				number_of_swaps++;
				int temp_value_holder = values[i];
				values[i] = values[index_of_min];
				values[index_of_min] = temp_value_holder;
			}
		}

		cout << "\nThis is the sorted array in ascending order: ";
		//OUTPUT VALUES
		for (int i = 0; i < array_size; i++)
		{
			cout << values[i] << " ";
		}
		cout << "\nThe algorithm selected the minimum for the traverse of the array.";
		cout << "\nIt took " << number_of_swaps << " swaps to sort the array...";
	}
}
