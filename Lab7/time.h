#ifndef TIME_H
#define TIME_H

class Time
{
	//Members
	private:
		int hours;
		int minutes;
		int seconds;
	public:
		//Constructors
		Time();
		Time(int, int, int);
		//Destructors		
		~Time();
		//Accessors
		int getHours();
		int getMinutes();
		int getSeconds();
		//Mutators
		void setHours(int);
		void setMinutes(int);
		void setSeconds(int);
};


#endif
