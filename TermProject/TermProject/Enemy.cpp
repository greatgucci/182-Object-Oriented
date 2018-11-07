#include "Enemy.h"
#include "PathFinder.h"
#include "GameManager.h"
void Enemy :: Attack()	//CHECK if Player is Near, if true then GameOver
{

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
	switch (act)
	{
	case 0:
		//오른쪽으로 이동
		break;
	case 1:
		//아래로 이동
		break;
	case 2:
		//왼쪽으로 이동
		break;
	case 3:
		//위로 이동
		break;
	default:
		break;
	}
}
#pragma endregion

