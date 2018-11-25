#pragma once
#include "Entity.h"

//Player Class
class Character : public Entity
{
public:
	Character(Node* node);
	Character();
	// Get and Set Location
	int* GetCharacterLocation();
	void AddCharacterOffset(int xOffset, int yOffset, int* moveLimit);
	void SetCharacterLocation(int xOffset, int yOffset);
	void MoveToNode(Node *target);
	
private:
	// Data
	int* location;	// 0 : x, y : 1. *Each values can have between 0 ~ (mapSize - 1).
};