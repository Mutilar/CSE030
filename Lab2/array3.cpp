#include <iostream>

using namespace std;

int main()
{
	//Ask for size of square array (between 1 and 10)
	cout << "Enter the size of a 2D array: ";

	int array_size = 0;
	cin >> array_size;
	if (array_size < 1)
		 cout << "ERROR: you entered an incorrect value for the array size!";
	else if (array_size > 10)
		cout << "ERROR: your array is too large! Enter 1 to 10";
	else
	{
		//2D array
		int value[array_size][array_size];

		//counter for number of negative values inputted
		int number_negatives = 0;

		//Ask for input for each row, nested loop to fill entire array
		for (int i = 0; i < array_size; i++)
		{
			cout << "\nEnter the values in the array for row " << i+1 << ", separated by a space, and press enter: ";

			for (int j = 0; j < array_size; j++)
			{
				cin >> value[i][j];
				if (value[i][j] < 0) number_negatives++;
			}
		}

		if (number_negatives > 0)
			cout << "There are " << number_negatives << " negative values!";
		else
			cout << "All values are non-negative!";



	}

}
