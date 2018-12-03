#include "MapEditor.h"
using namespace std;

MapEditor::MapEditor()
{
	ReadFile();
	if(FileControlMenu()) //menu
		cout << "file edit completed";
}


int MapEditor::FileControlMenu() {
	vector<Map*>::iterator iterMap;
	vector<Map*>::iterator iterTempMap;
	vector<string>::iterator iterStr;
	string tempMapName;
	iterMap = mapList.begin();
	iterStr = fileNameList.begin();
	if (iterMap == mapList.end()) {
		cout << "no map data";
		return 0;
	}

	char inputKey = 0;
	editEnded = false;
	system("cls");
	while (!editEnded) {
		

		cout << "\nFile Control Menu!" << endl << endl;
		

		if ((iterMap) == mapList.end()) {
			cout << endl << "No Maps in File" << endl;
			cout << "1. create New Map";
		}
		else {
			cout << "1. create map" << endl << "2. change map" << endl <<"3. delete map"<< endl<<endl;
			cout << "a : previous map" << "\td : next map" << endl << "q : save and exit" << endl;
			cout << endl << "map name : " << *iterStr << endl << endl;
			tempMap = (*iterMap);
			tempMap->PrintMap();
			cout << endl;
		}
		
		
		inputKey = _getch();

		
		if (inputKey == '1') {
			newMap = new EditMap();
			cout << "create map's name : ";
			cin >> tempMapName;
			mapList.push_back(newMap->GetMap());
			fileNameList.push_back(tempMapName+".csv");
			FileControlMenu();
		}
		else if (inputKey == '2') {//edit new map

			newMap = new EditMap(tempMap);
			iterMap = mapList.erase(iterMap);
			iterMap = mapList.insert(iterMap, newMap->GetMap());
		}
		else if (inputKey == '3') {
			iterMap = mapList.erase(iterMap);
			iterStr = fileNameList.erase(iterStr);
			if (iterMap == mapList.end()) {
				iterMap = mapList.begin();
				iterStr = fileNameList.begin();
			}

		}

		switch (inputKey) {
		case 'A':
		case 'a':
			if (iterMap == mapList.begin()) {
				cout << "this map is first map" << endl;
			}
			else {
				iterMap--;
				iterStr--;
			}
			break;
		case 'D':
		case 'd':
			iterMap++;
			iterStr++;
			if (iterMap == mapList.end() || iterStr == fileNameList.end()) {
				iterMap--;
				iterStr--;
				cout << "this map is lastest map" << endl;
			}
			break;
		case 'q':
		case 'Q':
			SaveFile();
			cout << "file save completed";
			editEnded = true;
			inputKey = 0;
		}
		
		
		system("cls");
	}

	return 1;
}

void MapEditor::SaveFile() {
	ofstream fileName("mapListData.txt");
	vector<string>::iterator iterStr;
	for (iterStr = fileNameList.begin(); iterStr != fileNameList.end(); iterStr++) {
		fileName << *iterStr;
		if (iterStr + 1 != fileNameList.end()) {
			fileName << "\n";
		}
	}


	ofstream* mapFile;
	Node** mapData;
	int width, height;
	char tempData;
	
	for (int i = 0; i < fileNameList.size(); i++) {
		mapFile = new ofstream(fileNameList.at(i));
		tempMap = mapList.at(i);
		width = tempMap->GetMapSize()[0];
		height = tempMap->GetMapSize()[1];
		mapData = tempMap->GetMapData();
		*mapFile << width <<"," << height<<"\n";

		for (int i = height - 1; i >= 0; i--) {
			for (int i2 = 0; i2 <= width - 1; i2++) {
				tempData = mapData[i][i2].GetState();
				tempData += '0';
				*mapFile << tempData;
				if (i2 != width-1) {
					*mapFile << ',';
				}
			}
			if (i != 0) {
				*mapFile << '\n';
			}
		}
	}
}

void MapEditor::ReadFile() { //pointer map vector from file
	int count = 0;
	int xOffset;
	int yOffset;
	char tempData;
	string tempStr;
	istringstream ss;
	vector<string> strVector;

	fileNameList.clear();
	mapList.clear();

	system("cls");
	tempNode = new Node();

	ifstream fileList("mapListData.txt");
	ifstream* file;

	//file list 읽기
	while (fileList.good()) {
		if (fileList.fail()) {
			cout << "no map list file.";
			system("pause");
		}
		fileList >> tempStr;
		fileNameList.push_back(tempStr);
	}

	//map 읽기
	file = new ifstream(fileNameList.at(count));
	while(file->good()){
		
		if (file->fail()) {
			cout << "no map file.";
			system("pause");
		}

		*file >> tempStr;
		strVector = StrSplit(tempStr, ',');

		ss = istringstream(strVector.at(0));
		ss >> xOffset;
		ss = istringstream(strVector.at(1));
		ss >> yOffset;

		tempMap = new Map(xOffset, yOffset);

		for (int i = yOffset - 1; i >= 0; --i) {
			*file >> tempStr;
			strVector = StrSplit(tempStr, ',');
			for (int i2 = 0; i2 < xOffset; i2++) {
				ss = istringstream(strVector.at(i2));
				ss >> tempData;
				tempData -= '0';
				tempNode->SetState(tempData);
				tempMap->SetMapData(i2, i, *tempNode);
			}
		}

		mapList.push_back(tempMap);
		count++;
		if (count >= fileNameList.size())
			break;
		file = new ifstream(fileNameList.at(count));
	}
	
	
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
	delete tempNode;
	delete tempMap;
}

