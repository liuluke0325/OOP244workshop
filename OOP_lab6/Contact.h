// Workshop 6 - Class with a Resource
// w6_in_lab.cpp
// hsueh chih liu
// 2019/03/07

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

	public:
		Contact();
		Contact(const char*, const long long*,int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};




}