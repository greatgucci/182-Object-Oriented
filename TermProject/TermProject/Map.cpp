#include "Map.h"
#include <iostream>
#include <io.h>
#include <fstream>
#include <string.h>
#include "ConsoleController.h"
using namespace std;

Map::Map(int widthSize, int heightSize)
{
	// Set width, height data
	width = widthSize;
	height = heightSize;
	bIsOddTiming = false;
}


void Map::CreateMap(char** readData)
{
	
	char** tempData = new char*[height];
	for(int i = 0; i < height; i++)
	{
		tempData[i] = new char[width];
	}

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

void Map::PrintMap(char x, char y, Character* character)
{
	int printRange = 4;	// The practical range is printRagne * 2.
	for(int i = y + printRange; i >= y - printRange; i--)
	{
		if(i >= 0 && i < height)
		{
			for(int i2 = x - printRange; i2 <= x + printRange; i2++)
			{
				if(i2 >= 0 && i2 < width)
				{
					if (mapData[i][i2].GetState() == 0 || mapData[i][i2].GetState() == 1)
					{
						
						if(i2%2 == 0 && i%2 == 0) {SetTextColor(8 + 7*bIsOddTiming);}
						else if(i2%2 == 0 && i%2 == 1) {SetTextColor(15 - 7*bIsOddTiming);}
						else if(i2%2 == 1 && i%2 == 0) {SetTextColor(15 - 7*bIsOddTiming);}
						else {SetTextColor(8 + 7*bIsOddTiming);}
						
						mapData[i][i2].GetState() == 0 ?(cout << "¡à") : (cout << "¡á");
					}
					else if (mapData[i][i2].GetState() == 2)//Player
						{SetTextColor(14); cout << "¡Ú";}
					/*
					else if (mapData[i][i2].GetState() == 1)//Block
						{textcolor(8); cout << "¡á";}
					*/
					else if (mapData[i][i2].GetState() == 3)//Snake
						{SetTextColor(13); cout << "¡×";}
					else if (mapData[i][i2].GetState() == 4)//Bat
						{SetTextColor(10); cout << "¡Ø";}
					else if (mapData[i][i2].GetState() == 9)//Goal
						{SetTextColor(11); cout << "¡Ý";}
				}
				else {cout << "  ";}
			}
		}
		// Print Character State
		if(i == y)
		{
			SetTextColor(12);
			cout << "  ¢¾ " << character->GetLife();
		}
		cout << endl;
	}
	bIsOddTiming = (1+bIsOddTiming)%2;	// if this value is 0, changes to 1. vice versa.
}

int* Map::GetMapSize()
{
	int* size = new int[2];
	size[0] = width, size[1] = height;
	return size;
}

Map* Map::SelectMap()
{
	char csvFileList[100][100];
	int csvFileCount = 0;
	char* selectedFilePath;

	// Select a map of csv list
	_finddatai64_t c_file;
	intptr_t hFile;

	if((hFile = _findfirsti64("*.csv", &c_file)) == -1L)
	{
		cout << "No files in that directory"<< endl;
	}
	else
	{
		do
		{
			strcpy_s(csvFileList[csvFileCount], 100, c_file.name);
			csvFileCount++;
			cout<< csvFileList[csvFileCount-1] <<endl;
		} while(_findnexti64(hFile, &c_file) == 0);
		_findclose(hFile);
	}
	selectedFilePath = csvFileList[rand() % csvFileCount];

	// Read Map Data
	ifstream readFile(selectedFilePath);
	try
	{
		if(readFile.is_open() == true)
		{
			//cout << "Read success!" << endl;
			char sizeStr[10];
			readFile.getline(sizeStr, 10);

			/** Get length of sizeStr */
			int length = 0;
			while(sizeStr[length] != NULL) {length++;}

			/** Devide sizeStr to widthStr, heightStr */
			int cIndex = 0;
			while(sizeStr[cIndex] != ',') {cIndex++;}
			int width = 0, height = 0;
			for(int i = 0; i < cIndex; i++)
			{
				width += (sizeStr[i] - '0') * (int)pow(10, (cIndex - 1 - i));
			}
			for(int i = cIndex + 1; i < length; i++)
			{
				height += (sizeStr[i] - '0') * (int)pow(10, (length - 1 - i));
			}

			/** Get map data from file */
			// Initialize the temp map data
			char** mapData;
			mapData = new char*[height];
			for(int heightIndex = 0; heightIndex < height; heightIndex++)
			{
				mapData[heightIndex] = new char[width];
			}
			// Set the temp map data from file
			for(int i = 0; i < height; i++)
			{
				char* ithDataStr = new char[width*2 - 1];	// includes number of comma
				readFile.getline(ithDataStr, width*2);
				for(int i2 = 0; i2 < width*2 - 1; i2+=2)
				{
					mapData[i][i2/2] = ithDataStr[i2];
				}
			}

			readFile.close();

			// Copy to Map Data
			Map* selectedMap = new Map(width, height);
			selectedMap->CreateMap(mapData);

			return selectedMap;
		}
		else
		{
			throw false;
		}
	}
	catch(bool)
	{
		cout << "Read Failed!" << endl;
	}

	return NULL;
}

Map::~Map()
{
	for(int i = 0; i < height; i++)
		delete[] mapData[i];
	delete[] mapData;
}