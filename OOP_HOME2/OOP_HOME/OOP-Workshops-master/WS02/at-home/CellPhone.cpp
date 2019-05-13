// Workshop 2 - Dynamic Memory
// Version 1.0
// Date: 24/1/2019
// Author: hsueh chih liu

// TODO: include the necessary headers
#include "CellPhone.h"
#include <iostream>
using namespace std;




// TODO: the sict namespace
// TODO: definition for display(...) 


namespace sict {

	void display(const CellPhone & cellphone) {


		cout << "Phone " << cellphone.m_model << " costs $" << cellphone.m_price << "!" << endl;



	}

	void display(const CellPhone * cellphone, int numofarray) { //finds the cheapest cell-phone in the array and prints the array information
		int cheapindex = 0; //hold the index of the cheapest array, assuming the first one is the cheapest.

		for (int i = 0; i < numofarray; i++) // find out the cheapest index
		{
			if (cellphone[i].m_price < cellphone[cheapindex].m_price) 
			{
				cheapindex = i; 
			}
		}
		cout << "------------------------------" << endl;
		cout << "Phones available at the mall:" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < numofarray; i++)
		{
			cout << i+1 << ". Phone " << cellphone[i].m_model << " costs $" << cellphone[i].m_price << "!" << endl;
		}

		cout << "------------------------------" << endl;
		cout << "The cheapest phone costs $" << cellphone[cheapindex].m_price << "." << endl;
		cout << "------------------------------" << endl;







	}


}
