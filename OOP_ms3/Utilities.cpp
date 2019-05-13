/*
name : hsueh chih liu
student id: 116131186
date: 3/24/2019
*/




#include "Utilities.h"
using namespace std;
namespace ama {

	double& operator+=(double& total, const Product& prod) {
		total += prod.total_cost();
		return total;

	}

	ostream& operator<<(ostream& out, const Product& prod) {

		prod.write(out, write_human);
		return out;

	}

	istream& operator>>(istream& in, Product& prod) {

		prod.read(in, 1);  // 1 == interactive mode
		return in;
	}


}