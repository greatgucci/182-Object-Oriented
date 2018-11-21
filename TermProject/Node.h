#include <list>
#pragma once
class Node
{
	char state;//0 = None , 1 = Block, 2 = Player ,3 = Snake , 4=Bat, 9=GameWin
	char x, y;

#pragma region  PathFinder
	Node* prev;//for PathFinding
	short distance;//for PathFinding;
	Node* neighbours[4];//for PathFinding;
	char pathFindingState = 0; //0-> none , 1-> open , 2->closed
#pragma endregion



public:
	Node();
	~Node();
	void SetPosition(char x, char y);
	void SetState(char c);
	char GetX() const;
	char GetY() const;
	char GetState() const;

#pragma region  PathFinder
	void SetPrev(Node* node);
	void SetDistance(int d);
	Node* GetPrev() const;
	int GetDistance() const;
	void AddNeighbour(Node*n , char c);
	Node* GetNeighbour(char count)const;
	void SetPathState(char c);
	char GetPathState();
#pragma endregion


};


class NodeCompare
{
public :
	bool operator() (Node* a, Node* b);
};