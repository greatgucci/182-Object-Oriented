#pragma once
#include "Node.h"
 class Entity
{

protected:
	char num;
	Node* currentNode;
public :
	Entity(Node* node);
	virtual void MoveToNode(Node *target) = 0;
	//virtual bool MoveToNode(Node *target);
	int GetX() const;
	int GetY() const;
};