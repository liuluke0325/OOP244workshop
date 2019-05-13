/*
name : hsueh chih liu
id:116131186
student id : hcliu3
*/


#include "Book.h"
#include <cstring>
#include <iostream>

using namespace std;


namespace sict {

	void Book::set(const char * giv_name, const char *fami_name, const char * tit_book, const long long isbn) {


		if (isbn >= min_isbn_value && isbn <= max_isbn_value) // check is 13 digits or not
		{
			
			int oddsum = 0;
			int evensum = 0;
			int checkdigit = 0;
			long long tempnum = isbn; // store a temperate isbn in order to calculate
			int arrayisbn[13]; // array version isbn
			
			for (int i = 12; i >= 0; i--) //convert ISBN into array.
			{
				arrayisbn[i] = tempnum % 10; // store the last digit into array
				tempnum = tempnum / 10; // delete the last digits
			}
	

			// 1 3 .... 9 11= odd sum  , index = 0 2... 8 10
			for (int i = 0; i < 11; i = i+2) // calculate odd isbn
			{
				oddsum += arrayisbn[i];
			}

			// 2 4 ... 10 12= even sum  , index = 1 3.. 9 11
			for (int i = 1; i < 12; i = i + 2) // calculate even isbn
			{
				evensum += arrayisbn[i];
			}

			evensum = evensum * 3;  // Calculate the even sum and multiply it by three



			checkdigit = ((((evensum + oddsum) / 10) + 1) * 10) - (evensum + oddsum);// conver to Next highest integer multiple of 10 ex, 89 -> 90 , then divided by sum of even and odd

			if (checkdigit == arrayisbn[12]) // if == check digit (last digit of isbn)  ,  valid isbn
			{
				ISBN = isbn; // if valid, store in object
				strncpy(givenname, giv_name, max_name_size+1);
				strncpy(familyname, fami_name, max_name_size+1);
				strncpy(booktitle, tit_book, max_title_size+1);
			}
			else
			{
				ISBN = -99;//unvalid isbn, store to empty state
			}


		}
		else
		{
			ISBN = -99;//empty state
		}

	}

	void Book::set(int year, double price) {

		if (isEmpty()) //If the object is empty, this function does nothing.
		{

		}
		else //if the object is not empty, this function stores the parameters into the attributes.
		{
			publishyear = year;
			bookprice = price;
		}

	}




	bool Book::isEmpty() const { //This function returns true if the object is in a safe empty state, false otherwise. void display() const: If the object is
		bool check;
		if (ISBN == -99)
		{
			check = true;  //object is in a safe empty state,
		}
		else
		{
			check = false; // otherwise
		}
		return check;


	}




	void Book::display(bool check) const {
		if (isEmpty() == true && check == false)
		{
			cout << "The book object is empty!" << endl;
		}
		else if (isEmpty() == false && check == false)
		{
			cout << "Author: " << familyname << ", " << givenname << endl;
			cout << "Title: " << booktitle << endl;
			cout << "ISBN-13: " << ISBN << endl;
			cout << "Publication Year: " << publishyear << endl;
			cout << "Price: " << bookprice << endl;




		}
		else if (isEmpty() == true && check == true)
		{
			cout << "|";
			cout.width(92);
			cout.setf(ios::left);
			cout << "The book object is empty!";
			cout.unsetf(ios::left);
			cout << "|" << endl;
		}
		else if (isEmpty() == false && check == true)
		{
			cout << "|";
			cout.width(max_name_size); cout << familyname;
			cout << "|";
			cout.width(max_name_size);cout << givenname;
			cout << "|";
			cout.width(max_title_size);cout.setf(ios::left);cout << booktitle;
		    cout << "|";
			cout.unsetf(ios::left);cout.width(13);cout << ISBN;
			cout << "|";
			cout.width(4);cout << publishyear;
			cout << "|";
			cout.setf(ios::fixed);cout.width(6);cout.precision(2);cout << bookprice;
			cout << "|" << endl;
			cout.unsetf(ios::fixed);
		}




	}





}

