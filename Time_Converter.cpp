#include <iostream>
using namespace std;


int main ()
{
	int seconds = 0;
	int minutes = 0;
	int days = 0;
	int hours = 0;
	int weeks = 0;
	int min_secs = 0;
	int hours_min = 0;
	int days_hour = 0;
	int weeks_day = 0;
	
	cout << "Welcome to the second converter!" <<endl; 
	do 
	{
		cout << "Please enter an integer value that is greater than zero for the number of seconds you wish to convert: " << endl;
		cin >> seconds;
	
		if (seconds <= 0) {
		cout << "The value you entered is invalid, please try again." << endl;
		} 
	} 
	while (seconds <= 0);	
	cout << "The interger value you entered was: " << seconds << endl << endl ;
	
	if (seconds > 60) { //minutes
		minutes = (seconds/60); 
		min_secs = seconds % 60;
	}
	
	if (minutes > 60) { //hours
		hours = (minutes/60);
		hours_min = minutes % 60;
	}
	
	if (hours > 24) { //days
		days = (hours/24);
		days_hour = hours % 24;
	}
	
	if (days > 7) { //weeks
		weeks = (days/7);
		weeks_day = days % 7;
	}


	cout << "Week(s): " << weeks << endl 
		<< "Day(s): " << weeks_day << endl 
		<< "Hour(s): " << days_hour << endl 
		<< "Minute(s): " << hours_min << endl 
		<< "Second(s): " << min_secs << endl;
	
}
	

