#include "PathFinder.h"
#include "GameManager.h"
#include <math.h>
#include <queue>
#include <iostream>

using namespace std;

 int PathFinder::CostToEnterTile(Node* v,Node* target)
{
	 if (v->GetState() != 0)
	 {
		 if (v == target)
		 {
			 return 1;
		 }
		 else
		 {
			 return 999999;
		 }
	 }
	 else
	 {
		 return 1;
	 }
}
int PathFinder::CalculateDistance(Node* a, Node* b)
{
	return abs((a->GetX()-b->GetX()))+ abs((a->GetY() - b->GetY()));
}
Node* PathFinder::GeneratePath(Node* source, Node* target)
{
	if (target == source)
	{
		return target;
	}

	Node** nodes = GameManager::instance->GetMap()->GetMapData();//ÃÊ±âÈ­
	int* mapSize = GameManager::instance->GetMap()->GetMapSize();//0-> width , 1->height
	for (int i = 0; i < mapSize[1]; i++)
	{
		for (int j = 0; j < mapSize[0]; j++)
		{
			nodes[i][j].SetPrev(nullptr);
			nodes[i][j].SetDistance(999999);
			nodes[i][j].SetPathState(0);
		}
	}

	priority_queue<Node*,vector<Node*>,NodeCompare> openList;

	openList.push(source);
	source->SetDistance(0);
	source->SetPathState(1);

	while (!openList.empty())
	{
		Node* current = openList.top();
		openList.pop();
		current->SetPathState(2);

		if (current == target)
		{
			break;
		}

		for (int i = 0; i < 4; i++)
		{

			Node* v = current->GetNeighbour(i);
			
			if (v == nullptr || v->GetPathState()==2 || CostToEnterTile(v,target) == 999999)
			{
				continue;
			}

			int alt = current->GetDistance() + CostToEnterTile(v,target) + CalculateDistance(v, target);
			if (alt < v->GetDistance() || v->GetPathState() == 0)
			{
				v->SetDistance(alt);
				v->SetPrev(current);
				if (v->GetPathState() == 0)
				{
					openList.push(v);
					v->SetPathState(1);
				}
			}
		}
	}
	if (target->GetPrev() == nullptr)
	{
		return nullptr;
	}

	Node* now = target;
	while (now != nullptr && now->GetPrev() != source)
	{
		now = now->GetPrev();
	}
	return now;
}