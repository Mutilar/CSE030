#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

#include "time.h"

using namespace std;

bool getTimeFromUser(Time&);
string print24Hour(Time);

int main()
{
	Time start_time, end_time;
	cout << "Enter a start time for the lecture (format is HH:MM:SS): ";
	//If formatted, continue and set values
	if (getTimeFromUser(start_time))
	{
		cout << "Enter the end time for the lecture (format is HH:MM:SS): ";
		if (getTimeFromUser(end_time))
		{
			//Print 24 hour format
			cout << "The lecture starts at " << print24Hour(start_time) << " and ends at " << print24Hour(end_time);
		}
		else
		{
			cout << "The end time entered is invalid!";
		}
	}
	else
	{
		cout << "The start time entered in invalid!";
	}


}

//There are 3 stringstreams because .str() was acting weird
string print24Hour(Time time_in)
{
	stringstream stream;
	stream << time_in.getHours();
	string hours_string = stream.str();
	if (hours_string.length() == 1)
	{
		 hours_string.insert(0,"0");	//Add 0s if number is less than 10
						// 9:2:3 --> 09:02:03
	}
	stringstream stream2;
	stream2 << time_in.getMinutes();
	string minutes_string = stream2.str();
	if (minutes_string.length() == 1)
	{
		 minutes_string.insert(0,"0");
	}
	stringstream stream3;
	stream3 << time_in.getSeconds();
	string seconds_string = stream3.str();
	if (seconds_string.length() == 1)
	{
		seconds_string.insert(0,"0");
	}
	return hours_string+":"+minutes_string+":"+seconds_string;
}

//Checking if times passed up are reasonable
bool getTimeFromUser(Time &time_in)
{
	string input = "";
	getline(cin, input);
	//Needs to be the right size (##:##:##)
	if (input.length() != 8)
	{
		return false;
	}
	//Making sure ##:##:## each index has expected value
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
	//Parsing data
	time_in.setHours(atoi(input.substr(0,2).c_str()));
	time_in.setMinutes(atoi(input.substr(3,2).c_str()));
	time_in.setSeconds(atoi(input.substr(6,2).c_str()));
	//Making sure data is reasonable
	if (time_in.getHours() < 0 || time_in.getHours() > 23)
	{
		 return false;
	}
	if (time_in.getMinutes() < 0 || time_in.getMinutes() > 59)
	{
		 return false;
	}
	if (time_in.getSeconds() < 0 || time_in.getSeconds() > 59)
	{
		return false;
	}
	return true;
}

