//*********************************************
// Student1 Name: Sebastian Kolosa
// Student1 Number: 20611678
//
// Student2 Name: Jesse Young
// Student2 Number: 20603164
//
// SYDE 121 Lab: 05 Assignment: 03
//
// Filename: lab0503.cpp
// Date submitted: October 30, 2015
//
// We hereby declare that this code, submitted
// for credit for the course SYDE121, is a product
// of our own efforts. This coded solution has
// not been plagiarized from other sources and
// as not been knowingly plagiarized by others.
//
// Pair Programming Work Declaration:
// Jesse Young Completed ~50% of the assignment.
// Sebastian Kolosa Completed ~50% of the assignment.
//
//*********************************************

#include <iostream>
#include <cmath>

using namespace std;


int main () {
	
	double pi = 0;
	int static_decimals = 0;
	int static_d_iteration = 0;
	int count = 0;
	double prior_pi = 0;
	
	cout.setf(ios::fixed);
	cout.precision(12);
	
	do {
		cout << "Please enter the decimal place of consistency (integer values from 1-6): ";
		cin  >> static_decimals;
		if ( static_decimals < 1 || static_decimals > 6) {
			cout << "Invalid input. Please try again.\n" << endl;
		} 
	} while (static_decimals < 1 || static_decimals > 6); //error checking user input
	

	cout << endl << " 	Term | Approximation of pi\n"; // header of the table formed in the console
	
	while ( static_d_iteration < 2) // loop that continually approximates pi (to 12 decimal places) until the (static_decimal)th decimal is consistent for three consecutive outputs
	{
		if (count % 2 == 0) {
			pi += (4.0/(1+2*count));
			cout << " 	" << count + 1 
				 << "    | ";  
			cout << pi << endl;
		} else {
			pi += -(4.0/(1+2*count));
			cout << " 	" << count + 1 
				 << "    | ";  
			cout << pi << endl;
		}
		
		if ((floor(pi*pow(10, static_decimals))) == (floor(prior_pi*pow(10, static_decimals)))) {
			static_d_iteration++;
		} else { 
			static_d_iteration = 0;
		}
		prior_pi = pi; 

		
		count++; // incrementing infinite series for pi by one for next iteration 	
	}
	cout << endl << "Thank you. Program now exiting.";
	return 0;
}

