#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int value = 0;
	int product = 0;
	int answer = 0;
	int multiple_1 = 0;
	int multiple_2 = 0;
	int counter = 0;
	int question_num = 0;
	
	cout << "Welcome to the Multiplication Educator!\n"
		 << "If you wish to exit the program, enter the value \"-1\" when asked for an answer.\n";
	
	
	while (product != -1) { //Loop iterates, producing multiplication questions until user inputs "-1" as "answer"
	// -1 is a exit on flag condition, "answer" being the flag variable
		do {
	
			multiple_1 = rand() % 10;
			multiple_2 = rand() % 10;
	
			cout << "What is the product of " << multiple_1
		 	   	 << " and " << multiple_2 
		 		 << " ?" << endl;
			question_num ++;
			cin >> product;
			answer = (multiple_1 * multiple_2);
			if (answer == product) {
				counter += 1; //Counts the amount of first try correct answers
				cout << "Congratulations, you're correct!" << endl
					 << "Try another!" << endl;
			}
		
		} while (product == answer);
	
	
		if ((product != answer) && (product != -1)) { //loop iterates until user gets correct answer or inputs "-1" to exit
			do {
				cout << "Sorry, you are incorrect. Please try again." << endl
			    	 << "What is the product of " << multiple_1
					 << " and " << multiple_2 
		 			 << " ?" << endl;
			
				cin >> product;
				
			} while ((product != answer) && (product >= 0 || product < -1));
		}
		
		if (product >= 0) {
			cout << "Congratulations, you're correct!" << endl
				 << "Try another!" << endl;
		}
	}
	cout << "You got " << counter // Once "-1" entered, code states the number of correct answers on the first try
		 << " questions right on the first try!" << endl
		 << "This is out of " << (question_num -1) << " total questions attempted." //Subract one from the total question counter as to not count the question answered by the exit flag. 
		 << endl << "Thank you. Goodbye."; 
}
