#include "Textures.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool Textures::LoadSubtextures()
{
	//
	// Part A-1
	//
	std::string fileName = "character_robot_sheetHD.csv";
	std::ifstream inFile(fileName);
	if (inFile.is_open())
	{
		char colDelim = '?';
		std::getline(inFile, imageFile_);
		while (not inFile.eof())
		{
			std::string line;
			std::getline(inFile, line);

			SubTexture sub;
			std::stringstream lineStream(line);
			std::getline(lineStream, sub.name, colDelim);

			std::string numData;
			std::getline(lineStream, numData, colDelim);
			sub.x = std::stoi(numData);

			std::getline(lineStream, numData, colDelim);
			sub.y = std::stoi(numData);

			std::getline(lineStream, numData, colDelim);
			sub.width = std::stoi(numData);

			std::getline(lineStream, numData, colDelim);
			sub.height = std::stoi(numData);

			maxWidth_ = std::max(maxWidth_, sub.width);
			maxHeight_ = std::max(maxHeight_, sub.height);

			subTextures_.push_back(sub);
		}
		inFile.close();
		return true;
	}
	else
	{
		std::cout << fileName << " could not be opened.\n";
	}
	inFile.close();
	return false;
}

bool Textures::LoadSpritesheet(SDL_Renderer* renderer)
{
	spriteSheet_ = new PG2Texture(renderer);
	return spriteSheet_->LoadFromFile(imageFile_);
}

SDL_Rect Textures::GetTextureSource(int index)
{
	SDL_Rect rect{ 0,0,0,0 };
	if (index >= 0 && index < subTextures_.size())
	{
		rect.x = subTextures_[index].x;
		rect.y = subTextures_[index].y;
		rect.w = subTextures_[index].width;
		rect.h = subTextures_[index].height;
	}
	return rect;
}

void Textures::Render(SDL_Rect* texSrc, SDL_Rect* dest, SDL_RendererFlip flip)
{
	spriteSheet_->Render(texSrc, dest, 0, 0, flip);
}
