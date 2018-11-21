#pragma once
#include "Map.h"
#include "Character.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <conio.h>
using namespace std;

class EditMap {
public:
	EditMap(); //empty Map
	EditMap(Map* oldMap); //file input
	void EditFile();
	Map* GetMap();
	~EditMap();

private:
	Map* editorMap;
	bool editEnded;
	int width;
	int height;
	Character* inputCursor;
	Character* character;
	Character* portal;
	int* tempLocation;
	int* currentLocation;
};