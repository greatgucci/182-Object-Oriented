#include "EnemyController.h"


void EnemyController::AddEnemy(Enemy* enemy)
{
	enemies.push_back(enemy);
}
void EnemyController::CommandAll()
{
	for (iter = enemies.begin(); iter != enemies.end(); iter++)
	{
		(*iter)->DoAct();
	}
}
EnemyController::~EnemyController()
{
	enemies.clear();
}