/*
name : hsueh chih liu
student id: 116131186
date: 3/24/2019
*/



#include "Product.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;
namespace ama {

	void Product::message(const char* pText) {
		errorState.message(pText);
	}

	bool Product::isClear() const {

		return errorState.message() == nullptr ? true : false; // nullptr == no error message
	}

	Product::Product(const char character) :typeOfProduct(character) {

		set("\0", "\0", "\0", 0.0, 0, 0, true);
	}

	Product::Product(const char* srcSKU, const char *srcNofP, const char*srcUofP, double srcPri, int srcNeedofP, int srcQtyofP, bool srcTaxable) : typeOfProduct('N') {

		if (srcSKU == nullptr || srcNofP == nullptr || srcUofP == nullptr)
		{
			pNameOfProduct = nullptr;
			*this = Product(); // set to safe empty state
		}
		else
		{
			set(srcSKU, srcNofP, srcUofP, srcPri, srcNeedofP, srcQtyofP, srcTaxable);

		}

	}

	void Product::set(const char* srcSKU, const char *srcNofP, const char*srcUofP, double srcPri, int srcNeedofP, int srcQtyofP, bool srcTaxable) {
		//deep 
		string nameOfP = srcNofP;
		lengthOfString = nameOfP.length() + 1; // plus the null terminator
		pNameOfProduct = new char[lengthOfString];
		strcpy(pNameOfProduct, srcNofP);

		//shallow 
		strncpy(productSKU, srcSKU, max_length_sku);
		productSKU[max_length_sku] = '\0';
		strncpy(productUnit, srcUofP, max_length_unit);
		productUnit[max_length_unit] = '\0';
		qtyProductOhHand = srcQtyofP;
		qtyProductNeed = srcNeedofP;
		priceBeforeTax = srcPri;
		taxableStatus = srcTaxable;

	}



	Product& Product::operator=(const Product& src) {

		if (this != &src) // check self copy or not
		{
			delete[] pNameOfProduct;
			set(src.productSKU, src.pNameOfProduct, src.productUnit, src.priceBeforeTax, src.qtyProductNeed, src.qtyProductOhHand, src.taxableStatus);
		} // else do nothing
		return *this;
	}




	Product::Product(const Product& src) :typeOfProduct('N') {
		pNameOfProduct = nullptr;
		*this = src;

	}



	int Product::operator+=(int cnt) {

		if (cnt > 0)
		{
			qtyProductOhHand += cnt;
		} // else do nothing

		return qtyProductOhHand;

	}


	bool Product::operator==(const char* sku) const {

		return strcmp(productSKU, sku) == 0 ? true : false;

	}


	bool Product::operator> (const char* sku) const {

		return strcmp(productSKU, sku) > 0 ? true : false; // if >0 means s1 > s2
	}

	bool Product::operator> (const Product& src) const {

		return strcmp(pNameOfProduct, src.pNameOfProduct) > 0 ? true : false;  // if >0 means s1 > s2

	}

	int Product::qtyAvailable() const {
		return qtyProductOhHand;
	}


	int Product::qtyNeeded() const {

		return qtyProductNeed;
	}

	double Product::total_cost() const {
		return priceBeforeTax * qtyProductOhHand *(1 + (taxableStatus == true ? tax_rate : 0)); // plus tax
	}

	bool Product::isEmpty() const {
		return pNameOfProduct[0] == '\0' ? true : false; // if in safe empty state return true,

	}


