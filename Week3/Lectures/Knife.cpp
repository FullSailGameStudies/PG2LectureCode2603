#include "Knife.h"
#include <iostream>
void Knife::showMe()
{
	Weapon::showMe();
	std::cout << "\n\tIs Serrated: " << ((serrated_) ? "Yes" : "No") << "\n";
}