// Workshop 2 - Dynamic Memory
// Version 1.0
// Date: 24/1/2019
// Author: hsueh chih liu

// TODO: header safeguards
#ifndef SICT_CELLPHONE_H
#define SICT_CELLPHONE_H



// TODO: sict namespace
namespace sict {
	struct CellPhone {// TODO: define the structure CellPhone in the sict namespace

		char m_model[32];
		double m_price;

	};
// TODO: declare the function display(...),
//         also in the sict namespace
	void display(const CellPhone & cellphone);
	void display(const CellPhone * cellphone, int numofarray);//find the cheapest cell-phone in the array and print the information
}




#endif 