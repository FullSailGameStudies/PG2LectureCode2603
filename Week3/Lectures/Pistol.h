#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage,int numRounds, int capacity)
		: //member initialization list
		Weapon(range, damage),
		numRounds_(numRounds), 
		capacity_(capacity)
	{
		//do NOT do the base ctor code in the derived ctor
	}

private:
	int numRounds_, capacity_;


};

