#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file_in;
	file_in.open("words_in.txt");
	int num_lines = 0;
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
	}
	file_in.close();

	ofstream file_out;
	file_out.open("words_out.txt");

	for (int i = 0; i < num_lines; i++)
	{
		file_out << p_words[i] << "\n";
	}

}
