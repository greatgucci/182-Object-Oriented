#include "Character.h"
#include "Map.h"

Character::Character(Node* node) : Entity(node)
{
	num = 2;
	life = 3;
}

int Character::GetLife() const
{
	return life;
}

void Character::AddLife(int offset)
{
	life += offset;
}