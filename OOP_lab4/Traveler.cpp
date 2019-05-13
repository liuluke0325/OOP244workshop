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
	}


	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char* fname, const char* lname, const char*desti) {

		if (fname == nullptr || fname[0] == '\0' || lname == nullptr || lname[0] == '\0' || desti == nullptr || desti[0] == '\0')  
		{
			strcpy(firstname, "???");
			strcpy(lastname, "???");
			strcpy(destination, "???");
		}
		else
		{
			strcpy(firstname, fname);
			strcpy(lastname, lname);
			strcpy(destination, desti);
		}

	}



	// TODO: implement isEmpty query here
	bool Traveler::isEmpty() const {
		bool check; // return true or false
		if (strcmp(firstname, "???")==0) // safe empty state
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
			cout << firstname << " " << lastname << " goes to " << destination << endl;
		}



	}
}