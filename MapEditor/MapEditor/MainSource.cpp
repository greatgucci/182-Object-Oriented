#pragma once
#include <iostream>
#include "MapEditor.h"
#include <conio.h>
using namespace std;





int main()
{
	//set console size
	system("mode con: cols=40 lines=30");
	
	//call MapEditor
	MapEditor* mapEditor = new MapEditor();
	return 0;


}



/** Function */
// Get File function