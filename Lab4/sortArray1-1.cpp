#include <iostream>
using namespace std;

void sortArr (int, int[], int);

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
		cout << "Sort in ascending (0) or descending (1) order?";
		int order = -1;
		cin >> order;
		sortArr (order, values, array_size);
		cout << "This is the sorted array in ";
		if (order == 0) cout << "ascending order: ";
		else cout << "descending order: ";

		//OUTPUT SORTED ARRAY
		for (int i = 0; i < array_size; i++)
		{
			cout << values[i] <<  " ";
		}

	}
}

void sortArr(int order, int values[],  int size)
{
		//SORTING
		for (int i = 0; i < size; i++)
		{
			int index_of_extreme = 0;
			for (int j = 1; j < size - i; j++)
			{
				if (order == 0)
				{
					if (values[j] > values[index_of_extreme])
					{
						index_of_extreme = j;
					}
				}
				else
				{
					if (values[j] < values[index_of_extreme])
					{
						index_of_extreme = j;
					}
				}
			}
			int temp_value_holder = values[size-i-1];
			values[size-i-1] = values[index_of_extreme];
			values[index_of_extreme] = temp_value_holder;
		}
	}



