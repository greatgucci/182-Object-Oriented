#include "GameManager.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "PathFinder.h"
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
	instance = this;
}

GameManager* GameManager::instance = nullptr;

Map* GameManager::GetMap() const
{
	return map;
}


void GameManager::StartGame()
{
	// Initialize data
	map = new Map(10, 10);	// This map size will be changed by map file's size
	character = new Character(map->GetNode(0,0));

	char cPos[2] = { 0 };

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
			cPos[0] = character->GetX();
			cPos[1] = character->GetY();

			// Move character
			switch(inputKey)
			{
			case 'A':
			case 'a':
				// Move character
				character->MoveToNode(map->GetNode(cPos[0]-1,cPos[1]));
				break;

			case 'D':
			case 'd':
				// Move character
				character->MoveToNode(map->GetNode(cPos[0] + 1, cPos[1]));
				break;

			case 'W':
			case 'w':
				// Move character
				character->MoveToNode(map->GetNode(cPos[0] , cPos[1]+1));
				break;

			case 'S':
			case 's':
				// Move character
				character->MoveToNode(map->GetNode(cPos[0], cPos[1]-1));
				break;

				// test for quiting game
			case 'Q':
			case 'q':
				bIsEnded = true;
				break;
			}
			cout << "Input Key is : " << inputKey << endl;
			cout << "C Pos : " << character->GetX() << " , " << character->GetY() << endl;

			// Update Enemies

			// Print Map data
			map->PrintMap(character->GetX(),character->GetY());
			cout << "after : " << currentTime - previousTime << endl;


			inputKey = 0;
		}
	}
}

GameManager::~GameManager()
{
	delete map;
	delete character;
	delete obstacleList;
	instance = nullptr;
}