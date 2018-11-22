#pragma once
#include "Map.h"
#include "Character.h"
#include "EditMap.h"
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
	void SelectMenu();	//menu
	int ShowFile();		//show file output menu
	vector<string> StrSplit(string targetStr, char tokenizer); //string tokenizer
	vector<Map*> ReadFile(); //map* pointer vector from file
	void WriteFile(vector<Map*> mapList); // write file
	void FileControlMenu();
	~MapEditor();

private:
	
	bool editEnded;
	EditMap* newMap;
	Map* tempMap;
	vector<Map*> mapList;
};