// TODO: add file header comments here
//name : hsueh chih liu
//student id : 116131186





// TODO: add your headers here

#include <iostream>
#include <cstring>
#include "Traveler.h"
// TODO: continue your namespace here
using namespace std;
namespace sict {






	// TODO: implement the default constructor here
	Traveler::Traveler()   // safe empty state
	{
		strcpy(firstname, "???");
		strcpy(lastname, "???");
		strcpy(destination, "???");
		yearofdep = 0;
		dayofdep = 0;
		monthofdep = 0;
	}


	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char* fname, const char* lname, const char*desti) {

		if (fname == nullptr || fname[0] == '\0' || lname == nullptr || lname[0] == '\0' || desti == nullptr || desti[0] == '\0')
		{
			strcpy(firstname, "???");
			strcpy(lastname, "???");
			strcpy(destination, "???");
			yearofdep = 0;
			dayofdep = 0;
			monthofdep = 0;
		}
		else
		{
			strcpy(firstname, fname);
			strcpy(lastname, lname);
			strcpy(destination, desti);
			yearofdep = 2019;
			dayofdep = 1;
			monthofdep = 7;

		}

	}
	Traveler::Traveler(const char* fname, const char* lname, const char*desti, int dyear, int dmonth, int dday) {
		bool datenotvalid = true; // assume departure date is invalid (true = invalid)
		if (2022 >= dyear && dyear >= 2019 &&
			12 >= dmonth && dmonth >= 1 &&
			31 >= dday && dday >= 1)
		{
			datenotvalid = false;
		}

		if (fname == nullptr || fname[0] == '\0' || lname == nullptr || lname[0] == '\0' || desti == nullptr || desti[0] == '\0' || datenotvalid)
		{
			strcpy(firstname, "???");
			strcpy(lastname, "???");
			strcpy(destination, "???");
			yearofdep = 0;
			dayofdep = 0;
			monthofdep = 0;
		}
		else
		{
			strcpy(firstname, fname);
			strcpy(lastname, lname);
			strcpy(destination, desti);
			yearofdep = dyear;
			dayofdep = dday;
			monthofdep = dmonth;
		}


	}


	// TODO: implement isEmpty query here
	bool Traveler::isEmpty() const {
		bool check; // return true or false
		if (strcmp(firstname, "???") == 0) // safe empty state
		{
			check = true;
		}
		else  // if not in safe empty space
		{
			check = false;
		}

		return check;
	}
	// TODO: implement display query here
	void Traveler::display() const {

		if (isEmpty())
		{
			cout << "--> Not a valid traveler! <--" << endl;
		}
		else
		{
			cout << lastname << ", " << firstname << " goes to " << destination << " on " << yearofdep << "/";
			cout.fill('0');
			cout.width(2);
			cout << monthofdep << "/";
			cout.fill('0');
			cout.width(2);
			cout << dayofdep << endl;
		}



	}


	const char* Traveler::name() const {
		const char* p = nullptr; // pointer can be change, the object pointed can not be change

		if (strcmp(firstname, "???") != 0)  // if address of an empty string if the Traveler object is in a safe empty state.
		{
			p = firstname;
		}
		return p;

	}



	bool Traveler::canTravelWith(const Traveler& btraveler) const {
		bool check = false; // if true == can travel together
		if (strcmp(btraveler.destination, destination) == 0 &&    // check if two traveler can travel together if they are flying to the same destination on the same date).
			btraveler.dayofdep == dayofdep &&
			btraveler.monthofdep == monthofdep &&
			btraveler.yearofdep == yearofdep)
		{
			check = true;
		}

		return check;
	}




} // end of namespace