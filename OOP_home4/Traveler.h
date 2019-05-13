// TODO: add file header comments here
//name : hsueh chih liu
//student id : 116131186



// TODO: add header file guard here
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H


// TODO: declare your namespace here
namespace sict {
	// TODO: define the constants here
const int max_destination_size = 32; //This represents the maximum number of characters for the destination of the traveler
const int max_name_size = 16;
		   
							   // TODO: define the Traveler class here
class Traveler
{
	char firstname[max_name_size]; //first name (including '\0');
	char lastname[max_name_size]; //last name (including '\0');
	char destination[max_destination_size];
	int yearofdep; //departure year
	int monthofdep; //departure month
	int dayofdep; //departure day
	

public:
	Traveler(); //constructor, sets the Traveler object to a safe empty state;
	Traveler(const char*, const char*, const char*);
	Traveler(const char*, const char*, const char*, int, int, int);
	const char* name() const;
	bool isEmpty() const; // a query that reports if the Traveler object is in a safe empty state.
	void display() const;
	bool canTravelWith(const Traveler&) const;

};



}


#endif 