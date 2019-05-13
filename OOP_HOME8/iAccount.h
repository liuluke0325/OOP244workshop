
/*

student name :hsueh chih liu
student id: 116131186

*/

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
#include <iostream>

namespace sict {

	class iAccount {
	public:
		virtual  ~iAccount() { }

		//adds a positive amount to the account balance. If the parameter is not a positive value, this function does nothing. This function returns true if the transaction was successful, false otherwise.
		virtual bool credit(double amount) = 0;

		//subtracts a positive amount from the account balance. If the parameter is not a positive value or if the parameter is bigger than the balance, this function does nothing. This function returns true if the transaction was successful, false otherwise.
		virtual bool debit(double amount) = 0;

		//debits any applicable monthly fees for the account
		virtual void monthEnd() = 0;

		//inserts account information into the parameter.
		virtual void display(std::ostream& out) const = 0;
	};

	iAccount* CreateAccount(const char* type, double balance);

}//end of namespace

#endif //SICT_IACCOUNT_H

