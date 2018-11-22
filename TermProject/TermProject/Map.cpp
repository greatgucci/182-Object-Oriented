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
	char tempData[10][10] =
	{
		0,0,4,0,0,0,0,0,0,10,
		0,0,0,3,0,1,1,1,0,1,
		1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,4,0,0,1,
		1,1,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,1,1,0,1,1,1,0,1,0,
		0,0,1,0,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		2,1,1,1,1,0,0,0,0,0,
	};

	mapData = new Node*[height];
	for (int i = 0; i < height; i++)
		mapData[i] = new Node[width];

	// Initialize Map data
	for (int i = 0; i < height; i++)
	{
		for (int i2 = 0; i2 < width; i2++)
		{
			mapData[i][i2].SetState(tempData[9-i][i2]);
			mapData[i][i2].SetPosition(i2, i);
			mapData[i][i2].AddNeighbour(GetNode(i2 - 1, i),0);
			mapData[i][i2].AddNeighbour(GetNode(i2 + 1, i),1);
			mapData[i][i2].AddNeighbour(GetNode(i2 , i-1),2);
			mapData[i][i2].AddNeighbour(GetNode(i2 , i+1),3);
		}
	}

	
char Map::GetMapDate(int xOffset, int yOffset) {
	return mapData[yOffset][xOffset];
}

void Map::SetMapData(int xOffset, int yOffset, int value)
{
	mapData[yOffset][xOffset] = value;
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