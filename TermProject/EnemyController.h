#pragma once
#include <list>
#include "Enemy.h"
using namespace std;

class EnemyController
{
	
private :
	list<Enemy*> enemies;
	list<Enemy*> ::iterator iter;

public:
	~EnemyController();
	void AddEnemy(Enemy* enemy);
	void CommandAll();
};