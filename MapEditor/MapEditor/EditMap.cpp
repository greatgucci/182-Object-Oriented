#include "EditMap.h"

EditMap::EditMap() {
	//width height
	int width;
	int height;
	cout << endl << "enter width of map : ";
	cin >> width;
	cout << "enter height of map : ";
	cin >> height;


	//create defualt Map
	editorMap = new Map(width, height);
	character = new Character();
	portal = new Character();
	character->SetCharacterLocation(-1, 0);
	portal->SetCharacterLocation(-1, 0);

	EditFile();
}

EditMap::EditMap(Map* oldMap) {
	editorMap = oldMap;
	character = new Character();
	portal = new Character();
	tempLocation = editorMap->GetLocationOf(2);
	character->SetCharacterLocation(tempLocation[0], tempLocation[1]);
	portal->SetCharacterLocation(tempLocation[0], tempLocation[1]);

	EditFile();
}

void EditMap::EditFile() {
	editEnded = false;
	system("cls");

	//input
	char inputKey = 0;

	inputCursor = new Character();

	Node currentState;
	Node previousState;
	Node tempNode;

	tempLocation = new int[2];
	currentLocation = inputCursor->GetCharacterLocation();

	while (!editEnded) {	//q
		system("cls");


		cout << endl;
		cout << "w : up  " << "\t0. blank" << endl;									//wasd : move
		cout << "a : left" << "\t1. wall" << endl;									//1~9 : select object
		cout << "s : down" << "\t2. charater" << endl;
		cout << "d : right" << "\t3. portal" << endl;
		cout << "\t\t" << "4~?. enemy" << endl << endl;
		cout << "j : save state\tk : delete state" << endl;
		cout << "q : save and exit editor" << endl;

		currentLocation = inputCursor->GetCharacterLocation();
		cout << "x : " << currentLocation[0] << "\ty : " << currentLocation[1] << endl << endl;


		editorMap->PrintMap();

		cout << inputKey << endl;
		inputKey = _getch();

		//save state
		if (inputKey == '0') {										//0 : blank
			currentState.SetState(0);
		}
		else if (inputKey == '1') {									//1 : wall
			currentState.SetState(1);
		}
		else if (inputKey == '2') {									//2 : character
			currentState.SetState(2);
		}
		else if (inputKey == '3') {									//3 : portal
			currentState.SetState(3);
		}
		else if (inputKey == '4') {									//4 ~ 9 : enemy ÀÏ´Ü 45¸¸
			currentState.SetState(4);
		}
		else if (inputKey == '5') {
			currentState.SetState(5);
		}

		editorMap->SetMapData(currentLocation[0], currentLocation[1], currentState);



		//move
		switch (inputKey)
		{
		case 'A':
		case 'a':
			// Move character
			editorMap->SetMapData(currentLocation[0], currentLocation[1], previousState);
			inputCursor->AddCharacterOffset(-1, 0, editorMap->GetMapSize());
			previousState = (editorMap->GetMapData(currentLocation[0], currentLocation[1]));

			break;
		case 'D':
		case 'd':
			// Move character
			editorMap->SetMapData(currentLocation[0], currentLocation[1], previousState);
			inputCursor->AddCharacterOffset(1, 0, editorMap->GetMapSize());
			previousState = (editorMap->GetMapData(currentLocation[0], currentLocation[1]));
			break;

		case 'W':
		case 'w':
			// Move character
			editorMap->SetMapData(currentLocation[0], currentLocation[1], previousState);
			inputCursor->AddCharacterOffset(0, 1, editorMap->GetMapSize());
			previousState = editorMap->GetMapData(currentLocation[0], currentLocation[1]);
			break;

		case 'S':
		case 's':
			// Move character
			editorMap->SetMapData(currentLocation[0], currentLocation[1], previousState);
			inputCursor->AddCharacterOffset(0, -1, editorMap->GetMapSize());
			previousState = (editorMap->GetMapData(currentLocation[0], currentLocation[1]));
			break;

		//save and delete state
		case 'j':
		case 'J':
			previousState = currentState;

			if (currentState.GetState() == 2) {
				tempLocation = character->GetCharacterLocation();
				if (tempLocation[0] != -1) {
					tempNode.SetState(0);
					editorMap->SetMapData(tempLocation[0], tempLocation[1],tempNode);
				}
				character->SetCharacterLocation(currentLocation[0], currentLocation[1]);
			}
			else if (currentState.GetState() == 3) {
				tempLocation = portal->GetCharacterLocation();
				if (tempLocation[0] != -1) {
					tempNode.SetState(0);
					editorMap->SetMapData(tempLocation[0], tempLocation[1], tempNode);
				}
				portal->SetCharacterLocation(currentLocation[0], currentLocation[1]);
			}

			break;
		case 'k':
		case 'K':
			previousState.SetState(0);
			break;

		//exit
		case 'q':
		case 'Q':
			editEnded = true;
			break;
		}


		editorMap->SetMapData(currentLocation[0], currentLocation[1], currentState);

		
		inputKey = 0;
	}
	Node** tempData = editorMap->GetData();
}

Map* EditMap::GetMap() {
	return editorMap;
}

EditMap::~EditMap() {
	delete editorMap;
	delete inputCursor;
	delete character;
	delete portal;
	delete tempLocation;
	delete currentLocation;
}