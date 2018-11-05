#pragma once
#include <iostream>
#include "GameManager.h"
#include "MapEditor.h"
#include <conio.h>
using namespace std;

int main()
{
	/** Declaring data(file, map, and so on) */
	char selectMode;
	
	/** Select Menu */
	cout << "Welcome To This GAME!" << endl << endl << "1. Start" << endl << endl << "2. Edit a map" << endl;
	selectMode = _getch();
	while(!(selectMode == '1' || selectMode == '2'))
		selectMode = _getch();

	// When the correct key is pressed
	if(selectMode == '1')	// If Start mode
	{
		GameManager* gameManager = new GameManager();
	}
	else	// If Editing mode
	{
		MapEditor* mapEditor = new MapEditor();
	}
	
	system("pause");
	
	return 0;
}

/** Function */
// Get File function