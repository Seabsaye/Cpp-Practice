#include <iostream>
#include <cmath>
using namespace std;

struct complex_root { // organizing real and imaginary components of complex roots
	double real;
	double neg_imaginary;
	double pos_imaginary;
} components_of_root;

void input(double &a, double &b, double &c);
// takes in user input of the coefficients a, b, and c of the quadratic in question

void calculation(double a, double b, double c, double & root_1, double & root_2, complex_root & components_of_root, double & discriminant);
// calculates the two real or imaginary roots of the quadratic by inputting a, b, and c into the quadratic formula

void output(double a, double root_1, double root_2, complex_root components_of_root, double discriminant);
// outputs the result of the calculation function, affiliating "j" the imaginary components of any complex roots
	
int main () {
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double root_1 = 0.0;
	double root_2 = 0.0;
	double discriminant = 0.0;
	
	input(a,b,c);
	calculation(a,b,c,root_1,root_2,components_of_root,discriminant);
	output(a,root_1,root_2,components_of_root,discriminant);
	return 0;
}


void input(double &a, double &b, double &c)
{
	cout << "***ROOT FINDER***\nPlease input the three coefficients of the quadratic function.\n" << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	cout <<  "You inputted a as: " << a 
		 << endl << "You inputted b as: " 
		 << b << endl
		 << "You inputted c as: " << c;
		 return;
}

void calculation(double a, double b, double c, double & root_1, double & root_2, complex_root & components_of_root, double & discriminant) {
	discriminant = ((b*b) - (4*a*c));
	if (discriminant >= 0) { // therefore the two roots will be real
		root_1 = ( (-b + sqrt(discriminant))/(2*a) );
		root_2 = ( (-b - sqrt(discriminant))/(2*a) );
	} else { // discriminant is negative and therefore the roots are complex
		components_of_root.neg_imaginary = ((-sqrt(abs(discriminant)))/(2*a)); 
		components_of_root.pos_imaginary = ((sqrt(abs(discriminant)))/(2*a));
		components_of_root.real = (-b/(2*a));
	}
	return;
}

void output(double a, double root_1, double root_2, complex_root components_of_root, double discriminant)
{
	if(discriminant>=0)
	{
		cout << "\nThe roots of your function are: " << root_1
			 << " and " << root_2 << endl;
	}else {
		components_of_root.neg_imaginary = ((sqrt(abs(discriminant)))/(2*a));
		cout << "\nThe imaginary roots of your function are: \n\n" << components_of_root.real << " - "
			 << components_of_root.neg_imaginary << "j and "
			 << components_of_root.real << " + "
			 << components_of_root.pos_imaginary << "j.";
	}
	return;
}
