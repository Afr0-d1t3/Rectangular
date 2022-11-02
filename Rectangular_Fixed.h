#pragma once
//***************************************************************************************
// Title: Rectangular_Fixed.h
// Course: Computational Problem Solving II
// Developer: Santiago Sanchez
// Date: 9/13/2022
// Purpose: Declarations of Rectangular class
//***************************************************************************************
class Rectangular
{
private:
	double real;
	double imaginary;
public:
	Rectangular();
	Rectangular(double r, double a);
	void displayRectangularNumber();  //Displays
	void setRectangularNumber(double rset, double aset);  //sets the numbers
	Rectangular operator+();  //Increment, will flip the quadrant clockwise
	Rectangular operator-();  //Decrement, flips quadrant counter clockwise
	Rectangular operator+(Rectangular);  //Adds two values
	Rectangular operator-(Rectangular);  //Subtracts two values
	bool operator==(Rectangular);
	bool operator>(Rectangular);
};