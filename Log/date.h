#pragma once
#include "log.h"

class Date
{
private:
	short month, day, year,
		hours, min, sec;
	void SetDateAndTime();	// Sets the current date
public:
	Date() { SetDateAndTime(); };	// Default constructor

	// returns date and time string in format [mm.dd.yyyy][hh:mm:ss]
	const string& GetDateAndTime() const;	
};
