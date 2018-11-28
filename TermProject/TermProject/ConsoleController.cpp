#include "ConsoleController.h"

// Console Functions
void CreateConsole(const char* programName, PROCESS_INFORMATION pi)
{
	/** Create new console */
	STARTUPINFO si;
	//PROCESS_INFORMATION pi;
	char* name = new char[20];
	strcpy_s(name, 20, programName);

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	//ZeroMemory(&pi, sizeof(pi));
	// Create Process
	if ( !CreateProcess(NULL, name, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi) )
	{
		printf("CreateProcess failed (%d)\n", GetLastError());
		return;
	}
	// Close Process and Handle
	//CloseHandle(pi.hProcess);
	//CloseHandle(pi.hThread);
}

void SetConsoleLocation(int x, int y)
{
	HWND hWnd_console;

	hWnd_console = GetConsoleWindow();
	SetWindowPos(hWnd_console, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}

void SetConsoleSize(int w, int h)
{ 
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
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
} 

void SetTextColor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void SetFont(int fontSize)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.X = fontSize;	// Width of each character in the font
	cfi.dwFontSize.Y = fontSize*2;	// Height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}