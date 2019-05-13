/*

name:hsueh chih liu
student id : 116131186

*/
///////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include "Data.h"
#include <cmath>
using namespace std;
namespace sict {


	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		double count = max(population, n) - min(population, n);
		cout << "Population change from 2000 to 2004 is " << setprecision(2) << fixed << count / 1000000 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		cout << "Violent Crime trend is ";
		if ((violentCrimeRate[n - 1] - violentCrimeRate[0]) > 0)
		{
			cout << "up";
		}
		else
		{
			cout << "down";
		}
		cout << endl;

		// Q3 print the GTA number accurate to 0 decimal places


		cout << "There are " << setprecision(2) << fixed << average(grandTheftAuto, n) / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << setprecision(0) << fixed << min(violentCrimeRate, n) << endl;
		cout << "The Maximum Violent Crime rate was " << floor(max(violentCrimeRate, n))<< endl;

	}
}