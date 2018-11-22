#include "Map.h"
#include <iostream>
using namespace std;

Map::Map(int widthSize, int heightSize)
{
	// Set width, height data
	width = widthSize;
	height = heightSize;
	// Create Map
	CreateMap();
}

void Map::CreateMap()
{
	mapData = new char*[height];
	for(int i = 0; i < height; i++)
		mapData[i] = new char[width];

	// Initialize Map data
	InitializeMap();
}

char Map::GetMapDate(int xOffset, int yOffset) {
	return mapData[yOffset][xOffset];
}

void Map::SetMapData(int xOffset, int yOffset, int value)
{
	mapData[yOffset][xOffset] = value;
}

void Map::InitializeMap()
{
	for(int i = 0; i < height; i++)
	{
		for(int i2 = 0; i2 < width; i2++)
			mapData[i][i2] = 0;
	}
}

void Map::PrintMap(int* cLocation)
{
	for(int i = cLocation[1] + 4; i >= cLocation[1] - 4; i--)
	{
		if(i >= 0 && i < height)
		{
			for(int i2 = cLocation[0] - 4; i2 <= cLocation[0] + 4; i2++)
			{
				if(i2 >= 0 && i2 < width)
				{
					if (mapData[i][i2] == 0)
						cout << "¡à";
					else if (mapData[i][i2] == 1)
						cout << "¡á";
					else if (mapData[i][i2] == 2)						
						cout << "¡Ú";
					else if (mapData[i][i2] == 3)
						cout << "¡Ý";
					else
						cout << "¢Á";
				}
				else {cout << "  ";}
			}
		}
		else {cout << "  ";}
		cout << endl;
	}
}

void Map::PrintMap()
{
	for (int i = height-1; i >= 0; i--){
		for (int i2 = 0; i2 <= width-1; i2++){
			if (mapData[i][i2] == 0)
				cout << "¡à";
			else if (mapData[i][i2] == 1)
				cout << "¡á";
			else if (mapData[i][i2] == 2)
				cout << "¡Ú";
			else if (mapData[i][i2] == 3)
				cout << "¡Ý";
			else
				cout << "¢Á";
		}
		cout << endl;
	}
}


int* Map::GetMapSize()
{
	int* size = new int[2];
	size[0] = width, size[1] = height;
	return size;
}

char** Map::GetData() {
	return mapData;
}

int* Map::GetLocationOf(char data) {
	int* location = new int[2];
	location[0] = -1;
	for (int i = height - 1; i >= 0; i--) {
		for (int i2 = 0; i2 <= width - 1; i2++) {
			if (mapData[i][i2] == data) {
				location[0] = i2;
				location[1] = i;
			}
		}
	}
	return location;
}

Map::~Map()
{
	for(int i = 0; i < height; i++)
		delete[] mapData[i];
	delete[] mapData;
}