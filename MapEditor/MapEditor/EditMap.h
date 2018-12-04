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
	void EditFile();//file editing
	Map* GetMap();//return map
	~EditMap();//destructor

private:
	Map* editorMap;//source map
	bool editEnded;//loop ended
	int width;//map size width
	int height;//map size height
	Character* inputCursor; //input cursor location
	Character* character; //character
	Character* portal; //portal
	int* tempLocation; // temp location
	int* currentLocation; // current location
};