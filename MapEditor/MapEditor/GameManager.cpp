#include "GameManager.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

GameManager::GameManager()
{
	bIsEnded = false;
	previousTime = clock();
	currentTime = clock();
	// Get map data from file
	// Set map data
	// Starting a game
	StartGame();
}

void GameManager::StartGame()
{
	// Initialize data
	map = new Map(10, 10);	// This map size will be changed by map file's size
	character = new Character();


	char inputKey = 0;

	// Main Game
	while(!bIsEnded)
	{
		currentTime = clock();

		/** when key is pressed in correct time */
		if(currentTime - previousTime >= 400 && _kbhit())
		{
			if(GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState('a') & 0x8000)
			{
				inputKey = 'A';
			}
			else if(GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState('d') & 0x8000)
			{
				inputKey = 'D';
			}
			else if(GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState('w') & 0x8000)
			{
				inputKey = 'W';
			}
			else if(GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState('s') & 0x8000)
			{
				inputKey = 'S';
			}
			// For test
			else if(GetAsyncKeyState('Q') & 0x8000 || GetAsyncKeyState('q') & 0x8000)
			{
				inputKey = 'Q';
			}
		}

		/** Iterate every 0.5 second */
		if(currentTime - previousTime >= 500)
		{
			// Initialize data
			system("cls");
			cout << "before : " << currentTime - previousTime << endl;
			previousTime = clock();
			currentTime = clock();
			
			// Move character
			switch(inputKey)
			{
			case 'A':
			case 'a':
				// Move character
				character->AddCharacterOffset(-1, 0, map->GetMapSize());
				break;

			case 'D':
			case 'd':
				// Move character
				character->AddCharacterOffset(1, 0, map->GetMapSize());
				break;

			case 'W':
			case 'w':
				// Move character
				character->AddCharacterOffset(0, 1, map->GetMapSize());
				break;

			case 'S':
			case 's':
				// Move character
				character->AddCharacterOffset(0, -1, map->GetMapSize());
				break;

				// test for quiting game
			case 'Q':
			case 'q':
				bIsEnded = true;
				break;
			}
			cout << "Input Key is : " << inputKey << endl;

			// Update Map data
			map->InitializeMap();
			int* cLocation = character->GetCharacterLocation();	// character location. 0 : x, 1 : y.
			map->SetMapData(cLocation[0], cLocation[1], 1);	// Synchronize map's character location with real character location.
			cout << "character location : " << cLocation[0] << " , " << cLocation[1] << endl;

			// Update ObstacleList's data

			// Print Map data
			cout << "after : " << currentTime - previousTime << endl;
			map->PrintMap(character->GetCharacterLocation());

			inputKey = 0;
		}
	}
}

GameManager::~GameManager()
{
	delete map;
	delete character;
	delete obstacleList;
}