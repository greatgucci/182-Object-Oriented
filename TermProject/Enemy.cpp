#include "Enemy.h"
#include "PathFinder.h"
#include "GameManager.h"
bool Enemy :: Attack()	//CHECK if Player is Near, if true then GameOver
{
	Node* v = GameManager::instance->GetMap()->GetNode(GetX() + 1, GetY());
	if (v != nullptr && v->GetState() ==2 )
	{
		GameManager::instance->DecreaseLife();
		return true;
	}
	v = GameManager::instance->GetMap()->GetNode(GetX() - 1, GetY());
	if (v != nullptr && v->GetState() == 2)
	{
		GameManager::instance->DecreaseLife();
		return true;
	}
	v = GameManager::instance->GetMap()->GetNode(GetX(), GetY()+1);
	if (v != nullptr && v->GetState() == 2)
	{
		GameManager::instance->DecreaseLife();
		return true;
	}
	v = GameManager::instance->GetMap()->GetNode(GetX(), GetY()-1);
	if (v != nullptr && v->GetState() == 2)
	{
		GameManager::instance->DecreaseLife();
		return true;
	}
	return false;
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
	Attack();
	MoveToNode(PathFinder::GeneratePath(currentNode,GameManager::instance->GetCharacterNode()));
}
#pragma endregion

#pragma region Bat
Bat::Bat(Node* node) : Enemy(node)
{
	num = 4;
}
void Bat::DoAct()
{
	Attack();
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

