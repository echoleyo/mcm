// assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>


using namespace std;

//part1
float inputTime();
float inputGravity();
float inputAndValidate();
float fallingDistance(float, float);
void printResults(float, float, float);

int _tmain(int argc, _TCHAR* argv[])
{
    float time, gravity, distance;
    time = inputTime();
    gravity = inputGravity();
    cout << fixed << setprecision(2);
    distance = fallingDistance(time, gravity);
    printResults(time, gravity, distance);
    
    system("PAUSE");
	return 0;
}

float inputTime()
{
    cout << "Enter time(second): " ;
    return inputAndValidate();
}

float inputGravity()
{
    cout << "Enter gravity (m/s): " ;
    return inputAndValidate();
}

float inputAndValidate()
{
	float num;
	do {
		cin >> num;
		if (num > 0)
			break;
		cout << "\nInput can't less than zero! try again: ";
	}
	while(num <= 0);
	cout << num << " is valid entry."<< endl;
	return num;
}

float fallingDistance(float time, float g)
{
    float distance;
    distance = (g * time*time)/2;  // d =  (gt^2)/2
    return distance;
}

void printResults(float second, float g, float distance)
{
    cout << "\nSummary:" << endl;
	cout << "Time: " << second << " seconds."<<endl;
    cout << "Gravity(m/second): " << g << " m/s^2"<<endl;
    cout << "Falling distnace: " << distance << " meters" <<endl;
}



















//const float PI = 3.14159265;
//
//float inputReal();
//float inputImag();
//float inputAndValidate();
//float calResult(float, float, float &theta, int &quadrant );
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	float real, imag, magnitude, theta;
//	int quadrant = 0;	
//	real = inputReal();
//	imag = inputImag();
//	magnitude = calResult(real, imag, theta, quadrant);    
//    cout << fixed<< setprecision(2);
//	cout << "\n\nReal (X-axis): " << real << endl;
//	cout << "Imaginary (Y-axis): " << imag << endl;
//	cout << "Magnitude: " << magnitude << endl;
//	cout << "Theta: " << theta << "\370"<< endl;
//	cout << "Quadrant: " << quadrant << endl<<endl;
//    system("PAUSE");
//	return 0;
//}
//float inputReal()
//{
//    cout << "Enter real number(X axis): ";
//	return inputAndValidate();
//}
//float inputImag()
//{
//    cout << "Enter imaginary number(Y axis): ";
//	return inputAndValidate();
//}
//
//float inputAndValidate()
//{
//	float num;
//	do {
//		cin >> num;
//		if (num != 0)
//			break;
//		cout << "\nInput can't be zero! try again: ";
//	}
//	while(num == 0);
//	cout << num << " is valid entry."<< endl;
//	return num;
//}
//
//float calResult(float real, float imag, float &theta, int &quadrant )
//{
//    /* calcaulate magnitude */
//	float m;
//    m = sqrt(real * real + imag * imag);
//	
//	/* calculate theta */
//	theta = atan(abs(imag/real))*180/PI;
//	
//	/* check quadrant */
//	if (real > 0 && imag > 0)
//		quadrant = 1;
//	else if (real < 0 && imag > 0)
//		quadrant = 2;
//	else if(real < 0 && imag < 0)
//		quadrant = 3;
//	else
//		quadrant = 4;
//    return m;
//}








