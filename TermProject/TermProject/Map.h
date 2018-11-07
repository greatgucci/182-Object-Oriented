#pragma once
#include "Node.h"
class Map
{
public:
	Map(int widthSize, int heightSize);
	Node** GetMapData() const;
    Node* GetNode(int xOffset, int yOffset) const;	// Get data
	void PrintMap(char x, char y) const;	// Print Map data
	int* GetMapSize();	// Return Map's width and height

	// Destructor
	~Map();

private:
	// Size
	int width, height;
	// Data
	Node **mapData;		// 0 : empty, 1 : character, 2 : obstacle
	// Create Map
	void CreateMap();
};