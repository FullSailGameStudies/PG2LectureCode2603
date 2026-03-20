#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include "Weapon.h"
#include "Color.h"
#include <Pistol.h>
#include <Knife.h>

double add(double n1, double n2) { return n1 + n2; }
int add(int n1, int n2) { return n1 + n2; }
int add(int n1, int n2, int n3) { return n1 + n2 + n3; }

void Counter()
{
	static int i = 0;
	std::cout << i << " ";
	i++;
}
int main(int argc, char* args[])
{
	//stack variables
	int n = 5;
	int* nPtr = &n;//address-of
	int& nRef = n;
	std::cout << n << "\n";
	std::cout << nRef << "\n";
	std::cout << *nPtr << "\n";//* - dereferencing

	//heap variables
	//   developer-managed memory
	//  anytime you see " = new", 
	//    you are creating heap variables
	int* nHeap = new int(10);
	//whatever you "new", you MUST "delete"
	//delete it when you don't need it anymore
	delete nHeap;


	//indexer 
	//[3] means startingPtr + index * sizeoftype
	//startingPtr++

	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	std::cout << add(5, 2) << "\n" << add(5, 2, 10) << "\n";
	std::cout << add(5, 2) << "\n" << add(5.2, 2.7) << "\n";

	Color clr;
	clr.red = 255;
	clr.green = clr.blue = 0;
	clr.alpha = 255;

	int value = 10;
	//Weapon wpn(10, 100);//this is calling the default ctor
	//wpn.SetRange(10);
	//wpn.Damage(100);
	//std::cout << wpn.range() << " " << wpn.damage() << "\n";

	Pistol* heapPistol = new Pistol(100, 200, 5, 5);
	Pistol p1(50, 100, 10, 15);
	Pistol p2(50, 100, 3, 15);
	Pistol p3 = p1 + p2;
	Weapon wpn(10, 100);

	wpn = p1;//??
	//copies the Weapon parts of p1 to wpn
	//p1 = wpn;
	std::vector<Weapon*> inventory;
	inventory.push_back(new Pistol(50,100,5,10));//UPCASTING pointers
	inventory.push_back(new Knife(3, 10, true));//UPCASTING 

	std::cout << "\n\nInventory:\n";
	for (auto& item : inventory)
	{
		item->showMe();//runtime polymorphism
	}

	//cleanup the objects
	for (int i = 0; i < inventory.size(); i++)
	{
		delete inventory[i];
	}
	inventory.clear();

	//use heapPistol for stuff
	//delete it when we're done
	delete heapPistol;
	heapPistol = nullptr;
	if(heapPistol != nullptr)
		heapPistol->showMe();

	Pistol* pPistol = &p1;
	pPistol->showMe();
	(*pPistol).showMe();
	pPistol->showMe();

	p3.showMe();


    std::string hello = "Hello Week 3!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Create Class",//classes + inheritance + override?
		"2. Part B-1: Inheritance, Polymorphism",//no pointers
		"3. Part C-1: Pointers",//pointers
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day7::PartA_1();
			break;
		}
		case 2:
		{
			Day8::PartB_1();
			break;
		}
		case 3:
		{
			Day9::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());


	return 0;
}