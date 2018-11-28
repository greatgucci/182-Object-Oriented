#include "Enemy.h"
#include "PathFinder.h"
#include "GameManager.h"
void Enemy :: Attack()
{
	GameManager::instance->DecreaseLife();
	GameManager::instance->ResetPosition();
}
bool Enemy::CheckPlayer(char range)
{
	char pX = GameManager::instance->GetCharacterNode()->GetX();
	char pY = GameManager::instance->GetCharacterNode()->GetY();

	char distance = abs(GetX() - pX) + abs(GetY() - pY);//Player와의 거리

	if (distance <= range)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Enemy::MoveToNode(Node *target)
{
	if (target == nullptr || target->GetState() != 0)//이동하려는칸이 빈칸이 아니라면 리턴
	{
		return;
	}

	currentNode->SetState(0);
	currentNode = target;
	currentNode->SetState(num);
}
Enemy::Enemy(Node* node) : Entity(node)
{

}
#pragma region Snake
Snake::Snake(Node* node) : Enemy(node)
{
	num = 3;
	bIsActivated = false;
}
void Snake::DoAct() 	//PathFinder로 길찾기
{
	if (!bIsActivated)
	{
		if(CheckPlayer(5)) {bIsActivated = true;}
	}
	else if (CheckPlayer(1))
	{
		Attack();
	}
	else {MoveToNode(PathFinder::GeneratePath(currentNode, GameManager::instance->GetCharacterNode()));}
}
#pragma endregion

#pragma region Bat
Bat::Bat(Node* node) : Enemy(node)
{
	num = 4;
}
void Bat::DoAct()
{
	Node* target;
	switch (act)
	{
	case 0:
		target = GameManager::instance->GetMap()->GetNode(GetX() + 1, GetY());
		if (target == nullptr)
		{
			break;
		}
		else if (target->GetState() == 2)
		{
			Attack();
		}
		MoveToNode(target);
		break;
	case 1:
		target = GameManager::instance->GetMap()->GetNode(GetX(), GetY()-1);
		if (target == nullptr)
		{
			break;
		}
		else if (target->GetState() == 2)
		{
			Attack();
		}
		MoveToNode(target);
		//아래로 이동
		break;
	case 2:
		target = GameManager::instance->GetMap()->GetNode(GetX() - 1, GetY());
		if (target == nullptr)
		{
			break;
		}
		else if (target->GetState() == 2)
		{
			Attack();
		}
		MoveToNode(target);
		//왼쪽으로 이동
		break;
	case 3:
		target = GameManager::instance->GetMap()->GetNode(GetX(), GetY()+1);
		if (target == nullptr)
		{
			break;
		}
		else if (target->GetState() == 2)
		{
			Attack();
		}
		MoveToNode(target);
		//위로 이동
		break;
	default:
		break;
	}
	act++;
	if (act >= 4)
	{
		act = 0;
	}
}
#pragma endregion

