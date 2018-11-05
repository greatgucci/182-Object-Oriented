#pragma once

class Map
{
public:
	Map(int widthSize, int heightSize);

	char GetMapDate(int xOffset, int yOffset);	// Get data
	void SetMapData(int xOffset, int yOffset, int value);	// Set data
	void InitializeMap();	// Initialize map data
	void PrintMap(int* cLocation);	// Print Map data
	int* GetMapSize();	// Return Map's width and height

	// Destructor
	~Map();

private:
	// Size
	int width, height;
	// Data
	char **mapData;		// 0 : empty, 1 : character, 2 : obstacle
	// Create Map
	void CreateMap();
};