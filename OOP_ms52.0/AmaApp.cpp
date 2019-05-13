/*
name : hsueh chih liu
student id: 116131186
date: 4/7/2019
*/



#include "AmaApp.h"
#include <iostream>
#include <fstream>
#include "Utilities.h"
#include <iomanip>
#include <cstring>
using namespace std;
namespace ama {

	AmaApp::AmaApp(const char * filename) {
		if (filename != nullptr && filename[0] != '\0')
		{
			strncpy(m_filename, filename, 255);
			m_filename[255] = '\0';

			for (int i = 0; i < 100; i++) //Set all the m_product elements to null
			{
				m_products[i] = nullptr;
			}

			m_noOfProducts = 0;

			loadProductRecords();
		}
	}

	AmaApp::~AmaApp() {
		for (int i = 0; i < m_noOfProducts; i++)
		{
			delete m_products[i];
		}

	}


	void AmaApp::pause() const {
		bool control = true;
		cout << "Press Enter to continue..." << endl;

		while (control)
		{
			if (cin.get() == '\n')
			{
				control = false;
			}
		}
	}

	int AmaApp::menu() const {
		int select;
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1- List products" << endl;
		cout << "2- Search product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to product quantity" << endl;
		cout << "6- Delete product" << endl;
		cout << "7- Sort products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> select;

		if (cin.fail() || select < 0 || select > 7) // check the input
		{
			select = -1;
		}
		cin.clear();
		cin.ignore(2000, '\n');
		return select;
	}
	void AmaApp::loadProductRecords() {

		int rdIndex = 0; // reading index
		iProduct * tempadd = nullptr; // to hold the temp address

		// clean the array
		if (m_noOfProducts != 0)
		{
			for (int i = 0; i < m_noOfProducts; i++)
			{
				m_products[i] = nullptr;
			}
		}

		ifstream in(m_filename);    // open source file

		if (in) { // if open successful

			while (!in.eof())
			{
				tempadd = createInstance(in.get()); // use the first word to create instance
				if (tempadd != nullptr)
				{
					m_products[rdIndex] = tempadd; // store to array;
					in.ignore(1, ','); // skip the ,
					m_products[rdIndex]->read(in, 0); // read in noninteractive mode
					rdIndex++;
				}
			}

			m_noOfProducts = rdIndex; //set number of products to readIndex
			in.close(); // close the file and ext
		}
		else
		{
			ofstream out("output.txt"); // create the new one
			out.close(); // close
		}


	}


	void AmaApp::saveProductRecords() const {

		ofstream out(m_filename); // connects 

		for (int i = 0; i < m_noOfProducts; i++)
		{
			m_products[i]->write(out, write_condensed);
			out << endl; // After each record, this function adds an end line into the file.
		}
		out.close(); // close


	}




	void AmaApp::listProducts() const {

		double TotalCost = 0.0;
		char d[4] = " | "; //delimiter | 
		createBar(96);

		// print out title
		cout << "|" << setw(4) << right << "Row" << " |";
		cout << " " << setw(max_length_sku) << right << "SKU" << d;
		cout << setw(16) << left << "Product Name";
		cout << d << setw(10) << left << "Unit";
		cout << d << setw(7) << right << "Price";
		cout << d << setw(3) << right << "Tax";
		cout << d << setw(6) << right << "QtyA";
		cout << d << setw(6) << right << "QtyN";
		cout << d << setw(10) << left << "Expiry" << " |" << endl;
		cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;
		// print out data

		for (int i = 0; i < m_noOfProducts; i++)
		{
			cout << "|" << setw(4) << right << i + 1 << " |";
			m_products[i]->write(cout, write_table);

			cout << endl;
			TotalCost += *m_products[i];
		}

		// print out foot
		createBar(96);
		cout << "|" << setw(83) << right << " Total cost of support ($): | " << setw(10) << right << setprecision(2) << fixed << TotalCost << " |" << endl;
		createBar(96);
		cout << endl;
		pause();
	}

	iProduct* AmaApp::find(const char* sku) const {
		iProduct * iPptr = nullptr; // to hold the address

		for (int i = 0; i < m_noOfProducts; i++)
		{
			if (*m_products[i] == sku)
			{
				iPptr = m_products[i];
			}
		}
		return iPptr;
	}

	void AmaApp::addQty(iProduct* product) {
		int tmpqty;
		int maxaddnum = (product->qtyNeeded() - product->qtyAvailable());

		product->write(cout, write_human);
		cout << endl << endl << "Please enter the number of purchased items: ";
		cin >> tmpqty;
		if (cin.fail())
		{
			cout << "Invalid quantity value!" << endl;
		}
		else
		{
			if (tmpqty <= maxaddnum)
			{
				*product += tmpqty;
			}
			else
			{
				*product += maxaddnum; // add to the maximum.
				cout << "Too many items; only " << maxaddnum << " is needed. Please return the extra " << tmpqty - maxaddnum << " items." << endl;
			}
			cout << endl << "Updated!" << endl;
		}
		cin.clear();
		cin.ignore();

	}


	void AmaApp::addProduct(char tag) {
		iProduct * iPptr = createInstance(tag); // create the new product
		if (iPptr != nullptr)
		{
			cin >> *iPptr;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(2000, '\n');
				cout << endl << *iPptr << endl << endl;
			}
			else
			{
				m_products[m_noOfProducts] = iPptr; // add to the last index
				m_noOfProducts++; // increment the number
				saveProductRecords();
				cout << endl << "Success!" << endl << endl;
			}
		}
	}

	int AmaApp::run() {
		bool flag = true; //control while
		char input[max_length_sku + 1]; // hold temp sku
		iProduct * iPptr = nullptr; // hold the add of object
		while (flag)
		{
			switch (menu())
			{
			case 1:
				listProducts();
				break;
			case 2:
				cout << "Please enter the product SKU: ";
				cin >> input;
				cin.ignore(2000, '\n');
				cout << endl;
				iPptr = find(input);

				if (iPptr == nullptr)
				{
					cout << "No such product!";

				}
				else
				{
					iPptr->write(cout, write_human);
				};
				cout << endl;
				pause();
				break;
			case 3:
				addProduct('N');
				break;
			case 4:
				addProduct('P');
				break;
			case 5:

				cout << "Please enter the product SKU: ";
				cin >> input;
				cin.ignore(2000, '\n');
				cout << endl;
				iPptr = find(input);
				if (iPptr == nullptr)
				{
					cout << "No such product!" << endl;
				}
				else
				{
					addQty(iPptr);

				};
				cout << endl;
				break;
			case 6:
				cout << "~~~Invalid selection, try again!~~~" << endl;
				break;
			case 7:
				cout << "~~~Invalid selection, try again!~~~" << endl;
				break;
			case 0:
				cout << "Goodbye!" << endl;
				flag = false;
				break;
			default:
				cout << "~~~Invalid selection, try again!~~~" << endl;
				pause();
			}
		}


		return 0;
	}

	void AmaApp::createBar(int num) const {
		for (int i = 0; i < num; i++)
		{
			cout << "-";
		}
		cout << endl;
	}


}//namespace

