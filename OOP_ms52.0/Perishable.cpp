/*
name : hsueh chih liu
student id: 116131186
date: 4/7/2019
*/



#include "Perishable.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace ama {

	Perishable::Perishable() :Product('P') {

	}


	std::ostream& Perishable::write(std::ostream& out, int writeMode) const {

		Product::write(out, writeMode);
		if (!isClear() || isEmpty()) // in error mode or in  empty state
		{
			// do nothing
		}
		else if (writeMode == write_human)
		{
			out << setw(max_length_label) << right << "Expiry Date: " << expDate << endl;
		}
		else if (writeMode == write_table)
		{
			out << " " << expDate << " |";
		}
		else if (writeMode == write_condensed)
		{
			out << "," << expDate;
		}

		return out;


	}


	std::istream& Perishable::read(std::istream& in, bool interractive) {

		Date tempexpl; // temp Date to check the input
		Product::read(in, interractive);
		if (interractive)
		{

			cout << setw(max_length_label) << right << "Expiry date (YYYY/MM/DD): ";
			in >> tempexpl; // ask for the date
			if (!tempexpl.isGood()) // if error
			{
				in.setstate(ios::failbit);

				switch (tempexpl.status())
				{

				case 1: // year
					message("Invalid Year in Date Entry");
					break;


				case 2: // error_mon
					message("Invalid Month in Date Entry");
					break;

				case 3: // error_day
					message("Invalid Day in Date Entry");
					break;

				case 5: // error input
					message("Invalid Date Entry");
					break;

				}

			}

			else
			{
				expDate = tempexpl; // store the date
			}

		}
		else // non interactive mod
		{

			if (in.get() == ',') // if there is a date
			{
				in >> expDate; // get the data
			}
			else
			{
				in.ignore(1, '\n'); // if is newline discharge the \n
			}

		}
		return in;
	}



} // end of namespace