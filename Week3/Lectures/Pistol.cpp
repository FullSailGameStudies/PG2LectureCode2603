#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	//what kind of OVERRIDE do I need?
	//FULL override:
	//	you do NOT want the base behavior.
	//  you ONLY want the new derived behavior
	//EXTENSION override:
	//	you want the base behavior + the new derived behavior
	Weapon::showMe();

	std::cout << "Rounds: " << numRounds_ << " Capacity: " << capacity_ << "\n";
}