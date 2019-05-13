/*
name : hsueh chih liu
student id: 116131186
date: 4/7/2019
*/


#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H

#include "iProduct.h"
#include "Perishable.h"

namespace ama {




	class AmaApp {

		char m_filename[256]; //Holds the name of the text file used to store the product information.
		iProduct * m_products[100];// An array of iProduct pointers
		int m_noOfProducts; //Number of products

		AmaApp(const AmaApp&) = delete;
		AmaApp& operator=(const AmaApp&) = delete;
		void pause() const;
		int menu() const;
		void listProducts() const;
		void loadProductRecords();
		void saveProductRecords() const;
		iProduct* find(const char* sku) const;
		void addQty(iProduct* product);
		void addProduct(char tag);
		void createBar(int) const; // to create -----

	public:
		AmaApp(const char *);
		~AmaApp();
		int run();
	};

}//namespace

#endif // !AMA_AMAAPP_H
