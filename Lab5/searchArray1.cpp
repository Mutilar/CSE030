
#include <iostream>
#include <fstream>
using namespace std;

int checkArraySort(string*, int);
int binarySearchR(string*, int, int, string);

int main()
{
	ifstream file_in;
	file_in.open("words_in.txt");
	int num_lines = -1; //Last line of text file is empty string, offset with -1.
	while (file_in.eof() == false)
	{
		//Only wants to work if I call getline
		//Mathbits.com's eof explanation hints at this
		//Tried mathbit's version, didnt work for me.
		string output;
		getline(file_in,output);
		num_lines++;
	}
	file_in.close();
	file_in.open("words_in.txt");

	string* p_words = new string[num_lines];

	for (int i = 0; i < num_lines; i++)
	{
		getline(file_in, p_words[i]);
		cout << p_words[i] << ", ";
	}
	file_in.close();

	int result = checkArraySort(p_words, num_lines);

	if (result == 0)
	{
		cout << "Array not sorted!";
	}
	else
	{
		cout << "Enter an input search key: ";
		string target;
		cin >> target;

		int output = binarySearchR(p_words, num_lines, 0 , target);
		if (output == -1)
		{
			cout << "The key " << target << " was not found in the array!";
		}
		else
		{
			cout << "Found key " << target << " at index " << output << "!";
		}
	}
}

int binarySearchR(string* A, int upper, int lower, string target)
{
	int mid = (upper+lower)/2;
	if (A[mid] == target)
	{
		return mid;
	}
	else
	{
		if (lower >= upper)
		{
			 return -1;
		}
		if (A[mid] > target)
		{
			return binarySearchR(A, mid-1, lower, target);
		}
		if (A[mid] < target)
		{
			return binarySearchR(A, upper, mid+1, target);
		}
	}
}

int checkArraySort(string* A, int array_size)
{
	bool ascending = true;
	bool descending = true;
	for (int i = 1; i < array_size; i++)
	{
		if (A[i] <= A[i-1])
		{
			 ascending = false;
		}
		if (A[i] >= A[i-1])
		{
			descending = false;
		}
	}
	if (ascending)
		return 1;
	if (descending)
		return -1;
	return 0;
}
