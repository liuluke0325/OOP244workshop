// Workshop 7 - Derived Classes
// File w7_athome.cpp
// Version 2.0
// Date 3/14/2019
// Author      hsueh chih liu

#include "Hero.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sict {


	void Hero::set(const char* name, int health, int attack) {

		strncpy(NameOfHero, name, max_name_characters_with_null - 1);
		NameOfHero[max_name_characters_with_null - 1] = '\0';
		HealthOfHero = health;
		AttackStrength = attack;

	}

	//retrun true if all parameters valid
	bool Hero::isInputValid(const char* name, int health, int attack)const {
		return (name != nullptr && name != '\0') && isNumValid(health) && isNumValid(attack) ? true : false;
	}


	Hero::Hero() {
		set("\0", 0, 0);  // safe empty state
	}

	Hero::Hero(const char* name, int health, int attack) {

		if (isInputValid(name, health, attack))
		{
			set(name, health, attack);
		}
		else
		{
			set("\0", 0, 0); // safe empty state
		}

	}

	// return true if input interger is positive
	bool Hero::isNumValid(int num) const {

		return num > 0 ? true : false;
	}

	void Hero::operator-=(int attack) {

		if (isNumValid(attack))
		{
			HealthOfHero -= attack;

			if (HealthOfHero < 0) // if drop below 0, set to 0
			{
				HealthOfHero = 0;
			}
		}
		// else do nothing

	}


	bool Hero::isAlive() const {

		return HealthOfHero > 0 ? true : false;

	}

	int Hero::attackStrength() const {

		return isEmpty() ? 0 : AttackStrength;
	}


	bool Hero::isEmpty() const {
		return strcmp(NameOfHero,"\0")==0 ? true : false;
	}



	ostream& operator<<(ostream& os, const Hero& hero) {


		if (hero.NameOfHero[0] == '\0')
		{
			os << "No hero";
		}
		else {
			os << hero.NameOfHero;
		}

		return os;

	}



	void Hero::displayName() const {
		cout << NameOfHero;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero tempf = first;
		Hero temps = second;
		int countrounds = 0;
		const Hero *winner = nullptr; // to store the winners


		//count
		for (int i = 0; i < max_rounds && tempf.isAlive() && temps.isAlive(); i++)
		{
			tempf -= temps.attackStrength();
			temps -= tempf.attackStrength();
			countrounds++;

			if (!tempf.isAlive()) // if first is not alive
			{
				winner = &second; // second is winner
			}
			else if (!temps.isAlive())
			{
				winner = &first;
			}
		}

		// display
		cout << "Ancient Battle! ";
		first.displayName();
		cout << " vs ";
		second.displayName();
		cout << " : Winner is ";
		winner->displayName();
		cout << " in " << countrounds << " rounds." << endl;

		return *winner;
	}


}// end of namespace




