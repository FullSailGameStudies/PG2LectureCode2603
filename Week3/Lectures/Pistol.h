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

	Pistol operator+(Pistol& other)
	{
		Pistol newPistol(range(), damage(),
			numRounds_ + other.numRounds_,
			capacity_);
		return newPistol;
	}

	//2. add a new method in the derived that matches EXACTLY the base method
	//  OPTIONAL: add the 'override' keyword to the declaration
	void showMe() override;

private:
	int numRounds_, capacity_;


};

