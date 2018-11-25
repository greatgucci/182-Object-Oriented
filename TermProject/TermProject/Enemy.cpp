#include "Enemy.h"
#include "PathFinder.h"
#include "GameManager.h"
#include <math.h>

void Enemy :: Attack()	//CHECK if Player is Near, if true then GameOver
{
	GameManager::instance->GameOver();
}
bool Enemy::CheckPlayer(char range)
{
	char pX = GameManager::instance->GetCharacterNode()->GetX();
	char pY = GameManager::instance->GetCharacterNode()->GetY();
	
	char distance = abs(GetX() - pX) + abs(GetY() - pY);
	
	if (range <= distance)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Character::MoveToNode(Node *target)
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
}
void Snake::DoAct() 	//PathFinder로 길찾기
{
	if (CheckPlayer(5))
	{
		Attack();
		MoveToNode(PathFinder::GeneratePath(currentNode, GameManager::instance->GetCharacterNode()));
	}
}
#pragma endregion

#pragma region Bat
Bat::Bat(Node* node) : Enemy(node)
{
	num = 4;
}
void Bat::DoAct()
{
	if (CheckPlayer(1))
	{
		Attack();
	}
	switch (act)
	{
	case 0:
		MoveToNode(GameManager::instance->GetMap()->GetNode(GetX()+1, GetY()));
		break;
	case 1:
		MoveToNode(GameManager::instance->GetMap()->GetNode(GetX(), GetY()-1));
		//아래로 이동
		break;
	case 2:
		MoveToNode(GameManager::instance->GetMap()->GetNode(GetX()-1, GetY()));
		//왼쪽으로 이동
		break;
	case 3:
		MoveToNode(GameManager::instance->GetMap()->GetNode(GetX(), GetY() + 1));
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

