#pragma once
#include "Entity.h"

//Player Class
class Character : public Entity
{
public:
	Character(Node* node);
	int GetLife() const;
	void AddLife(int offset);
	void MoveToNode(Node *target);
	int GetInitX() const;
	int GetInitY() const;

private:
	int life;
	int initX, initY;
	
};