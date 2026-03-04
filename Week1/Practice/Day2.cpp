#include "Day2.h"
#include <string>
#include <Console.h>
#include <Input.h>
#include "Player.h"

//
// Part B-1.2: Add a method definition for GetLights
//
void Day2::GetLights(std::vector<Target>& lights)
{
	for (int col = 0; col < 48; col++)
	{
		for (int row = 0; row < 48; row++)
		{
			Target light;
			light.row = row;
			light.col = col;

			light.red = rand() % 256;//0-255
			light.green = rand() % 256;//0-255
			light.blue = rand() % 256;//0-255

			lights.push_back(light);
		}
	}
}

//
// Part B-2.2: Add a method definition for GetLights
//

//
// Part B-3.2: Add a method definition for EraseLights
//

void PrintNum(float& numRef)//pass by REFERENCE (ALIAS)
{
	numRef++;
	std::cout << numRef << "\n";
}
void Day2::PartB_1()
{
	float num = 5.3f;
	PrintNum(num);
	std::cout << num << "\n";
	float& numRef = num;
	float num2 = 10;
	numRef = num2;
	std::vector<int> nums = { 1, 2, 3 };
	//the loop variable, n, is a reference to the int in the vector
	for (int& n : nums) {
		n *= 2; //modifies the int in the vector
	}

	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part B-1 Goal: Pass by reference", ConsoleColor::Green);
		Console::WriteLine("Write a method called GetLights to fill the vector with Target objects.");
		Console::WriteLine("\t there should be 48 rows with 48 Target objects per row.");
		Console::WriteLine("\t Give each target a random color.");

		std::vector<Target> lights;
		//
		// Part B-1.3: call GetLights
		//
		GetLights(lights);

		Map map(engine.Renderer(), 10);

		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			for (auto& target : lights)
			{
				map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
			}

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}

void Day2::PartB_2()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-2"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part B-2 Goal: const parameters", ConsoleColor::Green);
		Console::WriteLine("Write a method called DrawLights to call DrawCell for each Target.");
		Console::WriteLine("\t NOTE: pass the vector and engine by reference AND as const.");

		std::vector<Target> lights;
		//
		// Part B-1.3: call GetLights
		//

		Map map(engine.Renderer(), 10);

		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			//
			// Part B-2.3: call DrawLights
			//

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}

void Day2::PartB_3()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-3"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part B-3 Goal: erasing in a loop", ConsoleColor::Green);
		Console::WriteLine("Write a method called EraseLights. Pass the 'lights' variable to it.");
		Console::WriteLine("\tInside the method, erase any light whose red value is less than 100.");

		std::vector<Target> lights;
		//
		// Part B-1.3: call GetLights
		//

		//
		// Part B-3.3: call EraseLights
		//


		Map map(engine.Renderer(), 10);

		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			//
			// Part B-2.3: call DrawLights
			//

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}
