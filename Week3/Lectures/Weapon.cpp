#include <iostream>
#include "Weapon.h"

Weapon::Weapon(int range, int damage) 
	: 
	//member initialization list
	mRange(range), 
	mDamage(damage)
{
	//ok
	//mRange = range;
	//mDamage = damage;
}

void Weapon::showMe()
{
	std::cout << "Range: " << mRange << " Damage: " << mDamage << "\n";
}

int Weapon::calcDamage()
{
	return rand() % (mDamage+1);
}
