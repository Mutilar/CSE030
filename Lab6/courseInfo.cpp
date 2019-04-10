
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>

using namespace std;

//Time struct
struct Time
{
	int hours;
	int minutes;
	int seconds;
}start_time, end_time;
//Courses
struct Course
{
	string name;
	int credits;
	bool majorRequirement;
	double avgGrade;
	string days;
	Time startTime;
	Time endTime;
};

bool getTimeFromUser(Time&, string);
string print12Hour(Time);


int main()
{
	//Get file
	ifstream file_in;
	file_in.open("in.txt");
	string line;
	getline(file_in, line);
	int number_classes = atoi(line.c_str());

	Course* classes = new Course[number_classes];
	//Get info from .txt file
	for (int i = 0;	i < number_classes; i++)
	{
		getline(file_in, line);
		classes[i].name = line;
		getline(file_in, line);
		classes[i].credits = atoi(line.c_str());
		getline(file_in, line);
		classes[i].majorRequirement = atoi(line.c_str());
		getline(file_in, line);
		classes[i].avgGrade =  atof(line.c_str());
		getline(file_in, line);
		classes[i].days = line;
		getline(file_in, line);
		getTimeFromUser(start_time,line);
		getline(file_in, line);
		getTimeFromUser(end_time,line);	
	}
	//Output values
	cout << "-------------------\nSCHEDULE OF STUDENT\n-------------------\n";
	for (int i = 0; i < number_classes; i++)
	{
		cout << "COURSE " << (i+1) << ": " << classes[i].name << "\n";
		if (classes[i].majorRequirement)
		{
			cout << "Note: this course is a major requirement!\n";
		}
		else
		{
			cout << "Note: this course is not a major requirement...\n";
		}
		cout << "Number of Credits: " << classes[i].credits << "\n";
		cout << "Days of Lectures: " << classes[i].days << "\n";
		cout << "Lecture Time: " << print12Hour(start_time) << " -" << print12Hour(end_time)<<"\n";
		cout << "Stat: on average students get " << classes[i].avgGrade << "% in this course.\n";
		cout <<  "-------------------\n";
	}


}

string print12Hour(Time time_in)
{
	//if past noon, shift and add modifier at the end (am/pm)
	bool am = true;
	if (time_in.hours > 12)
	{
		 am = false;
		time_in.hours -= 12;
	}
	stringstream stream;
	stream << time_in.hours;
	string hours_string = stream.str();
	if (hours_string.length() == 1)
	{
		 hours_string.insert(0,"0");	//Add 0s if number is less than 10
						// 9:2:3 --> 09:02:03
	}
	stringstream stream2;
	stream2 << time_in.minutes;
	string minutes_string = stream2.str();
	if (minutes_string.length() == 1)
	{
		 minutes_string.insert(0,"0");
	}
	stringstream stream3;
	stream3 << time_in.seconds;
	string seconds_string = stream3.str();
	if (seconds_string.length() == 1)
	{
		seconds_string.insert(0,"0");
	}
	if (am)
	{
		seconds_string+= "am";
	}
	else
	{
		seconds_string += "pm";
	}
	return hours_string+":"+minutes_string+":"+seconds_string;
}

//Checking if times passed up are reasonable
bool getTimeFromUser(Time &time_in, string input)
{
	if (input.length() != 8)
	{
		return false;
	}
	for (int i = 0; i < input.length(); i++)
	{
		if (i == 2 || i == 5)
		{
			if (input[i] != ':')
			{
				return false;
			}
		}
		else
		{
			if (!(input[i] >= '0' && input[i] <= '9'))
			{
				return false;
			}
		}
	}

	time_in.hours = atoi(input.substr(0,2).c_str());
	time_in.minutes = atoi(input.substr(3,2).c_str());
	time_in.seconds = atoi(input.substr(6,2).c_str());

	if (time_in.hours < 0 || time_in.hours > 23)
	{
		 return false;
	}
	if (time_in.minutes < 0 || time_in.minutes > 59)
	{
		 return false;
	}
	if (time_in.seconds < 0 || time_in.seconds > 59)
	{
		return false;
	}
	return true;
}

