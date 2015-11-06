#include <iostream>
#include <cmath>

using namespace std;

void histogram_update(int final_grade, int histogram_range_asterisks[]);
// Calculates the number of asterisks needed for each row of the histogram given the number of students per "bin" value.

double class_average(int student_number, int grades_total);
// Calculates the average of the class given the number of students and each of their grades.

void histogram_output(int histogram_range_asterisks[]);
// Outputs a histogram of the prior calculated values, displaying the number of students whose final_grade corresponds to each of the "bin" values.

int main () {
	int final_grade = 0;
	int student_number = 1;
	int grades_total = 0;
	int average = 0;
	int histogram_range_asterisks[6] = {0}; // array which contains 6 indexed variables that will hold the number of asterisks 
										    //for each of the corresponding 6 'bin' values of the histogram (i.e. histogram_range_asterisks[5] corresponds to the number of asterisks for "90-100") 
	
	cout << "Welcome to the class average and histogram output-er!\n"
		 << "Enter a grade from 0-100% for each student. When finished, enter -1.\n\n"; // -1 is a sentinel value
	
	while (final_grade != -1){ // flag condition to exit loop: final_grade = -1
		do {
			cout << "Please enter the final grade for student " << student_number << ": ";
			cin >> final_grade;
			if (final_grade < -1 || final_grade > 100) { // input error-checking
				cout << "Invalid input. Please try again.\n";
			} else if (final_grade == -1) { // flag condition triggered
				break;
			} else {
				student_number++; 
				grades_total += final_grade; 
				histogram_update(final_grade, histogram_range_asterisks); // updates number of asterisks by one for corresponding 'bin' value
			}
		} while (final_grade < -1 || final_grade > 100); // error-checking loop
	
		cout << "You inputted " << final_grade 
			 << ".\n";
	}
	
	average = class_average((student_number-1), grades_total); // (student_number -1) because student_number = 1 initially
	cout << "\nThe class average for this list of students is: " << average
		 << ".\n\n";
	
	histogram_output(histogram_range_asterisks); // outputs histogram, ending program
	
	return 0;
}


void histogram_update(int final_grade, int histogram_range_asterisks[]) {

	if (final_grade <= 49) {
		histogram_range_asterisks[0]++;
	} else if (final_grade <= 59) {
		histogram_range_asterisks[1]++;
	} else if (final_grade <= 69) {
		histogram_range_asterisks[2]++;
	} else if (final_grade <= 79) {
		histogram_range_asterisks[3]++;
	} else if (final_grade <= 89) {
		histogram_range_asterisks[4]++;
	} else if (final_grade <= 100) {
		histogram_range_asterisks[5]++;
	}
	
	return;
	
}
	 
double class_average(int student_number, int grades_total) {
	
	double average = 0; 
	
	if (student_number == 0) { // If "-1" is inputted initially (therefore student_number parameter = 0), sets average equal to zero to avoid division by zero.
		average = 0;
	} else {
		average = round(grades_total/(static_cast<double>(student_number))); // static_cast allows for double quotient that is then rounded via the "round" function
	}
	return average;

}

void histogram_output(int histogram_range_asterisks[]) {
	
	int count = 0;
	
	cout << "*** STUDENT GRADE-RANGE HISTOGRAM ***\n\n";
	cout << "  0-49: ";
	for (count; count < histogram_range_asterisks[0]; count++) {
		cout << '*';
	}
	cout << "\n 50-59: ";
	for (count = 0; count < histogram_range_asterisks[1]; count++) {
		cout << '*';
	}
	cout << "\n 60-69: ";
	for (count = 0; count < histogram_range_asterisks[2]; count++) {
		cout << '*';
	}
	cout << "\n 70-79: ";
	for (count = 0; count < histogram_range_asterisks[3]; count++) {
		cout << '*';
	}
	cout << "\n 80-89: ";
	for (count = 0; count < histogram_range_asterisks[4]; count++) {
		cout << '*';
	}
	cout << "\n90-100: ";
	for (count = 0; count < histogram_range_asterisks[5]; count++) {
		cout << '*';
	}
	
	return;

}

