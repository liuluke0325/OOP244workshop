
/*

student name :hsueh chih liu
student id: 116131186

*/

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"

namespace sict {



	class Account :public iAccount {
		double CurrentBalance;

	protected:
		double balance() const;
	public:
		Account(double = 0.0);
		bool credit(double amount);
		bool debit(double amount);


	};


}

#endif