#include <iostream>

using namespace std;

int main ()
{	
	int salary_managers = 0;
	int salary_managers_total = 0;
	int salary_hourlyworkers = 0;
	int salary_hourlyworkers_ot = 0;
	int salary_hourlyworkers_total = 0;
	int salary_commissionworkers_total = 0;
	int salary_pieceworkers_total = 0;
	int employee_choice = 0;
	int number_managers = 0;
	int number_hourlyworkers = 0;
	int number_commissionworkers = 0;
	int number_pieceworkers = 0;
	int hourlyworker_wage = 0;
	int hourlyworker_hours = 0;
	int commissionworker_sales = 0;
	int items_produced = 0;
	int money_per_item = 0;
	int number_employees_total = 0;
	int salary_employees_total = 0;
	char choice;
	enum employee {MANAGERS = 1, WORKERS_HOURLY, WORKERS_COMMISSION, PIECEWORKERS}; // setting the variables that the user will work with
	
	cout << "Welcome to the Employee-Managing Table producer!\n" << endl;
	do {
		do {
			cout << "Enter 1 for a manager, 2 for a hourly worker,\n" << "3 for a commission worker, or 4 for a pieceworker: ";
			cin >> employee_choice;
			switch (employee_choice) {
				case MANAGERS:{ // algorithm for manager salary 
					cout << "You entered " << employee_choice << "." << endl;
					cout << "Please enter the weekly salary for this manager: $";
					cin >> salary_managers;
					cout << "You entered $" << salary_managers << " as the weekly salary.\n";
					number_managers++;
					salary_managers_total += salary_managers;
					break;
				}
				case WORKERS_HOURLY: // algorithm for hourly worker salary
					cout << "You entered " << employee_choice << "." << endl;
					cout << "Please enter the hourly wage for this hourly worker: $";
					cin >> hourlyworker_wage;
					cout << "And the hours worked in a week: ";
					cin >> hourlyworker_hours;
					cout << "You entered $" << hourlyworker_wage << " for the hourly wage\n"
						 << "and " << hourlyworker_hours << " for the hours worked.\n";
					if (hourlyworker_hours >40)
					{
						salary_hourlyworkers_ot = (hourlyworker_hours - 40)*(hourlyworker_wage*1.5);
						salary_hourlyworkers_total += salary_hourlyworkers_ot + (hourlyworker_wage*40);
					}
					else 
					{
						salary_hourlyworkers_total += hourlyworker_wage*hourlyworker_hours;
					}
					number_hourlyworkers++;
					break;
				case WORKERS_COMMISSION: // algorithm for commission worker salary
					cout << "You entered " << employee_choice << "." << endl;
					cout << "Please enter the gross weekly sales for this commission worker: $";
					cin >> commissionworker_sales;
					cout << "You entered $" << commissionworker_sales << " as the amount in sales that\n" 
						 << "this commission worker made this week.\n";
					salary_commissionworkers_total += 200 + (commissionworker_sales*0.066);
					number_commissionworkers++;
					break;
				case PIECEWORKERS: // algorithm for pieceworker salary
					cout << "You entered " << employee_choice << "." << endl;
					cout << "Please enter the amount of items produced by this pieceworker: ";
					cin >> items_produced;
					cout << "and the fixed payment per item: ";
					cin >> money_per_item;
					cout << "You entered " << items_produced
						 << " as the number of items produced,\n" << "and $" 
						 << money_per_item << " as the fixed payment per item.\n ";
					salary_pieceworkers_total += items_produced*money_per_item;
					number_pieceworkers++;
					break;
				default: // error check: if user inputs any integer that isn't 1-4
					cout << "Invalid input. Please try again.\n"; 
			}
		} while (employee_choice < 1 || employee_choice > 4); // error check loop
		cout << "Would you like to find another employee's salary?\n" << "(enter Y for \"yes\" or N for \"no\"): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y'); // "ask-before-iterating" mechanism to have values inputted by user as long as he/she writes "Y" or "y" 
	
	number_employees_total = number_pieceworkers + number_commissionworkers + number_hourlyworkers + number_managers; // expression for the total number of employees
	salary_employees_total = salary_pieceworkers_total + salary_commissionworkers_total + salary_hourlyworkers_total + salary_managers_total; // expression for the total salary of all of the employees
	
	cout <<endl << endl
		 << "                     |                     |" << endl
		 << "                     | Number of Employees |   Salary " << endl // source code for output data table that contains calculated values
		 << "                     |                     |" << endl
		 << " --------------------------------------------------------" << endl
		 << "                     |                     |" << endl
		 << "       Managers      |          " << number_managers << "          |   " << salary_managers_total << endl
		 << "                     |                     |" << endl
		 << " --------------------------------------------------------" << endl
		 << "                     |                     |" << endl
		 << "    Hourly workers   |          " << number_hourlyworkers << "          |   " << salary_hourlyworkers_total << endl
		 << "                     |                     |" << endl
		 << " --------------------------------------------------------" << endl
		 << "                     |                     |" << endl
		 << "  Commission Workers |          " << number_commissionworkers << "          |   " << salary_commissionworkers_total << endl
		 << "                     |                     |" << endl
		 << " --------------------------------------------------------" << endl
		 << "                     |                     |" << endl
		 << "     Pieceworkers    |          " << number_pieceworkers << "          |   " << salary_pieceworkers_total << endl
		 << "                     |                     |" << endl
		 << " --------------------------------------------------------" << endl
		 << "                     |                     |" << endl
		 << "        TOTAL        |          " << number_employees_total << "          |   " << salary_employees_total << endl
		 << "                     |                     |" << endl;

	return 0;
}



