
/*

student name :hsueh chih liu
student id: 116131186

*/


#ifndef SICT_ALLOCATOR_CPP
#define SICT_ALLOCATOR_CPP


#include "SavingsAccount.h"

#include "iAccount.h"

namespace sict {
	const double interest_rate = 5.0;
	iAccount* CreateAccount(const char* type, double balance) {


		//dynamically creates the account with the starting balance and returns its address.
		iAccount * piAccount = nullptr;

		if (type[0] == 'S')
		{
			piAccount = new SavingsAccount(balance, interest_rate);

		}

		return piAccount;

	}





}






#endif // !SICT_ALLOCATOR_CPP
