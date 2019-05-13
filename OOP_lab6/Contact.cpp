
// Workshop 6 - Class with a Resource
// w6_in_lab.cpp
// hsueh chih liu
// 2019/03/07
#include <iostream>
#include <cstring>
#include "Contact.h"
#include  <iomanip>
using namespace std;
namespace sict {
	Contact::Contact() { // current object to a safe empty state;
		name[0] = '\0';
		phonenum = nullptr;
		numofdynamic = 0;

	}

	Contact::Contact(const char* contofname, const long long* addofphone, int numofphone) {
		
		int count=0;
		int setdynamicindex=0;// control the index of dynamic array
		if (contofname == nullptr || contofname[0] == '\0') {//if name == nullptr or empty , not valid
			*this = Contact();
		}
		else {

			strncpy(name, contofname, max_name_size-1); // store the name
			name[max_name_size-1] = '\0';

			for (int i = 0; i < numofphone; i++)  // count the valid phone num
			{
				if (isphonevalid(addofphone[i]))
				{
					count++; 
				}
			}
			numofdynamic = count; // store the num of valid phone number to data member
			phonenum = new long long[numofdynamic]; // create dynamically memory array for valid num
			for (int i = 0; i < numofphone; i++)
			{
				if (isphonevalid(addofphone[i])) { // check valid
					phonenum[setdynamicindex] = addofphone[i]; // if valid store the phone numbers
					setdynamicindex++;
				}
			}

		}
	}



	int Contact::countdigits(const long long num) { // count the digits of numbers
		long long temp = num;
		int count = 0;
		while (temp > 0) {
			temp /= 10;
			count++;
		}
		return count;
	}

	Contact::~Contact() {
		delete[] phonenum;
		phonenum = nullptr;
	}

	bool Contact::isEmpty() const {
		return phonenum == nullptr ? true : false; // if true == isempty, false==valid data
	}

	void Contact::display() const {
		if (isEmpty()) {// if true == safe empty state
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << name << endl;

			for (int i = 0; i < numofdynamic; i++)
			{
				cout << "(+" << getcountrycode(phonenum[i]) << ") " << getareacode(phonenum[i]) << " " << getsevennum(phonenum[i]) / 10000 << "-";
				cout <<setw(4)<< setfill('0')<< getsevennum(phonenum[i]) % 10000 << endl;
			}
		}


	}

	long long Contact::getareacode(const long long addofphone)const {
		long long temp = addofphone;
		temp /= 10000000;
		return temp % 1000; // get the area digits

	}
	long long Contact::getcountrycode(long long addofphone) const {
		long long temp = addofphone;
		return temp /= 10000000000;
	}

	long long Contact::getsevennum(const long long addofphone)const {
		return addofphone % 10000000; //return seven digits
	}

	bool Contact::isphonevalid(const long long countnum) {
		return (countdigits(getcountrycode(countnum)) >= 1 && countdigits(getcountrycode(countnum)) <= 2 && countdigits(getareacode(countnum)) == 3 && countdigits(getsevennum(countnum)) == 7) ? true : false;
	}


}//end of namespace