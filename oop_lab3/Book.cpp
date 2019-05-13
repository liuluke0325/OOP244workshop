/*
name : hsueh chih liu
id:116131186
student id : hcliu3
*/









#include "book.h"
#include <cstring>
#include <iostream>





using namespace std ;


namespace sict {

void Book::set(const char * giv_name, const char *fami_name, const char * tit_book, long long isbn){


	if (isbn >= min_isbn_value && isbn <= max_isbn_value)
	{
		ISBN = isbn; // if valid, store in object 

	    strncpy(givenname, giv_name, max_name_size);
		strncpy(familyname, fami_name, max_name_size);
		strncpy(booktitle, tit_book, max_title_size);


	}
	else
	{
		ISBN = -99;//empty state
	}


}

bool Book::isEmpty() const{ //This function returns true if the object is in a safe empty state, false otherwise. void display() const: If the object is
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



void Book::display() const{

	if (isEmpty())
	{
			cout << "The book object is empty!" << endl;

	}
	else {

	cout << "Author: " << familyname << ", " << givenname << endl;
	cout << "Title: " << booktitle << endl;
	cout << "ISBN-13: " << ISBN << endl;

	}

}


}

