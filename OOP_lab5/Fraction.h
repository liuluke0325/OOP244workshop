// Workshop 5: operator overloading
// File: w5_in_lab.cpp
// Version: 2.0
// Date: 2019/02/20
// Author: hsueh chih liu
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////



// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H


// TODO: create namespace
namespace sict
{
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;  // a/b   a = numerator
		int denominator;// a/b   b = denominator , By convention, the denominator is expressed as a positive integer.
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
	};
} // end of namespace


#endif 