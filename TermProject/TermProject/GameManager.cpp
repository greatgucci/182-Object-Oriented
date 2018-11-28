#include "GameManager.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "PathFinder.h"
#include "Enemy.h"
#include "ConsoleController.h"

using namespace std;
#define SLOT_NAME TEXT("\\\\.\\mailslot\\data")
GameManager* GameManager::instance = nullptr;

GameManager::GameManager(Map* gotMap)
{
	instance = this;
	bIsEnded = false;
	previousTime = clock();
	currentTime = clock();
	map = gotMap;
	// Starting a game
	StartGame();
}


void GameManager::MakeEnemies()
{
	
	int* siz = map->GetMapSize();//0 -> width, 1-> height
	Node** d = map->GetMapData();

	ec = new EnemyController();

	for (int i = 0; i < siz[1]; i++)
	{
		for (int j = 0; j < siz[0]; j++)
		{
			if (d[i][j].GetState() == 3)
			{
				Enemy* e = (Enemy*)new Snake(&d[i][j]);
				ec->AddEnemy(e);
			}
			else if (d[i][j].GetState() == 4)
			{
				Enemy* e = (Enemy*)new Bat(&d[i][j]);
				ec->AddEnemy(e);
			}
		}
	}
}

void GameManager::StartGame()
{
	// Initialize data
	MakeEnemies();
	character = new Character(map->FindNode(2));
	// Create New Console
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));
	CreateConsole("RhythmWindow.exe", pi);
	// Create Mailslot
	HANDLE hMailSlot;
	char rhythmData[4];
	DWORD bytes;
	hMailSlot = CreateMailslot(SLOT_NAME, 0, MAILSLOT_WAIT_FOREVER, NULL);

	char cPos[2] = {0};

	char inputKey = 0;
	int tickTime = 100;
	int currentTimeIndex = 0;
	previousTime = clock();

	map->PrintMap(character->GetX(),character->GetY(), character);
	// Main Game
	while(!bIsEnded)
	{
		// Get data from rhythm window program.
		if(!ReadFile(hMailSlot, rhythmData, 3, &bytes, NULL))
		{
			cout << "Unable to read";
			bIsEnded = true;
		}
		rhythmData[bytes/sizeof(char)] = NULL;

		currentTime = clock();

		if(rhythmData[0] == 1)
		{
			system("cls");

			previousTime = clock();
			currentTime = clock();
			cPos[0] = character->GetX();
			cPos[1] = character->GetY();

			// Move character
			switch(rhythmData[1])
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
			}

			// Update Enemies
			ec->CommandAll();

			// Print Map data
			map->PrintMap(character->GetX(),character->GetY(), character);

			// For Calculating Score
			currentTimeIndex++;
		}
	}
	system("cls");
	SetTextColor(15);
	// Game end
	if(bWin)
	{
		SetFont(15);
		SetConsoleLocation(600, 400);
		SetConsoleSize(40, 5);
		SetTextColor(15);
		cout << "WIN!" << endl << "Score : " << (2000 - currentTimeIndex*7) << endl;
	}
	else
	{
		SetFont(15);
		SetConsoleLocation(600, 400);
		SetConsoleSize(40, 5);
		SetTextColor(15);
		cout << "LOSE..." << endl;
	}
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	CloseHandle(hMailSlot);
}

GameManager::~GameManager()
{
	delete map;
	delete character;
	//delete obstacleList;
	instance = nullptr;
}

/** Public */
Map* GameManager::GetMap() const
{
	return map;
}

Node* GameManager::GetCharacterNode() const
{
	return map->GetNode(character->GetX(), character->GetY());
}

void GameManager::DecreaseLife()
{
	character->AddLife(-1);
	if(character->GetLife() < 1) {GameOver();}
}

void GameManager::GameWin()
{
	//명선이형 구현~
	bIsEnded = true;
	bWin = true;
}
void GameManager::GameOver()
{
	//명선이형 구현~
	bIsEnded = true;
	bWin = false;
}

void GameManager::ResetPosition()
{
	character->MoveToNode(map->GetNode(character->GetInitX(), character->GetInitY()));
}