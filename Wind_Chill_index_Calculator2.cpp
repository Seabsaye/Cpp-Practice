#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	double wind_km = 0;
	double temp_c = 0;
	double wind_mph= 0;
	double temp_f = 0;	
	
	
	
	do 
	{
		cout << "Please enter an numeric value that is greater than zero," << endl << "for the wind speed in kilometers per hour: ";
		cin >> wind_km;
		
		cout << "Please enter an numeric value for the temperature in Celsius: ";
		cin >> temp_c;
	
		if (wind_km <= 0) {
		cout << "The value you entered for the wind speed is invalid, please try again." << endl;
		} 
	} 
	while (wind_km <= 0);	

	cout << "The value you entered for wind speed was: " << wind_km << " km/hr" << endl
		<< "The value you entered for tempreture was: " << temp_c << " Celsius" << endl ;
	
	wind_mph = (wind_km * (0.6215)); //Conversion Metric to Imperial
	temp_f = ((temp_c * (9.0/5.0)) + 32);
	
	if (wind_mph <= 4){

	} else if (wind_mph <= 45) {
		temp_f = 91.4 - (10.45 + 6.69 * sqrt(wind_mph) - 0.447 * wind_mph) * ((91.4 - temp_f)/22.0);
	} else 
		temp_f = 1.6 * temp_f - 55.0;

	temp_c = (temp_f -32) * (5.0/9.0);
	
	
	cout << "The wind-chill index today is: " << temp_c << " degrees Celsius." << endl;
}


