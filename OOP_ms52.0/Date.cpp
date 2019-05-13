/*
name : hsueh chih liu
student id: 116131186
date: 4/7/2019
*/

#include "Date.h"
#include <iomanip>
#include <string>
namespace ama {
	// returns an integer representing the status of the current object.
	int Date::mdays(int year, int mon) const {

		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	// sets the object to an empty state and the status to no_error.
	Date::Date() {

		Year = 0;
		Month = 0;
		DayOfMonth = 0;
		status(no_error);
	}

	//year, month and day (in this order).If the date specified by the arguments is correct(each number is within range), this constructor should store the arguments in the attributes and set the status to no_error
	Date::Date(int y, int m, int d) {

		if (y > max_year || y < min_year) // check data valid or not
		{
			*this = Date();
			status(error_year);
		}
		else if (m < 1 || m > 12)
		{
			*this = Date();
			status(error_mon);
		}
		else if (d < 1 || d > mdays(y, m))
		{
			*this = Date();
			status(error_day);
		}
		else
		{
			Year = y;
			Month = m;
			DayOfMonth = d;
			status(no_error);
		}
	}

	// returns an integer representing the status of the current object.
	int Date::status() const {
		return Status;
	}

	//resets the status of an object to no_error.
	void Date::clearError() {
		Status = no_error;
	}
	//A query that returns true if the object stores a valid date and is not in error mode.
	bool Date::isGood() const {
		return Year != 0 && Month != 0 && DayOfMonth != 0 && Status == no_error ? true : false;
		// not in safe enpty state == valid data && no_error== not in error mode

	}

	//sets the status of the date object to the value of the parameter.
	void Date::status(int newStatus) {
		Status = newStatus;
	}

	//A modifier that adds to the date stored by the object the number of days specified in the parameter.
	Date& Date::operator+=(int days) {
		if (!isGood()) // true if in error mode or in safe empty state
		{
			status(error_invalid_operation);
		}
		else if (DayOfMonth + days > mdays(Year, Month) || DayOfMonth + days < 1) // check the date valid or not
		{
			status(error_invalid_operation);
		}
		else
		{
			DayOfMonth += days;
		}
		return *this;
	}

	//A modifier that adds one day to the date stored by the object (prefix).
	Date& Date::operator++() {
		return *this += 1;
	}

	//A modifier that adds one day to the date stored by the object (postfix).
	Date Date::operator++(int days) {
		Date temp = *this; // save the original one
		++ *this; // current object +=1 == prefix
		return temp;// postfix, return the original one
	}

	//A query that adds to the date stored by the object the number of days specified in the parameter.
	Date Date::operator+(int days) const {
		Date temp = *this;
		temp += days;
		return temp;
	}
	//A query that returns true if two date objects store the same date (does not check status of either object).
	bool Date::operator==(const Date& rhs)const {
		return Year == rhs.Year && Month == rhs.Month && DayOfMonth == rhs.DayOfMonth ? true : false;
	}
	//A query that returns true if two date objects store different dates
	bool Date::operator!=(const Date& rhs) const {
		return !(*this == rhs);
	}
	//returns true if the current object stores a date that is before the date stored in rhs
	bool Date::operator<(const Date& rhs) const {
		return DayOfMonth < rhs.DayOfMonth ? true : false;
	}
	//returns true if the current object stores a date that is after the date stored in rhs
	bool Date::operator>(const Date& rhs) const {
		return DayOfMonth > rhs.DayOfMonth ? true : false;
	}

	// returns true if the current object stores a date that is before or equal to the date stored in rhs
	bool Date::operator<=(const Date& rhs) const {
		return !(*this > rhs ? true : false); //not smaller == bigger or equal
	}
	//returns true if the current object stores a date that is after or equal to the date stored in rhs
	bool Date::operator>=(const Date& rhs) const {
		return !(*this < rhs ? true : false); //not smaller == bigger or equal
	}
	// reads from an input stream a date in the following format: YYYY?MM?DD (three integers separated by a single character).
	std::istream& Date::read(std::istream& is) {
		int fyear; // hold the year
		int fmonth; // hold the month
		int fday; // hold the day
		char del1; // hold the first delimiter 
		char del2; // hold the second delimiter

		is >> fyear >> del1 >> fmonth >> del2 >> fday; // put the string into different variable
		Date temp(fyear, fmonth, fday); // store the input to the object, if invalid set in safe empty state
		if (is.fail()) // if input fail change the status
		{
			temp.status(error_input);
		}
		*this = temp;

		return is;
	}



	//A query that writes the date to an std::ostream object in the following format : YYYY / MM / DD
	std::ostream& Date::write(std::ostream& os) const {

		os << std::setw(4) << std::setfill('0') << Year << "/" << std::setw(2) << Month << "/" << std::setw(2) << std::right << DayOfMonth << std::setfill(' ');
		return os;

	}

	//Reads the date from the first parameter
	std::istream& operator>>(std::istream& is, Date& d) {
		d.read(is);
		return is;
	}

	//Prints the date to the first parameter
	std::ostream& operator<<(std::ostream& os, const Date& d) {
		d.write(os);
		return os;

	}


}// end of namespace


