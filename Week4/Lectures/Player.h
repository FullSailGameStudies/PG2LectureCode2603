#pragma once
#include <fstream>
#include <string>

class Player
{
public:

	Player() : worldX(0), worldY(0) {}

	//
	// Part B-1.1
	//
	void SerializeCSV(std::ofstream& outFile, char delimiter) const;

	//
	// Part B-2.1
	//
	void DeserializeCSV(const std::string& csvData, char delimiter);
	
	//
	// Part B-2.3
	//
	Player(const std::string& csvData, char delimiter)
	{
		DeserializeCSV(csvData, delimiter);
	}


	void MoveLeft() { worldX--; }
	void MoveRight() { worldX++; }
	void MoveUp() { worldY--; }
	void MoveDown() { worldY++; }

	void GetPosition(int& x, int& y)
	{
		x = worldX;
		y = worldY;
	}

	void Info();
private:
	int worldX, worldY;
};

