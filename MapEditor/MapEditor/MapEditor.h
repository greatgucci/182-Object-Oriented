#pragma once
#include "Map.h"
#include "Character.h"
#include "EditMap.h"
#include "Node.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class MapEditor
{


public:
	MapEditor(); //conductor
	vector<string> StrSplit(string targetStr, char tokenizer); //string tokenizer
	void ReadFile(); //map* pointer vector from file
	int FileControlMenu(); //file menu
	void SaveFile(); //save file
	~MapEditor(); // destructor

private:
	bool editEnded; //loop ended
	EditMap* newMap; // map
	Map* tempMap; // temp map
	Node* tempNode; // temp node
	vector<Map*> mapList; // map list
	vector<string> fileNameList; // file name list
};