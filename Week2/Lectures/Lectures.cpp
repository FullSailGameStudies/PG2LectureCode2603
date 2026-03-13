#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>
#include <map>

//only use recursive methods for DETERMINANT loops
//(you know how many times it's going to loop)
void recursion(int n)
{
	//2) an exit condition (a base case)
	if(n < 10)
	{
		int b = 5;
		//1) a recursive call
		std::cout << n << " ";
		recursion(n + 1);
		Console::Write(n, (ConsoleColor)(rand() % 7));
	}
}

int main(int argc, char* args[])
{
	recursion(0);
	srand(static_cast<unsigned int>(time(NULL)));

	std::map<std::string, float> menu;
	//1) easy way
	//	  map[key] = value;
	menu["hotdogs"] = 1.99f;
	menu["lamb"] = 14.99f;
	menu["chicken pot pie"] = 7.99f;
	menu["Dino Nuggies"] = 12.99f;
	menu["Dino Nuggies"] = 14.99f;//overwrite the value
	//2) not-easy way
	//	 map.insert(key-valuepair);
	std::pair< std::string, float> menuPair =
		std::make_pair("burger", 8.99f);
	menu.insert(menuPair);
	menuPair.second = 11.99f;
	auto wasInserted =  menu.insert(menuPair);//does NOT overwrite the value

	std::cout << "\n\nMenu: \n";
	for (auto& pair : menu)
	{
		std::cout << pair.first << " " << pair.second << "\n";
	}
	//structured bindings
	for (auto& [menuItem,menuPrice] : menu)
	{
		std::cout << menuItem << " " << menuPrice << "\n";
	}
	for (auto it = menu.begin(); it != menu.end(); it++)
	{
		std::cout << it->first << " " << it->second << "\n";
	}

	std::string hello = "Hello Week 2!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";  

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Recursion Example\n",
		"2. Part A-1.1: Recursion (Bats)",
		"3. Part A-1.2: Recursion (Reverse Word)",
		"4. Part A-1.3: Recursion (Reverse words in a sentence)\n",
		"5. Part A-2: Sorting\n",
		"6. Part B-1: Linear Search\n",
		"7. Part B-2: Maps",
		"8. Part B-3: Find in Maps",
		"9. Part C-1: Erase from Maps",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day4::RecursionExample();
			break;
		}
		case 2:
		{
			Day4::PartA_1_1();
			break;
		}
		case 3:
		{
			Day4::PartA_1_2();
			break;
		}
		case 4:
		{
			Day4::PartA_1_3();
			break;
		}
		case 5:
		{
			Day4::PartA_2();
			break;
		}
		case 6:
		{
			Day5::PartB_1();
			break;
		}
		case 7:
		{
			Day5::PartB_2(1);
			break;
		}
		case 8:
		{
			Day5::PartB_2(2);
			break;
		}
		case 9:
		{
			Day6::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}