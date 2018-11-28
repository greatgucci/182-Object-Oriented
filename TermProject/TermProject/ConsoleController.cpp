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
	// ���� ��� 
	sr.Left = 0; 
	sr.Top = 0; 
	// ���� �ϴ� (1�� ���ִ� ������ ���� �ϴ��� ��ġ�̱� ����) 
	sr.Right = w-1; 
	sr.Bottom = h-1; 
	SetConsoleScreenBufferSize(hout, temp); // 999x999 (�ִ���) ���� ũ�⸦ ��� �� �� 
	SetConsoleWindowInfo(hout, TRUE, &sr); // â�� ũ�⸦ ���Ѵ�. 
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