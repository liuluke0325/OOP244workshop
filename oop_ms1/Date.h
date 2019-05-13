// Final Project - Milestone 5
// Date	2019/03/10
// Authors:	Hsueh Chih Liu
// student number: 116131186



#ifndef AMA_DATE_CPP
#define AMA_DATE_CPP

#include <iostream>

namespace ama {

	const int min_year = 2019;
	const int max_year = 2028;
	const int no_error = 0;//A date object with this status is either in a safe empty state or holds a valid date.
	const int error_year = 1; // attempted to set an invalid year for the date object.The object should be in a safe empty state.
	const int error_mon = 2;//attempted to set an invalid month for the date object.The object should be in a safe empty state.
	const int error_day = 3;  // attempted to set an invalid day for the date object.The object should be in a safe empty state.
	const int error_invalid_operation = 4; // attempted to perform an invalid operation on the date object.The object should store the same date as before the invalid operation was attempted.
	const int error_input = 5; // failed to read data from an input steam(stream data was in the wrong format).The object should be in a safe empty state.



	class Date {

		int Year;
		int Month;
		int DayOfMonth;
		int Status;
		void status(int newStatus);
		int mdays(int year, int month) const;

	public:
		Date();
		Date(int, int, int);
		int status() const;
		void clearError();
		bool isGood()const;
		Date& operator+=(int days);
		Date& operator++(); // prefix
		Date operator++(int); // postfix
		Date operator+(int days)const;
		bool operator==(const Date& rhs)const;
		bool operator!=(const Date& rhs)const;
		bool operator<(const Date& rhs)const;
		bool operator>(const Date& rhs)const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os)const;
	}; // end of class

	std::istream& operator>>(std::istream& is, Date &d);
	std::ostream& operator<<(std::ostream& os, const Date &d);










}// end of namespace

#endif 