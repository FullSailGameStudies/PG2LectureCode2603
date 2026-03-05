#pragma once
#include "Map.h"
#include "Target.h"
#include <string>
#include <vector>

class Day2
{
public:
	void PartB_1();
	void PartB_2();
	void PartB_3();

	const std::string& GetName() const
	{
		std::string nm = "Bruce Wayne";
		return name;
	}
	void SetName(const std::string& nm)
	{
		name = nm;
	}
	void CopyName(std::string& nm) const
	{
		nm = name;
	}
private:
	std::string name;
	//
	// Part B-1.1: Add a method declaration for GetLights
	//
	void GetLights(std::vector<Target>& lights);

	//
	// Part B-2.1: Add a method declaration for DrawLights
	//
	void DrawLights(const std::vector<Target>& lights,const Map& map) const;

	//
	// Part B-3.1: Add a method declaration for EraseLights
	//
	void EraseLights(std::vector<Target>& lights);

};

