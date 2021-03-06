#include "Map.h"
#include <iostream>
using namespace std;

Map::Map(int widthSize, int heightSize)
{
	// Set width, height data
	width = widthSize;
	height = heightSize;

	//CreateMap();
}


void Map::CreateMap(char** readData)
{
	
	char** tempData = new char*[height];
	for(int i = 0; i < height; i++)
	{
		tempData[i] = new char[width];
	}
	
	/**
	char tempData[10][10] =
	{
		0,0,4,0,0,0,0,0,0,9,
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
	*/
	// Initialize
	for(int i = 0; i < height; i++)
	{
		for(int i2 = 0; i2 < width; i2++)
		{
			tempData[i][i2] = readData[i][i2] - '0';
		}
	}

	mapData = new Node*[height];
	for (int i = 0; i < height; i++)
		mapData[i] = new Node[width];

	// Initialize Map data
	for (int i = 0; i < height; i++)
	{
		for (int i2 = 0; i2 < width; i2++)
		{
			mapData[i][i2].SetState(tempData[height - 1 -i][i2]);
			mapData[i][i2].SetPosition(i2, i);

			mapData[i][i2].AddNeighbour(GetNode(i2 - 1, i),0);
			mapData[i][i2].AddNeighbour(GetNode(i2 + 1, i),1);
			mapData[i][i2].AddNeighbour(GetNode(i2 , i-1),2);
			mapData[i][i2].AddNeighbour(GetNode(i2 , i+1),3);
		}
	}
}

Node** Map::GetMapData() const
{
	return mapData;
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

Node* Map::FindNode(int stateValue) const
{
	for(int i = 0; i < height; i++)
	{
		for(int i2 = 0; i2 < width; i2++)
		{
			if(mapData[i][i2].GetState() == 2) {return &mapData[i][i2];}
		}
	}
	return nullptr;
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
						cout << "��";
					else if (mapData[i][i2].GetState() == 2)//Player
						cout << "��";
					else if (mapData[i][i2].GetState() == 1)//Block
						cout << "��";
					else if (mapData[i][i2].GetState() == 3)//Snake
						cout << "��";
					else if (mapData[i][i2].GetState() == 4)//Bat
						cout << "��";
					else if (mapData[i][i2].GetState() == 9)//Goal
						cout << "��";
				}
				else {cout << "  ";}
			}
		}
		else {cout << "  ";}
		cout << endl;
	}
}

int* Map::GetMapSize()
{
	int* size = new int[2];
	size[0] = width, size[1] = height;
	return size;
}

Map::~Map()
{
	for(int i = 0; i < height; i++)
		delete[] mapData[i];
	delete[] mapData;
}