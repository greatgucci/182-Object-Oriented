#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public :
	void Attack();
	Enemy(Node *);
	virtual void DoAct() = 0;
};
class Snake : Enemy
{

public :
	Snake(Node*);
	void DoAct();
};
class Bat :Enemy
{
private:
	char act = 0;
public:
	Bat(Node*);
	void DoAct();
};