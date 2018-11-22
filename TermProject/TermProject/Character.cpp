#include "Character.h"
#include "Map.h"

Character::Character(Node* node) : Entity(node)
{
	location = new int[2];
	location[0] = 0, location[1] = 0;
}

int* Character::GetCharacterLocation()
{
	return location;
}

void Character::SetCharacterLocation(int xOffset, int yOffset) {	// for exception handling change form "+=" to "=" by cho
	location[0] = xOffset;
	location[1] = yOffset;
}

void Character::AddCharacterOffset(int xOffset, int yOffset, int* moveLimit)
{
	location[0] += xOffset;
	location[1] += yOffset;
	// Adjust location
	if(location[0] < 0) {location[0] = 0;}
	else if(location[0] > moveLimit[0] - 1) {location[0] =  moveLimit[0] - 1;}
	if(location[1] < 0) {location[1] = 0;}
	else if(location[1] > moveLimit[1] - 1) {location[1] =  moveLimit[1] - 1;}
}