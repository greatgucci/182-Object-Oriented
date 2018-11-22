#include <list>
#pragma once
class Node
{
	char state;//0 = None , 1 = Block, 2 = Player ,3 = Snake , 4=Bat, 9=GameWin
	char x, y;
public:
	Node();
	~Node();
	void SetPosition(char x, char y);
	void SetState(char c);
	char GetX() ;
	char GetY() ;
	char GetState() ;
};
