#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream>
#include <iostream>
#include <sstream>


int main(int argc, char* args[])
{

	std::string fileName, path, finalPath;
	fileName = "2603.csv";
	path = "";
	finalPath = path + fileName;
	char colDelim = '$', rowDelim = '\n';
	//1) open the file
	std::ofstream outFile(finalPath);
	if (outFile.is_open())
	{
		//2) write to the file
		// << insertion operator
		outFile << "Batman" << colDelim << "Age35" << rowDelim;
		outFile << "Aquaman" << colDelim << 12;
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) close the file
	//close it ASAP
	outFile.close();


	std::ifstream inFile(finalPath);
	//1) open the file
	if (inFile.is_open())
	{
		//2) read the file
		//read until we reach the end of the file (or stream)
		while (not inFile.eof())//eof - end of file
		{
			//read 1 line from the file
			std::string line;
			//reads the file until it encounters
			//  a '\n' OR the end of the STREAM
			std::getline(inFile, line);
			std::cout << line << "\n";

			//parse the line
			std::string data;
			std::stringstream lineStream(line);
			//reads the file until it encounters
			//  a '$' OR the end of the STREAM
			std::getline(lineStream, data, colDelim);
			std::cout << data << "\n";

			std::getline(lineStream, data, colDelim);
			// try-catch
			try
			{
				int age = std::stoi(data);
				std::cout << age << "\n";
			}
			catch (const std::exception& ex)
			{
				std::cout << "ERROR parsing " << data << "\n";
				std::cout << ex.what() << "\n";
			}
		}
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) close the file
	//close it ASAP
	inFile.close();


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