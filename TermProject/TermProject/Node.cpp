#include "Node.h"
Node::Node()
{
	state = 0;
}
Node::~Node()
{
	delete[] neighbours;
}
char Node::GetState () const
{
	return state;
}
char Node::GetX() const
{
	return x;
}
char Node::GetY() const
{
	return y;
}
void Node::SetState(char c)
{
	state = c;
}
void Node::SetPosition(char posX, char posY)
{
	x = posX;
	y = posY;
}

#pragma region PathFinder
Node* Node::GetPrev() const
{
	return prev;
}
int Node::GetDistance() const
{
	return distance;
}
void Node::SetPrev(Node* node)
{
	prev = node;
}
void Node::SetDistance(int d)
{
	distance = d;
}
void Node::AddNeighbour(Node* n,char c)
{
	neighbours[c] = n;
}
Node* Node::GetNeighbour(char count) const
{
	return neighbours[count];
}

void Node::SetPathState(char c)
{
	pathFindingState = c;
}
char Node::GetPathState()
{
	return pathFindingState;
}

bool NodeCompare::operator() (Node*a, Node* b)
{
	if (a->GetDistance() > b->GetDistance())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#pragma endregion

