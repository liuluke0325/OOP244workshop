/*
name : hsueh chih liu
student id: 116131186
date: 4/7/2019
*/


#ifndef AMA_PERISHABLE_CPP
#define AMA_PERISHABLE_CPP
#include "Date.h"
#include "Product.h"

namespace ama {

	class Perishable : public Product {
		Date expDate; // to store the expiry date
	public:
		Perishable();
		std::ostream& write(std::ostream& out, int writeMode) const;
		std::istream& read(std::istream& in, bool interractive);
	};


}
#endif // !AMA_PERISHABLE_CPP



