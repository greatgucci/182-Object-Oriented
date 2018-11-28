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
	MapEditor();
	vector<string> StrSplit(string targetStr, char tokenizer); //string tokenizer
	void ReadFile(); //map* pointer vector from file
	int FileControlMenu();
	void SaveFile();
	~MapEditor();

private:
	bool editEnded;
	EditMap* newMap;
	Map* tempMap;
	Node* tempNode;
	vector<Map*> mapList;
	vector<string> fileNameList;
};