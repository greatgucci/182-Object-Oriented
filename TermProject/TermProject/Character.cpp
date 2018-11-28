#include "Character.h"
#include "Map.h"
#include "GameManager.h"

Character::Character(Node* node) : Entity(node)
{
	num = 2;
	life = 5;
	initX = GetX(), initY = GetY();
}

int Character::GetLife() const
{
	return life;
}

void Character::AddLife(int offset)
{
	life += offset;
}

void Character::MoveToNode(Node *target)
{
	if (target == nullptr)//이동하려는칸이 빈칸이 아니라면 리턴
	{
		return;
	}

	if (target->GetState() == 1 || target->GetState() == 3 || target->GetState() ==4)
	{
		// Snake가 캐릭터 초기 위치에 있으면 버그 발생하므로 예외처리.
		if(!(target->GetState() == 3 && target->GetX() == initX && target->GetY() == initY))
		{
			MoveToNode(GameManager::instance->GetMap()->GetNode(initX, initY));
		}
		return;
	}
	else if (target->GetState() == 9)
	{
		//GAMEWIN!!
		GameManager::instance->GameWin();
		return;
	}

	currentNode->SetState(0);
	currentNode = target;
	currentNode->SetState(num);
}

int Character::GetInitX() const
{
	return initX;
}

int Character::GetInitY() const
{
	return initY;
}