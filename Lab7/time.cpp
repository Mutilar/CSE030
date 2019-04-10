#include "time.h"

//Constructors
Time::Time()
{
}
Time::Time(int hour, int minute, int second)
{
	hours = hour;
	minutes = minute;
	seconds = second;
}
//Destructor
Time::~Time()
{
}

//Accessors
int Time::getHours()
{
	return hours;
}
int Time::getMinutes()
{
	return minutes;
}
int Time::getSeconds()
{
	return seconds;
}
//Mutators
void Time::setHours(int in)
{
	hours = in;
}
void Time::setMinutes(int in)
{
	minutes = in;
}
void Time::setSeconds(int in)
{
	seconds = in;
}
