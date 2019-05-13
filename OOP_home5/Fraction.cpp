// Workshop 5: operator overloading
// File: w5_in_lab.cpp
// Version: 2.0
// Date: 2019/02/25
// Author: hsueh chih liu
// Description:
// This file tests in-home section of your workshop
/////////////////////////////////////////////



// TODO: insert header files
#include "Fraction.h"
#include <iostream>
// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = -99;	// safe empty state
		denominator = -99;// safe empty state

	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int deno) {

		if (num >= 0 && deno > 0) //The data is valid if the numerator is not negative-valued and the denominator is positive-valued
		{
			numerator = num;
			denominator = deno;
			reduce(); // reduce the value;
		}
		else
		{
			*this = Fraction();

		}

	}
	// TODO: implement the max query
	int Fraction::max() const { // a private query that returns the greater of the numerator and denominator

		return  denominator > numerator ? denominator : numerator;  // assume denominator is greater

	}
	// TODO: implement the min query
	int Fraction::min() const {//a private query that returns the lesser of the numerator and denominator
		return  denominator < numerator ? denominator : numerator; // assume denominator is smaller
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int div = gcd(); // get the greatest common divisor
		numerator /= div;
		denominator /= div;

	}
	// TODO: implement the display query
	void Fraction::display() const {

		if (isEmpty())
		{
			cout << "no fraction stored";
		}
		else if (denominator == 1) {
			cout << numerator;
		}
		else
		{
			cout << numerator << "/" << denominator;
		}


	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		return denominator == -99 ? true : false; // check is safe empty or not
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction temp;// create a object in safe empty state
		if (isEmpty() == false && rhs.isEmpty() == false) // check if both of objects are not in safe empty state
		{
			temp.numerator = (numerator * rhs.denominator + rhs.numerator * denominator);
			temp.denominator = (denominator * rhs.denominator);
			temp.reduce();
		}

		return temp;
	}





	Fraction Fraction::operator*(const Fraction& cal) const {
		Fraction temp;
		if (isEmpty() == false && cal.isEmpty() == false) // check if both of objects are not in safe empty state
		{
			temp.numerator = (numerator *cal.numerator);
			temp.denominator = (denominator * cal.denominator);
			temp.reduce();
		}

		return temp;


	}

	bool Fraction::operator==(const Fraction& cal) const {

		bool temp = false; // assume is false , If either operand is in a safe empty state,   returns false.
		if (isEmpty() == false && cal.isEmpty() == false && (numerator == cal.numerator&&denominator == cal.denominator)) // check if both of objects are not in safe empty state && equal value
		{
			temp = true;
		}

		return temp;



	}

	bool Fraction::operator!=(const Fraction& cal) const {
		return isEmpty() || cal.isEmpty() ? false : !(*this == cal);
	}

	const Fraction& Fraction::operator+=(const Fraction& cal) {
		return *this=(*this+cal);
	}


	} // end of namespace