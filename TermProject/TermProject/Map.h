#pragma once
#include "Node.h"
#include "Character.h"
class Map
{
public:
	Map(int widthSize, int heightSize);
	Node** GetMapData() const;
    Node* GetNode(int x, int y) const;	// Get data
	Node* FindNode(int stateValue) const;	// Find data
	void PrintMap(char x, char y, Character* character);	// Print Map data
	int* GetMapSize();	// Return Map's width and height
	// Create Map
	void CreateMap(char** readData);
	// Select Map of files in directory (used in MainSrouce.cpp)
	static Map* SelectMap();

	// Destructor
	~Map();

private:
	// Size
	int width, height;
	bool bIsOddTiming;
	// Data
	Node **mapData;		// 0 : empty, 1 : character, 2 : obstacle
};