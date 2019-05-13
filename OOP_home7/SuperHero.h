/*
name:hsueh chih liu
student number : 116131186
date : 3/18/2019

*/

 #include "Hero.h"
namespace sict {
	class SuperHero : public Hero {

		int attackBonus;
		int defendStrength;

	public:
		SuperHero(); 
		SuperHero(const char* name, int health, int attack, int supatk, int supdfs);
		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);


} // end of namespace