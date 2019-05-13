
/*

student name :hsueh chih liu
student id: 116131186

*/
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace sict {

	SavingsAccount::SavingsAccount(double balance, double interestRate) :Account(balance) {
		if (interestRate > 0.0)
		{
			Interest = interestRate;
		}
		else
		{
			Interest = 0.0;
		}

	}

	void SavingsAccount::monthEnd() {

		credit(balance()*(Interest / 100)); // calculates the interest earned on the current balance and credits the account with that interest
	}

	void SavingsAccount::display(ostream& out) const {

		out << "Account type: Savings" << endl;
		out << "Balance: $" << setprecision(2) << std::fixed << balance() << endl;
		out << "Interest Rate (%): " << Interest << endl;  

	}


}
