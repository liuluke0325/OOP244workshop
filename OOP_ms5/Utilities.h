/*
name : hsueh chih liu
student id: 116131186
date: 4/7/2019
*/

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H

#include "Product.h"
#include <iostream>
#include "iProduct.h"
namespace ama {

	double& operator+=(double& total, const iProduct& prod);
	std::ostream& operator<<(std::ostream& out, const iProduct& prod);
	std::istream& operator>>(std::istream& in, iProduct& prod);
	iProduct* createInstance(char tag);
}

#endif // !AMA_UTILITIES_H

