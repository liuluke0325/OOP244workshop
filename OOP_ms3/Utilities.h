/*
name : hsueh chih liu
student id: 116131186
date: 3/24/2019
*/

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H

#include "Product.h"
#include <iostream>
namespace ama {

	double& operator+=(double& total, const Product& prod);
	std::ostream& operator<<(std::ostream& out, const Product& prod);
	std::istream& operator>>(std::istream& in, Product& prod);
}

#endif // !AMA_UTILITIES_H

