// dilution.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <cmath>
#include <iomanip>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int gpl = 0;
	float gRate = 0.0;
	float dilution;
	const float low = 0.2;
	const float high = 0.7;
	const float lowDilution = 0.35;
	const float highDilution = 0.45;

	cout << "Please enter an number in between 25 to 75 and divisible by 5 " << endl;
	cin >> gpl;
	if ( 25 > gpl || gpl > 75 || gpl%5 != 0){  // validate user input gram per liter.
		cout << "Wrong number entered\nPlease enter an number in between 25 to 75 and divisible by 5.\n";
		system("PAUSE");
		return -1;
	} 

	cout << "Please enter an float number in between 0.2 to 0.7 exclusive 0.2 and 0.7" << endl;
	cin >> gRate;   // user input

	if ( low < gRate && gRate < high){   // validate user input growth rate.
		cout << "Entered number is valid." << endl;;
	} else {
		cout << "Invalid rate entered\nPlease enter an float number in between 0.2 to 0.7 exclusive 0.2 and 0.7\n";
		system("PAUSE");
		return -2;
	}

	int saturation;
	saturation = 2 + rand()%5;		// randome generate int between 2 to  7
	cout<<fixed<<setprecision(3);   // display 3 decimal
	float div_res = (float)saturation / (saturation + gpl);  // cast divide result to float
	cout << "Saturation: " << saturation << endl;
	cout << "Growth rate: " << gRate << endl;

	dilution = gRate * ( 1 - sqrt(div_res));
	cout << "Dilution: " << dilution << endl;

	if ( lowDilution < dilution && dilution < highDilution ) {
		cout << "Kinetic parameters are acceptable." << endl;
	} else {
		cout << "Kinetic parameters are not acceptable." << endl;
	}

	system("PAUSE");
	return 0;
}