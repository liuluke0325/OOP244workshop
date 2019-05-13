// Workshop 6 - Class with a Resource
// w6_at_home.cpp
// Hsueh Chih Liu
// 2019/03/11
#include <iostream>
#include <cstring>
#include "Contact.h"
#include  <iomanip>
using namespace std;
namespace sict {
	Contact::Contact() { // current object to safe empty state;
		set("\0", nullptr, 0);
	}



	Contact::Contact(const char* contofname, const long long* addofphone, int numofphone) {

		int count = 0;
		int setdynamicindex = 0;// control the index of dynamic array
		if (contofname == nullptr || contofname[0] == '\0') {//if name == nullptr or empty , not valid
			set("\0", nullptr, 0); //set in safe empty state
		}
		else {

			for (int i = 0; i < numofphone; i++)  // count the valid phone num
			{
				if (isphonevalid(addofphone[i]))
				{
					count++;
				}
			}
			set(contofname, count); //store the name and store the num of valid phone number to data member
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
		return name[0] == '\0' ? true : false; // if true == isempty, false==valid data
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
				cout << setw(4) << setfill('0') << getsevennum(phonenum[i]) % 10000 << endl;
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


	Contact & Contact::operator =(const Contact& src) {

		if (this != &src) // check if two are same or not(with the same address)
		{
			set(src.name, src.numofdynamic); // shallow copy

			delete[] phonenum; //delete the current object's dynamic memory allocation
			if (src.phonenum != nullptr) //check if the source object has dynamic memory allocation or not
			{

				phonenum = new long long[numofdynamic];   // if exist, create the dynamic for current object
				for (int i = 0; i < numofdynamic; i++)
				{
					phonenum[i] = src.phonenum[i];
				}
			}
			else
			{
				phonenum = nullptr;
			}

		}

		return *this;
	}

	Contact::Contact(const Contact & src) {
		phonenum = nullptr;
		*this = src;

	}
	Contact & Contact::operator += (const long long newp) {

		if (isphonevalid(newp)) //if valid, store in the array
		{
			Contact temp;
			temp = *this;	// back up the current object
			
			numofdynamic += 1;
			delete[] phonenum;

			phonenum = new long long[numofdynamic];

			for (int i = 0; i < numofdynamic; i++)
			{
				if (i < (numofdynamic - 1))
				{
					phonenum[i] = temp.phonenum[i]; // copy from the temp
				}
				else // the last one copy from newphone
				{
					phonenum[i] = newp;
				}
			}


		}
		return *this;

	}

	//set name, phone, num
	void Contact::set(const char* sname, long long* sphone, int snum) {
		set(sname, snum);
		phonenum = sphone;


	}

	//set name and num
	void Contact::set(const char* sname, int snum) {
		strncpy(name, sname, max_name_size - 1); // store the name
		name[max_name_size - 1] = '\0';
		numofdynamic = snum;

	}







}//end of namespace