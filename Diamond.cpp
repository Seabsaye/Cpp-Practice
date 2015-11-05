//*********************************************
// Student1 Name: Sebastian Kolosa
// Student1 Number: 20611678
//
// Student2 Name: Jesse Young
// Student2 Number: 20603164
//
// SYDE 121 Lab: 05 Assignment: 01
//
// Filename: lab0501cpp
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
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int main ()
{
	int number_of_rows, number_of_stars, number_of_spaces;
	//loop that establishes the odd number input within 3 and 19, error check in place so if a number not in that range is inputed	
	//the user is asked to input another value that makes the boolean expression false	 
		cout << "Welcome to the Manual Diamond-o-Matic!\n" << endl;
	do {
		cout << "Please enter an odd integer value between 3 to 19 (inclusive) to construct a\n" 
		"diamond with that number of rows: ";
		cin >> number_of_rows;
		if (number_of_rows < 3 || number_of_rows  > 19 || number_of_rows % 2 == 0) {
			cout << "The value you have inputted it invalid, please try again.\n";
		}
	} while (number_of_rows < 3 || number_of_rows  > 19 || number_of_rows % 2 == 0);
	cout << "You have entered " << number_of_rows << " as the number of rows of the diamond.\n";
	system ("Pause");
	
	number_of_spaces = -(number_of_rows/2); // calculation to get the number of spaces in the diamond
	
	for(int a = 0; a < number_of_rows; a++) //main for-loop
	{
		for(int b = 0; b < abs(number_of_spaces); b++) //for-loop that establishes the amount of spaces in the diamond, continues to iterate until 										
		 	cout << " ";						       //b is equal to the absolute value of the number of spaces
		
		number_of_stars = number_of_rows - abs(number_of_spaces*2); // calculation for the amount of stars in the diamond 
		for( int b = number_of_stars; b > 0; b--) //for-loop for the amount of stars in the diamond, it will continue to iterate as long
			cout << "*";				          //as b(the number of stars) is bigger than 0
			
		number_of_spaces++;
		
		cout << endl;
	}
	
	cout <<"Thank you. Programming now exiting.";
	
	return 0;	
}
