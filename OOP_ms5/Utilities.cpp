/*
name : hsueh chih liu
student id: 116131186
date: 4/7/2019
*/

#include "Perishable.h"
#include "Utilities.h"
using namespace std;
namespace ama {

	double& operator+=(double& total, const iProduct& prod) {
		total += prod.total_cost();
		return total;

	}

	ostream& operator<<(ostream& out, const iProduct& prod) {

		prod.write(out, write_human);
		return out;

	}

	istream& operator>>(istream& in, iProduct& prod) {

		prod.read(in, 1);  // 1 == interactive mode
		return in;
	}

	iProduct* createInstance(char tag) {

		iProduct * piProduct = nullptr;
		if (tag == 'N' || tag == 'n')
		{
			piProduct = new Product;
		}
		else if (tag == 'P' || tag == 'p')
		{
			piProduct = new Perishable;
		}
		return piProduct;
	}

}