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

}




#endif 