/*

name:hsueh chih liu
student id : 116131186

*/
///////////////////////////////////////////////////
///////////////////////////////////////////////////
#ifndef SICT_DATA_H
#define SICT_DATA_H
#include <iomanip>
#include <iostream>
#include <cstring>

namespace sict {
	// These number defines the output column width for a single data field

	const int COLUMN_WIDTH = 15;

	// max returns the largest item in data
	//
	template <typename T>
	T max(const T* data, int n) {
		int largest = 0; // assume index 0 is the largest
		for (int i = 0; i < n - 1; i++)  //ex: if size 6 check 5 times
		{
			if (data[i] < data[i + 1])  //
			{
				largest = i + 1;
			}
		}
		return data[largest];
	}

	// min returns the smallest item in data
	//
	template <typename T>
	T min(const T* data, int n) {
		int smallest = 0; // assume index 0 is the smallest
		for (int i = 0; i < n - 1; i++)  //ex: if size 6 check 5 times
		{
			if (data[i] > data[i + 1])  //
			{
				smallest = i + 1;
			}
		}
		return data[smallest];
	}

	// sum returns the sum of n items in data
	//    
	template <typename T>
	T sum(const T* data, int n) {
		T sumOfArray = 0;
		for (int i = 0; i < n; i++)
		{
			sumOfArray += data[i];
		}
		return sumOfArray;
	}


	// average returns the average of n items in data
	//
	template<typename T>
	double average(const T* data, int n) {
		double count = sum(data, 5);
		return count / n;

	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		char test;
		bool boolcheck = true;
		for (int i = 0; i < n; i++)
		{
			input >> data[i];
			if (i < n - 1)
			{
				input >> test;
			}

		}

		if (input.fail())
		{
			boolcheck = false;
		}

		return boolcheck;
	}
	// display inserts n items of data into std::cout
	//
	template <typename T>
	void display(const char* name, const T* data, int n) {

		std::cout << std::setw(20) << std::right << name;
		for (int i = 0; i < n; i++)
		{

			std::cout << std::setw(15) << data[i];
		}
		std::cout << std::endl;
	}

	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,...

		if (ok) {
			// read the name  first
			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 
			input.ignore(1, ',');

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}



#endif // !SICT_DATA_H

