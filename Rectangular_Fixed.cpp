//***************************************************************************************
// Title: Rectangular.cpp
// Course: Computational Problem Solving II
// Developer: Santiago Sanchez
// Date: 9/13/2022
// Purpose: Functions of the Rectangular Number class
//***************************************************************************************

#include "Rectangular_Fixed.h"
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: Rectangular() (Constructor)
// Input:N/A
// Output: Real and imaginary are default zero
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Rectangular::Rectangular()  //No set parameters default to 0
{
	real = 0;
	imaginary = 0;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: Rectangular(double, double) (Constructor)
// Input: Two Doubles, Real and Imaginary
// Output: Real and imaginary set inputs
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Rectangular::Rectangular(double r, double a)  //Set parameters
{
	real = r; 
	imaginary = a;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: displayRectangularNumber()
// Input: N/A
// Output: Shows whole rectangular number
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Rectangular::displayRectangularNumber()  //Will show the values of the rectangular number
{
	if (imaginary >= 0) {  //Formats to positive real
		cout << fixed << setprecision(2) << setw(5) << real << " + j" << imaginary << endl;
	}
	else {
		cout << fixed << setprecision(2) << setw(5) << real << " - j" << abs(imaginary) << endl;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: setRectangularNumber(double, double) 
// Input: Two Doubles, Real and Imaginary
// Output: Real and imaginary set inputs
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Rectangular::setRectangularNumber(double rset, double iset)
{
	real = rset;
	imaginary = iset;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloading '+' Function
// Adds real and imaginary parts of numbers separately
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Rectangular Rectangular::operator+(Rectangular addVal)  //Adds two values
{
	Rectangular ans;
	ans.real = real + addVal.real;
	ans.imaginary = imaginary + addVal.imaginary;
	return ans;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloading '-' Function
// Subtracts real and imaginary parts of numbers separately
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Rectangular Rectangular::operator-(Rectangular subVal)  //Subtracts two values
{
	Rectangular ans;
	ans.real = real - subVal.real;
	ans.imaginary = imaginary - subVal.imaginary;
	return ans;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloading '==' Function
// Checks to see if the magnitudes of two rectangular numbers are equal
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool Rectangular::operator==(Rectangular equalVal)  //Determines if the rectangular numbers are equal
{
	double magnitude1;  //Comparing these
	double magnitude2;
	magnitude1 = sqrt(pow(real, 2) + pow(imaginary, 2));  //First Magnitude
	magnitude2 = sqrt(pow(equalVal.real, 2) + pow(equalVal.imaginary, 2));  //Second Magnitude
	if (magnitude1 == magnitude2) {  //If they are equal
		return true;
	}
	else {
		return false;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloading '>' Function
// Checks to see if first rect. number is greater than other
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool Rectangular::operator>(Rectangular moreVal)  //Determines if the first is greater
{
	double magnitude1;  //Comparing these
	double magnitude2;
	magnitude1 = sqrt(pow(real, 2) + pow(imaginary, 2));  //First Magnitude
	magnitude2 = sqrt(pow(moreVal.real, 2) + pow(moreVal.imaginary, 2));  //Second Magnitude
	if (magnitude1 > magnitude2) {  //If they are equal
		return true;
	}
	else {
		return false;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloading '+' Function (Increment)
// Will convert to polar, rotate the quadrant clockwise, convert back
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Rectangular Rectangular::operator+()  
{
	Rectangular incrementVal;  //Will return this at the end
	const double PI = 3.14159;
	double magPolar;  //Magnitude of polar
	double angPolar;  //Angle of polar

	magPolar = sqrt(pow(real, 2) + pow(imaginary, 2)); //Gets magnitude
	angPolar = (atan2(imaginary, real) * (180 / PI)) - 90;  //Gets the angle and rotates clockwise 90

	incrementVal.real = magPolar * cos(angPolar * (PI / 180)); //Real value
	incrementVal.imaginary = magPolar * sin(angPolar * (PI / 180));  //Imaginary value
	return incrementVal;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Overloading '-' Function (Decrement)
// Will convert to polar, rotate the quadrant clockwise, convert back
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Rectangular Rectangular::operator-()
{
	Rectangular decrementVal;  //Will return this at the end
	const double PI = 3.14159;
	double magPolar;  //Magnitude of polar
	double angPolar;  //Angle of polar

	magPolar = sqrt(pow(real, 2) + pow(imaginary, 2)); //Gets magnitude
	angPolar = (atan2(imaginary, real) * (180 / PI)) + 90;  //Gets the angle and rotates clockwise 90

	decrementVal.real = magPolar * cos(angPolar * (PI / 180)); //Real value
	decrementVal.imaginary = magPolar * sin(angPolar * (PI / 180));  //Imaginary value

	return decrementVal;
}