#pragma once
#ifndef _LOG_
#define _LOG_

#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>
#include <ostream>
#include <cstdio>
#include "cctype"
#include "conio.h"
#include <cstdlib>
#include <iomanip>
using namespace std;

static const unsigned short t10 = 10000;
enum Errors
{
	write_error = -1,
	read_error = -2,
	erase_content_error = -3
};

class Log // is an object
{
private:
	string header = "\t\t* * * LOG IS GOING * * *\n\n";
	bool status;
	string log_file_name;

	// returns date and time string in format [mm.dd.yyyy][hh:mm:ss]
	const string& GetDateAndTime() const;

	// returns current PC geolocation
	string GetLocation();

	// returns log file writing status of string in format ["OK"] or ["FAIL"]
	string GetStatus();

	// TODO(Arkdiy): create a function const string& GetLocation() const; that returns const string& location in format ["UKR"] or ["US"], so on.

	// TODO(Arkdiy): create a function const string& GetStatus() const that returns current logger status in format ["OK"] or ["FAIL"]

public:
	// Default constructor
	Log();

	//	Writes a log -- formatted string as follows:
	//	[curr. date][curr. time][location][status "OK" or "FAIL"]
	//	
	//	Example:
	//	[01.08.2020][01:45:20][UKR][OK]
	bool MakeLog();

	// eraze all data in file "log.txt"
	void ClearLog();

	// setup new log file name
	bool SetupFileName();
};
#endif // _LOG_
