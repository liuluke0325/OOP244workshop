/*
name:hsueh chih liu
student number : 116131186
date : 3/18/2019

*/
#include "SuperHero.h"
#include "Hero.h"
#include <iostream>
using namespace std;
namespace sict {

	SuperHero::SuperHero() {

		attackBonus = 0;
		defendStrength = 0;

	}

	SuperHero::SuperHero(const char* name, int health, int attack, int supatk, int supdfs) : Hero(name, health, attack) {

		if (isNumValid(supatk) && isNumValid(supdfs)) // check is input valid
		{
			attackBonus = supatk;
			defendStrength = supdfs;
		}
		else
		{
			*this = SuperHero(); // if not set in safe empty state 
		}


	}


	int SuperHero::attackStrength() const {

		return isEmpty() ? 0 : Hero::attackStrength() + attackBonus;
	}



	int SuperHero::defend() const {
		return isEmpty() ? 0 : defendStrength;

	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {

		SuperHero tempf = first;
		SuperHero temps = second;
		int countrounds = 0;
		const SuperHero *winner = nullptr; // to store the winners


		//count
		for (int i = 0; i < max_rounds && tempf.isAlive() && temps.isAlive(); i++)
		{
			tempf -= temps.attackStrength() - tempf.defend();
			temps -= tempf.attackStrength() - temps.defend();
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
		cout << "Super Fight! " << first << " vs " << second << " : Winner is " << *winner << " in " << countrounds << " rounds." << endl;

		return *winner;

	}




}