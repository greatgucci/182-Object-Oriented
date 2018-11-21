#pragma once
#include <iostream>
#include <fstream>
#include "GameManager.h"
#include "MapEditor.h"
#include <conio.h>
#include <Windows.h>
#include "MultipleConsoles_src/ConsoleLogger.h"
using namespace std;

HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

Map* SelectMap();
void resz(int w, int h);

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
		resz(70,35);
		Map* selectedMap = SelectMap();
		if(selectedMap != NULL)
		{
			/** Create new console */
			STARTUPINFO si;
			PROCESS_INFORMATION pi;
			char* name = new char[20];
			strcpy_s(name, 20, "test.exe");

			ZeroMemory(&si, sizeof(si));
			si.cb = sizeof(si);
			ZeroMemory(&pi, sizeof(pi));
			// Create Process
			if ( !CreateProcess(NULL, name, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi) )
			{
				printf("CreateProcess failed (%d)\n", GetLastError());
				return 1;
			}
			// Close Process and Handle
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);

			/** Start Game*/
			GameManager* gameManager = new GameManager(selectedMap);
		}
	}
	else	// If Editing mode
	{
		resz(70,35);
		MapEditor* mapEditor = new MapEditor();
	}
	
	system("pause");
	
	return 0;
}

/** Function */
// Get File function
Map* SelectMap()
{
	char* csvFileList[100];
	int csvFileCount = 0;
	char* selectedFilePath;
	// Select a map of csv list
	_finddatai64_t c_file;
	intptr_t hFile;

	if((hFile = _findfirsti64("*.csv", &c_file)) == -1L)
	{
		cout << "No files in that directory"<< endl;
	}
	else
	{
		do
		{
			csvFileList[csvFileCount] = c_file.name;
			csvFileCount++;
			//cout<< csvFileList[csvFileCount-1] <<endl;
		} while(_findnexti64(hFile, &c_file) == 0);
		_findclose(hFile);
	}
	selectedFilePath = csvFileList[rand() % csvFileCount];
	cout << "The selected map is " << selectedFilePath << endl;

	// Read Map Data
	ifstream ReadFile(selectedFilePath);
	try
	{
		if(ReadFile.is_open() == true)
		{
			cout << "Read success!" << endl;
			char sizeStr[10];
			ReadFile.getline(sizeStr, 10);
			
			/** Get length of sizeStr */
			int length = 0;
			while(sizeStr[length] != NULL) {length++;}
			
			/** Devide sizeStr to widthStr, heightStr */
			int cIndex = 0;
			while(sizeStr[cIndex] != ',') {cIndex++;}
			int width = 0, height = 0;
			for(int i = 0; i < cIndex; i++)
			{
				width += (sizeStr[i] - '0') * (int)pow(10, (cIndex - 1 - i));
			}
			for(int i = cIndex + 1; i < length; i++)
			{
				height += (sizeStr[i] - '0') * (int)pow(10, (length - 1 - i));
			}
			cout << "width : " << width << "height : " << height << endl;

			/** Get map data from file */
			// Initialize the temp map data
			char** mapData;
			mapData = new char*[height];
			for(int heightIndex = 0; heightIndex < height; heightIndex++)
			{
				mapData[heightIndex] = new char[width];
			}
			// Set the temp map data from file
			for(int i = 0; i < height; i++)
			{
				char* ithDataStr = new char[width*2 - 1];	// includes number of comma
				ReadFile.getline(ithDataStr, width*2);
				for(int i2 = 0; i2 < width*2 - 1; i2+=2)
				{
					mapData[i][i2/2] = ithDataStr[i2];
				}
			}

			ReadFile.close();

			// Copy to Map Data
			Map* selectedMap = new Map(width, height);
			selectedMap->CreateMap(mapData);

			return selectedMap;
		}
		else
		{
			throw false;
		}
	}
	catch(bool)
	{
		cout << "Read Failed!" << endl;
	}

	return NULL;
}

// Console Functions
void resz(int w, int h){ // 열, 행 
	COORD temp = {999, 999}; 
	COORD siz={w,h}; 
	SMALL_RECT sr; 
	// 좌측 상단 
	sr.Left = 0; 
	sr.Top = 0; 
	// 우측 하단 (1을 빼주는 이유는 우측 하단의 위치이기 때문) 
	sr.Right = w-1; 
	sr.Bottom = h-1; 
	SetConsoleScreenBufferSize(hout, temp); // 999x999 (최대한) 버퍼 크기를 잡아 준 후 
	SetConsoleWindowInfo(hout, TRUE, &sr); // 창의 크기를 정한다. 
	SetConsoleScreenBufferSize(hout, siz); 
	printf("크기 설정 완료 %d*%d",w,h); 
} 