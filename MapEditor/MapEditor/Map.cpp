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

//get map data
Node Map::GetMapData(int xOffset, int yOffset) {
	return mapData[yOffset][xOffset];
}

//set map data
void Map::SetMapData(int xOffset, int yOffset, Node value)
{
	mapData[yOffset][xOffset].SetState(value.GetState());
}

//get node
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

//get all map data
Node** Map::GetMapData() const
{
	return mapData;
}
// print map with color point
void Map::PrintMap(Character* inputCursor){
	int* currentLocation = inputCursor->GetCharacterLocation();
	for (int i = height - 1; i >= 0; i--) {
		for (int i2 = 0; i2 <= width - 1; i2++) {
			if (currentLocation[0] == i2 && currentLocation[1]== i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE + BLACK * 16);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE + BLACK * 16);
			}

			if (mapData[i][i2].GetState() == 0)
				cout << "��";
			else if (mapData[i][i2].GetState() == 1)
				cout << "��";
			else if (mapData[i][i2].GetState() == 2)
				cout << "��";
			else if (mapData[i][i2].GetState() == 3)
				cout << "��";
			else if (mapData[i][i2].GetState() == 4) {
				cout << "��";
			}
			else {
				cout << "��";
			}

		}

		cout << endl;
	}
}

//print all map
void Map::PrintMap()
{
	for (int i = height-1; i >= 0; i--){
		for (int i2 = 0; i2 <= width-1; i2++){
			if (mapData[i][i2].GetState() == 0)
				cout << "��";
			else if (mapData[i][i2].GetState() == 1)
				cout << "��";
			else if (mapData[i][i2].GetState() == 2)
				cout << "��";
			else if (mapData[i][i2].GetState() == 3)
				cout << "��";
			else if (mapData[i][i2].GetState() == 4){				
				cout << "��";
			}
			else {
				cout << "��";
			}
		
		}

		cout << endl;
	}
}

//get map size
int* Map::GetMapSize()
{
	int* size = new int[2];
	size[0] = width, size[1] = height;
	return size;
}

//get location
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