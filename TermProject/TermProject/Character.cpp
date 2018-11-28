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
	if (target == nullptr)//�̵��Ϸ���ĭ�� ��ĭ�� �ƴ϶�� ����
	{
		return;
	}

	if (target->GetState() == 1 || target->GetState() == 3 || target->GetState() ==4)
	{
		// Snake�� ĳ���� �ʱ� ��ġ�� ������ ���� �߻��ϹǷ� ����ó��.
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