	istream& Product::read(istream& in, bool interractive) {

		char insertname[30]; // temp to store the name
		int control = 1; // control switch
		char boolcheck; // temp taxable check
		double temppri;
		int temphand;
		int tempneed;
		char tempproductSKU[max_length_sku + 1];
		char tempproductUnit[max_length_unit + 1];
		bool temptaxableStatus;

		if (interractive)
		{

			do
			{
				switch (control)
				{
				case 1:
					cout << setw(max_length_label) << right << "Sku: ";
					in >> tempproductSKU;
					break;
				case 2:


					cout << setw(max_length_label) << "Name (no spaces): ";
					in >> insertname;
					break;

				case 3:
					cout << setw(max_length_label) << "Unit: ";
					in >> tempproductUnit;
					break;
				case 4:

					cout << setw(max_length_label) << "Taxed? (y/n): ";
					in >> boolcheck;
					if (boolcheck == 'y' || boolcheck == 'Y')
					{
						temptaxableStatus = true;
					}
					else if (boolcheck == 'n' || boolcheck == 'N')
					{
						temptaxableStatus = false;
					}
					else
					{
						errorState = "Only (Y)es or (N)o are acceptable!";
						in.setstate(ios::failbit);
					}

					break;
				case 5:
					cout << setw(max_length_label) << "Price: ";
					in >> temppri;
					if (temppri <= 0.0)
					{
						message("Invalid Price Entry!");
						in.setstate(ios::failbit);
					}

					break;
				case 6:

					cout << setw(max_length_label) << "Quantity on hand: ";
					in >> temphand;
					if (temphand <= 0)
					{
						message("Invalid Quantity Available Entry!");
						in.setstate(ios::failbit);
					}


					break;

				case 7:

					cout << setw(max_length_label) << "Quantity needed: ";
					in >> tempneed;
					if (tempneed <= 0)
					{
						message("Invalid Quantity Needed Entry!");
						in.setstate(ios::failbit);
					}


					break;
				}

				control++;
			} while (control < 8 && isClear());

			if (isClear()) // if no error message, set the value
			{
				delete[] pNameOfProduct;
				set(tempproductSKU, insertname, tempproductUnit, temppri, tempneed, temphand, temptaxableStatus);
			}

		}
		else
		{

			char delimiter; // to store the , 
			in.getline(productSKU, max_length_sku + 1, ','); // get up to max_length , add null terminator automatically
			in.getline(insertname, 30, ',');
			//deep copy start 
			delete[] pNameOfProduct;
			string nameOfP = insertname;
			lengthOfString = nameOfP.length() + 1; // plus the null terminator
			pNameOfProduct = new char[lengthOfString];
			strcpy(pNameOfProduct, insertname);
			//deep copy end
			in.getline(productUnit, max_length_unit + 1, ',');
			in >> priceBeforeTax >> delimiter >> taxableStatus >> delimiter >> qtyProductOhHand >> delimiter >> qtyProductNeed;
		}
		return in;
	}


	ostream& Product::write(ostream& out, int writeMode) const {
		if (!isClear())
		{
			out << errorState; // if contain errormessage, print out
		}
		else if (isEmpty()) { // if in safe empty state
			//"donothing";
		}
		else if (!isEmpty() && writeMode == write_condensed)
		{
			out << typeOfProduct << "," << productSKU << "," << pNameOfProduct << "," << productUnit << "," << priceBeforeTax << ","
				<< taxableStatus << "," << qtyProductOhHand << "," << qtyProductNeed;
		}
		else if (!isEmpty() && writeMode == write_table)
		{
			char d[4] = " | "; //delimiter | 
			string format; // format the string
			out << " " << setw(max_length_sku) << right << productSKU << d;
			out << setw(16) << left;
			if (lengthOfString > 16)
			{

				for (int i = 0; i < 16; i++)
				{
					if (i < 13)
					{
						format += pNameOfProduct[i];
					}
					else
					{
						format += ".";
					}
				}
				out << format;
			}
			else
			{
				out << pNameOfProduct;
			}

			out << d << setw(10) << left << productUnit;
			out << d << setw(7) << right << priceBeforeTax;
			out << d << setw(3) << right << (taxableStatus == true ? "yes" : "no");
			out << d << setw(6) << right << qtyProductOhHand;
			out << d << setw(6) << right << qtyProductNeed << " |";
		}
		else if (!isEmpty() && writeMode == write_human)
		{
			out << setw(max_length_label) << right << "Sku: " << productSKU << endl;
			out << setw(max_length_label) << right << "Name: " << pNameOfProduct << endl;
			out << setw(max_length_label) << right << "Price: " << setprecision(2) << fixed << priceBeforeTax << endl;
			out << setw(max_length_label) << right << "Price after Tax: " << (taxableStatus == true ? priceBeforeTax * (1 + tax_rate) : priceBeforeTax) << endl;
			out << setw(max_length_label) << right << "Quantity Available: " << qtyProductOhHand << " " << productUnit << endl;
			out << setw(max_length_label) << right << "Quantity Needed: " << qtyProductNeed << " " << productUnit << endl;

		}

		return out;
	}

	Product::~Product() {

		delete[] pNameOfProduct;
		pNameOfProduct = nullptr;
	}


} // end of namespace