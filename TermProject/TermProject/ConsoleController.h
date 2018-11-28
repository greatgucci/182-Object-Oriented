#pragma once
#include <iostream>
#include <fstream>
#include <io.h>
#include <Windows.h>

void CreateConsole(const char* programName, PROCESS_INFORMATION pi);
void SetConsoleLocation(int x, int y);
void SetConsoleSize(int w, int h);
void SetTextColor(int color_number);
void SetFont(int fontSize);