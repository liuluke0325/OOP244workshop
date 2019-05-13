/*
Author: hsueh chih liu
student number : 116131186
date:3/17/2019
milestone2
*/

#include "ErrorState.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
namespace ama {

	ErrorState::ErrorState(const char* errorMessage) {

		addOfMessage = nullptr; // prevent assignment operator deallocate garbage value
		*this = errorMessage; // use the assignment operator to copy it
	}

	ErrorState::~ErrorState() {
		delete[] addOfMessage;
		addOfMessage = nullptr;
	}

	ErrorState::operator bool() const {
		return addOfMessage == nullptr ? false : true;   // if is safe empty state(true) return false, otherwise(false) return true;
	}


	ErrorState& ErrorState::operator=(const char* pText) {

		delete[]addOfMessage; // deallocate the current dynamic array

		if (pText == nullptr || *pText == '\0')
		{
			addOfMessage = nullptr; // set to safe empty state
		}
		else {
			string str1 = pText;
			addOfMessage = new char[str1.length() + 1]; //count the length of the message(plus null terminator), allocate dynamic array
			strcpy(addOfMessage, pText);

		}
		return *this;
	}


	void ErrorState::message(const char* pText) {
		*this = pText; // valid first then copy string to current object
	}

	const char* ErrorState::message() const { 

		return *this ? addOfMessage : nullptr; // if valid return address, otherwise(invsafe empty state) return nullptr
	}

	ostream& operator<< (ostream& os, const ErrorState& src) {

		if (src) // if valid, return the address and print out
		{
			os << src.message();
		}


		return os;
	}



}//end of namestate