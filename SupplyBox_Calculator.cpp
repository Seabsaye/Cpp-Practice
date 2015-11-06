#include <iostream>
using namespace std;

int main()
{
	const int PENCIL_JR_ENG = 10; //Defining Contants
	const int PEN_JR_ENG = 5;
	const int ERASER_JR_ENG = 3;
	const int PENCIL_SR_ENG = 7;
	const int PEN_SR_ENG = 5;
	const int ERASER_SR_ENG = 2;
	const int PENCIL_ADMIN = 2;
	const int PEN_ADMIN = 10;
	const int ERASER_ADMIN = 1;
	const int PENCIL_PER_BOX = 25;
	const int PEN_PER_BOX = 10;
	const int ERASER_PER_BOX = 10;
	
	double percent_jr_eng = 0.0; //Defnining Variables 
	double percent_sr_eng = 0.0;
	double percent_admin = 0.0;
	
	int total_employees = 0;
	
	int number_jr_eng = 0;
	int number_sr_eng = 0;
	int number_admin = 0;
	
	int pencil_total = 0;
	int eraser_total = 0;
	int pen_total = 0;
	
	double pencil_jr_eng = 0;
	double pencil_sr_eng = 0;
	double pencil_admin = 0;
	
	double pen_jr_eng = 0;
	double pen_sr_eng = 0;
	double pen_admin = 0;
	
	double eraser_jr_eng = 0;
	double eraser_sr_eng = 0;
	double eraser_admin = 0;
	
	double total_pencil_box = 0;
	double total_pen_box = 0;
	double total_eraser_box = 0;
	
	cout << "Welcome to the engineering-firm utensil box calcomatic!" << endl;
	bool check = true;
	do //Checks to ensure valid input
	{
		cout << "Input the total number of employees in the company: ";
		cin >> total_employees;
		cout << endl << "Input the percent of employees that are Junior Engineers" << endl << "(DO NOT INCLUDE PERCENT SIGN %): ";
		cin >> percent_jr_eng;
		cout << "Input the percent of employees that are Senior Engineers" << endl << "(DO NOT INCLUDE PERCENT SIGN %): ";
		cin >> percent_sr_eng;
		if ((total_employees <= 0)||(percent_jr_eng<0)||(percent_sr_eng<0)||(percent_sr_eng + percent_jr_eng>100)) {
			check = false;
			cout << "The value(s) entered are invalid. Please try again. \n";
		} 
	}while (check == false);

	cout << endl << "You have inputted " << percent_jr_eng << " as the total percent of Junior Engineers." << endl;
	cout << endl << "You have inputted " << percent_sr_eng << " as the total percent of Senior Engineers." << endl;
	
	
	
	number_jr_eng=((percent_jr_eng/100)*total_employees);
	number_sr_eng=((percent_sr_eng/100)*total_employees);
	
	
	number_admin = (total_employees - (number_sr_eng + number_jr_eng));
	cout<< endl << "The number of Junior Engineers in the company is: " << number_jr_eng << endl;
	cout<< endl << "The number of Senior Engineers in the company is: " << number_sr_eng << endl;
	cout<< endl << "And therefore, the number of Administrators in the company is: " << number_admin << endl << endl; //Echoing input
	
	pencil_jr_eng = PENCIL_JR_ENG * number_jr_eng;
	pen_jr_eng = PEN_JR_ENG * number_jr_eng; 
	eraser_jr_eng = ERASER_JR_ENG * number_jr_eng;
	
	pencil_sr_eng = PENCIL_SR_ENG * number_sr_eng;
	pen_sr_eng = PEN_SR_ENG * number_sr_eng; 
	eraser_sr_eng = ERASER_SR_ENG * number_sr_eng;
	
	pencil_admin = PENCIL_ADMIN * number_admin;
	pen_jr_eng = PEN_ADMIN * number_admin; 
	eraser_jr_eng = ERASER_ADMIN * number_admin;
	
	pencil_total = pencil_jr_eng + pencil_sr_eng + pencil_admin;
	pen_total = pen_jr_eng + pen_sr_eng + pen_admin;
	eraser_total = eraser_jr_eng + eraser_sr_eng + eraser_admin;
	
	total_pencil_box = pencil_total/PENCIL_PER_BOX;
	total_pen_box = pen_total/PEN_PER_BOX;
	total_eraser_box = eraser_total/ERASER_PER_BOX;
	
	cout << "A company of " << total_employees //Final Statement with output
		 << " employees, %" << percent_jr_eng
		 << " being Junior Engineers," << endl 
		 << "%" << percent_sr_eng
		 << " being Senior Engineers, and %" << percent_admin
		 << " being Administrators," << endl 
		 << "would require " << total_pencil_box
		 << " boxes of pencils, " << total_pen_box
		 << " boxes of pens, and " << total_eraser_box
		 << " boxes of erasers.";
	
	
	return 0;
	
}
