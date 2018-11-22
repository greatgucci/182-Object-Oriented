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

//InitializeMap();
void Map::CreateMap()
{
	mapData = new Node*[height];
	for (int i = 0; i < height; i++)
		mapData[i] = new Node[width];
}
	
Node Map::GetMapData(int xOffset, int yOffset) {
	return mapData[yOffset][xOffset];
}

void Map::SetMapData(int xOffset, int yOffset, Node value)
{
	mapData[yOffset][xOffset].SetState(value.GetState());
}

Node* Map::GetNode(int x, int y) const
{
	if (x< width && y<height && x >= 0 && y >= 0)
	{
		return &mapData[y][x];
	}
	else
	{
		return nullptr;
	}
}

Node** Map::GetMapData() const
{
	return mapData;
}

void Map::PrintMap(char x, char y) const
{
	for(int i = y + 4; i >= y - 4; i--)
	{
		if(i >= 0 && i < height)
		{
			for(int i2 = x - 4; i2 <= x + 4; i2++)
			{
				if(i2 >= 0 && i2 < width)
				{
					if (mapData[i][i2].GetState() == 0)
						cout << "¡à";
					else if (mapData[i][i2].GetState() == 2)//Player
						cout << "¡Ú";
					else if (mapData[i][i2].GetState() == 1)//Block
						cout << "¡á";
					else if (mapData[i][i2].GetState() == 3)//Snake
						cout << "¡×";
					else if (mapData[i][i2].GetState() == 4)//Bat
						cout << "¡Ø";
					else if (mapData[i][i2].GetState() == 10)//Goal
						cout << "¡Ý";

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
			if (mapData[i][i2].GetState() == 0)
				cout << "¡à";
			else if (mapData[i][i2].GetState() == 1)
				cout << "¡á";
			else if (mapData[i][i2].GetState() == 2)
				cout << "¡Ú";
			else if (mapData[i][i2].GetState() == 3)
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

Node** Map::GetData() {
	return mapData;
}

int* Map::GetLocationOf(char data) {
	int* location = new int[2];
	location[0] = -1;
	for (int i = height - 1; i >= 0; i--) {
		for (int i2 = 0; i2 <= width - 1; i2++) {
			if (mapData[i][i2].GetState() == data) {
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