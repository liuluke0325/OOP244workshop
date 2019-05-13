
/*

student name :hsueh chih liu
student id: 116131186

*/


#ifndef SICT_SAVINGACCOUNT_H
#define SICT_SAVINGACCOUNT_H
#include "Account.h"
#include <iostream>
namespace sict {

	class SavingsAccount :public Account {
		double Interest;

	public:

		SavingsAccount(double balance, double interestRate);
		void monthEnd();
		void display(std::ostream& out) const;
	};




}

#endif