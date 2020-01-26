#include "log.h"
#include "date.h"

// default constructor
Log::Log() 
{
	status = true;
	cout << header; 
	SetupFileName(); 
};
// returns date and time string in format [mm.dd.yyyy][hh:mm:ss]
const string& Log::GetDateAndTime() const
{
	Date current_date;
	return current_date.GetDateAndTime();
}
// returns current PC geolocation
string Log::GetLocation()
{
	const string location("[UKR]");
	return location;
}
// returns log file writing status of string in format ["OK"] or ["FAIL"]
string Log::GetStatus() 
{
	return status ? "[OK]" : "[FAIL]";
}
// Write a log with formatted string
bool Log::MakeLog()
{
	ofstream log_file(log_file_name, ios::out | ios::app);

	// check on errors with file
	bool has_errors = (!log_file.is_open() || log_file.fail() ||
		!(log_file << GetDateAndTime() << GetLocation() << GetStatus() << '\n'));
	status = has_errors ? false : true;

	return status;
};
// eraze all log data
void Log::ClearLog()
{
	// TODO: eraze all data in the log.txt
	ofstream log_file(log_file_name, ios::trunc);

	if (!log_file.is_open() || log_file.fail())
	{
		cout << "Erasing file's content failed.\n";
		exit(erase_content_error);
	}

	log_file.clear();
};
bool Log::SetupFileName()
{ 
	// no previos input
	cin.sync(); cin.clear();

	// 's' as "new_out_file_name"
	string s;
	cout << "Write new output file name: ";
	cin >> s;
	
	// check for errors
	if (cin.fail() || s.empty() || s.size() > 512)
		return false;

	log_file_name = s; 

	return true;
}
