#include "date.h"

void Date::SetDateAndTime() // Get the present date 
{
	// and assign it to the data members.
	struct tm* dur; // Pointer to struct tm.
	time_t sec; // For seconds.
	time(&sec); // Get the present time.
	dur = localtime(&sec); 
	
	// Initialize a struct of
	// type tm and return a
	// pointer to it.
	day = (short)dur->tm_mday;
	month = (short)dur->tm_mon + 1;
	year = (short)dur->tm_year + 1900;
	hours = (short)dur->tm_hour;
	min = (short)dur->tm_min;
	this->sec = (short)dur->tm_sec;
}
const string& Date::GetDateAndTime() const // Return a date as string.
{
	static string dateString;
	stringstream iostream; // For conversion number -> string

	iostream << setfill('0') // and formatting.
		<< '[' << setw(2) << month << '.'
		<< setw(2) << day << '.' << year << ']'
		<< '[' << setw(2) << this->hours << ':'
		<< setw(2) << this->min << ':' << this->sec << ']';
	iostream >> dateString;
	return dateString;
}
