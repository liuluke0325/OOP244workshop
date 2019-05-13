
/*
name : hsueh chih liu
student id: 116131186
date: 3/27/2019
*/




#ifndef AMA_IPRODUCT_H
#define AMA_IPRODUCT_H

#include <iostream>

namespace ama {

	const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;
	const int write_condensed = 0; //signal what we want the data inserted into a stream in a condensed form.
	const int write_table = 1; // signal what we want the data inserted into a stream in a table form.
	const int write_human = 2; // signal what we want the data inserted into a stream in a human readable form.
	const double tax_rate = 0.13; // current tax rate


	class iProduct {
		public:
		virtual std::ostream& write(std::ostream& os, int writeMode) const = 0;
		virtual std::istream& read(std::istream& is, bool interractive) = 0;
		//This query returns true if the string specified in the parameter is the same as the SKU of the current instance; false otherwise.
		virtual bool operator==(const char* sku) const = 0;
		//returns the total cost of all available units of product, including tax.
		virtual double total_cost() const = 0;
		virtual int qtyNeeded() const = 0;
		virtual int qtyAvailable() const = 0;
		//This query returns the address of the string storing the name of the product.
		virtual const char* name() const = 0;
		//receives an integer identifying the number of units to be added to the available quantity of product and returns the updated number of units on hand.
		virtual int operator+=(int qty) = 0;
		// returns true if the name of the current products is greater than the name of the iProduct received as parameter
		virtual bool operator>(const iProduct& other) const = 0;
		virtual ~iProduct() {}

	};
	   	  
} // end of namespace


#endif // !AMA_IPRODUCT_H
