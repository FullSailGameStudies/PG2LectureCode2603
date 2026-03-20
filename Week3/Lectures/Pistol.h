#pragma once
#include "Weapon.h"
//IS-A relationship
//Pistol IS-A Weapon
class Pistol : public Weapon  
{
public:
	Pistol(int range, int damage,int numRounds, int capacity)
		: //member initialization list
		Weapon(range, damage),
		numRounds_(numRounds), 
		capacity_(capacity),
		name_(nullptr)
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
	~Pistol()
	{
		if (name_ != nullptr)
		{
			delete name_;
			name_ = nullptr;
		}
	}

	//2. add a new method in the derived that matches EXACTLY the base method
	//  OPTIONAL: add the 'override' keyword to the declaration
	void showMe() override;
	int calcDamage() override;
	void Name()
	{
		name_ = new std::string("Batgun");
	}

private:
	int numRounds_, capacity_;
	std::string* name_;


};

