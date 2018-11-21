#pragma once
#include "Entity.h"

//Player Class
class Character : public Entity
{
public:
	Character(Node* node);
	int GetLife() const;
	void AddLife(int offset);

private:
	int life;
	
};