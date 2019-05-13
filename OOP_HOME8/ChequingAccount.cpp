
/*

student name :hsueh chih liu
student id: 116131186

*/


#include "ChequingAccount.h"
#include <iomanip>

using namespace std;
namespace sict {


	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) :Account(balance) {
		transFee > 0.0 ? transactionFee = transFee : transactionFee = 0.0;
		monthlyFee > 0.0 ? monthEndFee = monthlyFee : monthEndFee = 0.0;

	}


	bool ChequingAccount::credit(double amount) {
		bool check = false;
		if (Account::credit(amount))
		{
			Account::debit(transactionFee); // if credit successful, debit the transcation fee
			check = true;
		}

		return check;
	}

	bool ChequingAccount::debit(double amount) {
		bool check = false;
		if (Account::debit(amount))
		{
			Account::debit(transactionFee); // if debit successful, debit the transcation fee
			check = true;
		}

		return check;

	}

	void ChequingAccount::monthEnd() {
		Account::debit(monthEndFee);
	}


	void ChequingAccount::display(ostream& out) const {

		out << "Account type: Chequing" << endl;	
		out << "Balance: $" << setprecision(2) << std::fixed << balance() << endl;
		out << "Per Transaction Fee: " << transactionFee << endl;
		out << "Monthly Fee: " << monthEndFee << endl;
	}

}

