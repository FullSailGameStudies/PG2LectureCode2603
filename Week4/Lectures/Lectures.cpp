#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream>
#include <iostream>


int main(int argc, char* args[])
{

	std::string fileName, path, finalPath;
	fileName = "2603.csv";
	path = "C:/temp/2603/";
	finalPath = path + fileName;
	char colDelim = '$', rowDelim = '\n';
	//1) open the file
	std::ofstream outFile(finalPath);
	if (outFile.is_open())
	{
		//2) write to the file
		// << insertion operator
		outFile << "Batman" << colDelim << 35 << rowDelim;
		outFile << "Aquaman" << colDelim << 12;
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) close the file
	//close it ASAP
	outFile.close();


	std::string hello = "Hello Week 4!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Read CSV file",
		"2. Part A-2: Write CSV file",
		"3. Part B: Serialize/Deserialize objects",
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
			Day10::PartA_1();
			break;
		}
		case 2:
		{
			Day10::PartA_2();
			break;
		}
		case 3:
		{
			Day11::PartB();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}