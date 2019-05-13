// Workshop 7 - Derived Classes
// File w7_athome.cpp
// Version 2.0
// Date 3/14/2019
// Author      hsueh chih liu



#ifndef SICT_HERO_H	
/*
name:hsueh chih liu
student number : 116131186
date : 3/18/2019

*/


#define SICT_HERO_H
#include <iostream>

namespace sict {

	const int max_rounds = 100;
	const int max_name_characters_with_null = 41;
	class Hero {
		char NameOfHero[max_name_characters_with_null];
		int HealthOfHero; // positive
		int AttackStrength; // positive

	protected:
		void set(const char*, int, int);
		bool isNumValid(int) const;
		bool isEmpty() const;
	public:
		Hero();
		Hero(const char*, int, int);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};

	const Hero& operator*(const Hero& first, const Hero& second);

} // end of namespace




#endif