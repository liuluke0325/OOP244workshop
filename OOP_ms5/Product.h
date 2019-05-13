/*
name : hsueh chih liu
student id: 116131186
date: 4/7/2019
*/


#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include "ErrorState.h"
#include <iostream>
#include "iProduct.h"
namespace ama {




	class Product :public iProduct {

		const char typeOfProduct;
		char productSKU[max_length_sku + 1];
		char productUnit[max_length_unit + 1];
		char * pNameOfProduct;
		int qtyProductOhHand;
		int qtyProductNeed;
		double priceBeforeTax;
		bool taxableStatus; //  true if the product is taxable.
		ErrorState errorState; // An ErrorState object that holds the error state of the Product object.
		void set(const char*, const char*, const char*, double, int, int, bool); // to set the attribute
		int lengthOfString;
	protected:
		void message(const char* pText);
		bool isClear() const;

	public:
		Product(const char = 'N');
		Product(const char*, const char*, const char*, double = 0.0, int = 0, int = 0, bool = true);
		Product(const Product&); //copy constructor
		~Product();
		Product& operator=(const Product&);
		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator> (const char* sku) const;
		bool operator> (const iProduct& other) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		const char* name() const;
		double total_cost() const;
		bool isEmpty() const;
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;
	};

}

#endif // !AMA_PRODUCT_H
