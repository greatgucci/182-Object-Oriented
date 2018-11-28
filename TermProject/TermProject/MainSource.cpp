#pragma once
#include "GameManager.h"
#include "MapEditor.h"
#include "ConsoleController.h"
#include <conio.h>
using namespace std;

int main()
{
	// Set console attributes
	SetConsoleTitle("Rhythm Adventurer");
	SetFont(15);
	SetConsoleLocation(200, 100);
	SetConsoleSize(60, 18);
	SetTextColor(15);

	char selectMode = 0;
	/** Select Menu */
	while(selectMode != '1')
	{
		system("cls");
		cout << "\n\n\n\n\t■■■■■■■■■■■■■■■■■■■■■■\n" << "\t■\t\t\t\t\t  ■\n" << "\t■\tWELCOME TO RHYTHM ADVENTURER!\t  ■\n" << "\t■\t\t\t\t\t  ■\n" << "\t■\t\t1. Start\t\t  ■\n" << "\t■\t\t\t\t\t  ■\n" << "\t■\t       2. Edit Map\t\t  ■\n" << "\t■\t\t\t\t\t  ■\n" << "\t■■■■■■■■■■■■■■■■■■■■■■" << endl;
		selectMode = _getch();
		while(!(selectMode == '1' || selectMode == '2')) {selectMode = _getch();}

		// When the correct key is pressed
		if(selectMode == '1')	// If Start mode
		{
			system("cls");
			SetConsoleLocation(400, 130);
			SetConsoleSize(25,8);
			SetFont(40);
			srand(time(NULL));
			Map* selectedMap = Map::SelectMap();
			if(selectedMap != NULL)
			{
				GameManager* gameManager = new GameManager(selectedMap);	// Start Game
			}
		}
		else if(selectMode == '2')	// If Editing mode
		{
			// 기존 콘솔 위치 및 크기 조정(숨기기)
			//SetConsoleLocation(-500, 0);
			SetConsoleSize(10, 10);
			//MapEditor* mapEditor = new MapEditor();
			//CreateConsole("MapEditor.exe");
			//WaitForSingleObject();
		}
	}
	
	system("pause");
	
	return 0;
}