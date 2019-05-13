
/*

student name :hsueh chih liu
student id: 116131186

*/


#include "Account.h"

namespace sict {


	Account::Account(double balance) {
		if (balance > 0.0) { // check balance valid 
			CurrentBalance = balance;
		}
		else {
			CurrentBalance = 0.0;
		}


	}



	bool Account::credit(double amount) {
		bool check = false;
		if (amount > 0.0)
		{
			CurrentBalance += amount;
			check = true; // success
		}

		return check;
	}

	bool Account::debit(double amount) {
		bool check = false;
		if (amount > 0.0 && !(amount > CurrentBalance)) {
			CurrentBalance -= amount;
			check = true; // success
		}
		return check;
	}

	double Account::balance() const {

		return CurrentBalance;

	}






}