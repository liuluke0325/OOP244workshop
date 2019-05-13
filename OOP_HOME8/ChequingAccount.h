
/*

student name :hsueh chih liu
student id: 116131186

*/



#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include "Account.h"
#include <iostream>
namespace sict {



	class ChequingAccount : public Account {


		double transactionFee;
		double monthEndFee;

	public:
		ChequingAccount(double balance, double transFee, double monthlyFee);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream& out) const;



	};







}//end of namespace




#endif
