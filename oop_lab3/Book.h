/*
name : hsueh chih liu
id:116131186
student id : hcliu3
*/






#ifndef SICT_BOOK_H
#define SICT_BOOK_H


namespace sict {

	const int max_title_size = 32; //This represents the maximum number of characters for the title of the book (not including the null byte '\0')

	const int max_name_size = 16; //This represents the maximum number of characters for the name of the book author (not including the null byte '\0')
	const long long min_isbn_value = 1000000000000; // smallest ISBN
	const long long max_isbn_value = 9999999999999; // max ISBN

	class Book
	{
		char familyname[max_name_size +1];
		char givenname[max_name_size + 1];
		char booktitle[max_title_size + 1];
		long long ISBN; // The ISBN that identifies the book

	public:

		void set(const char*  , const char* , const char* , long long );

		bool isEmpty() const;
		void display() const;

	};




}


#endif 