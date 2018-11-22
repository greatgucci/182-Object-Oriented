#pragma once
#include "Node.h"
class Map
{
public:
	Map(int widthSize, int heightSize);
	Node** GetMapData() const;
    Node* GetNode(int xOffset, int yOffset) const;	// Get data
	void PrintMap(char x, char y) const;	// Print Map data
	char GetMapDate(int xOffset, int yOffset);	// Get data
	void SetMapData(int xOffset, int yOffset, int value);	// Set data
	void InitializeMap();	// Initialize map data
	void PrintMap(int* cLocation); //Print map data for location
	void PrintMap();	//Print All map
	int* GetMapSize();	// Return Map's width and height
	int* GetLocationOf(char data); //get location of special object
	char** GetData();

	// Destructor
	~Map();

private:
	// Size
	int width, height;
	// Data
	Node **mapData;		// 0 : empty, 1 : character, 2 : obstacle
	char **mapData;		// 0 : empty, 1 : wall, 2 : character, 3 : portal, 4 : obstacle
	// Create Map
	void CreateMap();
};