#include "MapEditor.h"
using namespace std;

MapEditor::MapEditor()
{
	SelectMenu(); //menu
}

void MapEditor::SelectMenu() {
	mapList = ReadFile();
	char selectMenu;
	system("cls");
	
	cout << "Welocmeto Map Editor Menu!" << endl << endl << "1. create new map" << endl << "2. map information" <<endl;
	
	selectMenu = _getch();
	while (!(selectMenu == '1' || selectMenu == '2'))
		selectMenu = _getch();

	if (selectMenu == '1') {//edit new map
		newMap = new EditMap();
		mapList.push_back(newMap->GetMap());
	}
	else {
		FileControlMenu();//read maps and edit - not completed
	}

	WriteFile(mapList);

}

void MapEditor::FileControlMenu() {
	int fileNumber=0;
	char selectMenu;
	system("cls");

	cout << "File Control Menu!" << endl << endl << "1. change map" << endl << "2. delete map" << endl << endl;

	selectMenu = _getch();
	while (!(selectMenu == '1' || selectMenu == '2' || selectMenu == '3'))
		selectMenu = _getch();

	if (selectMenu == '1') {//edit new map
		newMap = new EditMap(mapList.at(fileNumber));

	}
	else if (selectMenu == '2') {
		FileControlMenu();//read maps and edit - not completed
	}
	else {
	}
}


vector<Map*> MapEditor::ReadFile() { //pointer map vector from file
	int count = 0;
	int xOffset;
	int yOffset;
	char tempData;
	string tempStr;
	istringstream ss;
	vector<string> strVector;
	vector<Map*> mapVector;

	system("cls");

	ifstream file("mapData.csv");

	if (file.fail()) {
		cout << "no map list file.";
		system("pause");
	}

	cout << "Here is your map" << endl;
	cout << count + 1 << " map" << "\n\n";

	//map ÀÐ±â
	while(file.good()){
		file >> tempStr;
		strVector = StrSplit(tempStr, ',');

		ss = istringstream(strVector.at(0));
		ss >> xOffset;
		ss = istringstream(strVector.at(1));
		ss >> yOffset;

		tempMap = new Map(xOffset, yOffset);

		for (int i = yOffset - 1; i >= 0; --i) {
			file >> tempStr;
			strVector = StrSplit(tempStr, ',');
			for (int i2 = 0; i2 < xOffset; i2++) {
				ss = istringstream(strVector.at(i2));
				ss >> tempData;
				tempData -= '0';
				tempMap->SetMapData(i2, i, tempData);
			}
		}

		mapVector.push_back(tempMap);
	}
	
	return mapVector;
}

void MapEditor::WriteFile(vector<Map*> mapList) {
	//re-write file
}

vector<string> MapEditor::StrSplit(string targetStr,char tokenizer){
	vector<string> strResult;
	istringstream iss(targetStr);
	string token;
	while (getline(iss, token, tokenizer))
	{
		strResult.push_back(token);
	}
	return strResult;
}



MapEditor::~MapEditor()
{
	delete tempMap;
}

