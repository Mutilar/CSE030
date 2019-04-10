#include <iostream>
using namespace std;

int main()
{
	//INPUT ARRAY SIZE
	cout<<"Enter the size of the array: ";
	int array_size = 0;
	cin >> array_size;

	if (array_size <= 0)
	{
		cout<<"\nERROR: you entered an incorrect value for the array size!";
	}
	else
	{
		int values[array_size];
		//INPUT ARRAY VALUES
		cout << "\nEnter the numbers in the array, separated by a space, and press enter: ";
		for (int i = 0; i < array_size; i++)
		{
			cin >> values[i];
		}
		//INPUT TARGET VALUE
		cout << "\nEnter a number to search for in the array: ";
		int target_number = 0;
		cin >> target_number;

		//STEP THROUGH ARRAY LOOKING FOR VALUE, BREAK WHEN IT FINDS IT
		bool found = false;

		int number_of_steps = 0;
		for (number_of_steps = 0; number_of_steps < array_size; number_of_steps++)
		{
			if (values[number_of_steps] == target_number)
			{
				found = true;
				break;
			}
		}
		//OUTPUT RESULTS
		if (found)
		{
			cout << "Found value " << target_number << " at index " << number_of_steps << ", which took " <<  number_of_steps+1 << " checks.";
			if (number_of_steps == 0)
			{
				cout << "\nWe ran into the best case scenario!";
			}
		}
		else
		{
			cout << "\nWe ran into the worst case scenario!\n";
			cout <<"The value " << target_number << " was not found in the array!";
		}
	}





}
