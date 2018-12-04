#include <list>
#pragma once
class Node
{
	char state;//0 = None , 1 = Block, 2 = Player ,3 = Snake , 4=Bat, 9=GameWin
	char x, y; //location
public:
	Node();
	~Node();
	void SetPosition(char x, char y); //set location
	void SetState(char c); //set state
	char GetX() ; // get x
	char GetY() ; // get y
	char GetState() ; // get state
};
