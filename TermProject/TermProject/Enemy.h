#pragma once
#include "Entity.h"
class Enemy : public Entity
{
protected :
/*
	bool Attack();
*/
	void Attack();
	void MoveToNode(Node *target);
	bool CheckPlayer(char c);
public :
	Enemy(Node *);
	virtual void DoAct() = 0;
};
class Snake : Enemy
{

public :
	Snake(Node*);
	void DoAct();
private :
	bool bIsActivated;
};
class Bat :Enemy
{
private:
	char act = 0;
public:
	Bat(Node*);
	void DoAct();
};