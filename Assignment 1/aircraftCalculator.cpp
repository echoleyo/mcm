// aircraftCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    const float emptyAircraftMoment = 2751405.0;   // inch-pounds
    const float emptyAircraftWeihgt = 9021.0;      // pounds
    const float fuelMoment = 1169167.3;       // inch-pounds
    const float fullTankFuelWeight = 3618.0;  // pounds 
    const float distanceToCrew = 120.0;       // inches
    const float distanceToCargo = 345.0;      // inches
	const int maxCargoWeight = 5000;				  // pounds
    bool valid = false;
    int crewNum = 0;
    
	do {
        cout << "\nHow many crewNum member (only 1 or 2) in this journey: ";
        cin >> crewNum;
        if (crewNum == 1 || crewNum == 2) {  // validating  crew member either 1 or 2
            valid = true;	
			cout << "Good, ["<< crewNum << "] crew(s) for this journey.\n";
		}else {	
			system("cls"); // clean windows console; TODO: checking OS before clean
			cout << "Invalid number you entered. please try again only allow 1 or 2: \n";
		}
    }
    while(!valid);

	float crewWeight = 0.0;
    float weight = 0.0;
    for (int i=0; i < crewNum; i++) {  // loop for input crew weight
		bool validWeight = false;	   //set flag
		int crew = i+1;
		while(!validWeight) {
			cout << "Please enter pounds for crew[" << crew << "] bewteen 85-400: ";
			cin >> weight;
			if (weight >=85 && weight <= 400 ) {   // validating crew weight
				crewWeight += weight;			   // sum weight
				cout << "Awesome, crew[" << crew <<"] weight: " <<weight << " pound" << endl;;
				validWeight = true;   //update flag
			}
		}
	}
	cout<<fixed<<setprecision(3);   // display 3 decimal
	float centerGravity = 0.0;
	float currCrewMoment = crewWeight * distanceToCrew;
	float maxCargoMoment = maxCargoWeight * distanceToCargo;
	// print report

	cout << setw(50) << setfill('=')<<endl;
    cout << "\nCrew memeber: " << crewNum << endl;
    cout << "Total weight of crew: " << crewWeight << " pound.\n";
	//cout << setfill('_')<< setw(35) << '_' << endl;
	cout << setfill('-')<< setw(35) << '-' << endl;
	int width = 16;
	cout << left << setw(width) << setfill(' ') << "Weight(pound)";
	cout << left << setw(width) << setfill(' ') << "Center of gravity" << endl;
	cout << setfill('-')<< setw(35) << '-' << endl;
	for (int currCargoWeight=0; currCargoWeight <= 5000; currCargoWeight+=500) {  // list all cargo
		float currCargoMoment = currCargoWeight * distanceToCargo;
		centerGravity = (currCrewMoment + 
					     currCargoMoment + 
						 emptyAircraftMoment + 
						 fuelMoment) / 
						 ( crewWeight + 
						 currCargoWeight + 
						 emptyAircraftWeihgt + 
						 fullTankFuelWeight);
		cout << left << setw(width) << setfill(' ') << currCargoWeight;
		if (centerGravity >= 315) {
			cout << right<< setw(width-12) << setfill(' ') << "*";
			cout <<centerGravity<< endl;
		} else {
			cout << right << setw(width-5) << setfill(' ') << centerGravity << endl;
		}
	}
	cout << setfill('_')<< setw(35) << '_' << endl;
    system("PAUSE");
	return 0;
}