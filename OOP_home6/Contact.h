// Workshop 6 - Class with a Resource
// w6_at_home.cpp
// Hsueh Chih Liu
// 2019/03/11
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H


namespace sict {

const int max_name_size = 16;//This represents the maximum number of characters for the name of the traveler

	class Contact {
		char name[max_name_size];//including \0
		long long * phonenum; //a pointer to a dynamically allocated array of phone numbers
		int numofdynamic;


		int countdigits(const long long);
		long long getareacode(const long long)const;
		long long getcountrycode(long long) const;
		long long getsevennum(const long long) const;
		bool isphonevalid(const long long);
		void set(const char*, long long*, int);
		void set(const char*, int);
		
	public:
		Contact();
		Contact(const Contact &); // copy constructor
		Contact(const char*, const long long*,int);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact & operator =(const Contact&); // COPY ASSIGNMENT OPERATOR
		Contact & operator += (const long long);
	};




}


#endif // 