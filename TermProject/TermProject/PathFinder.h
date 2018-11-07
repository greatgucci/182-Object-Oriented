#pragma once
#include "Node.h"
 class PathFinder
{	
private:
	static int CostToEnterTile(Node* source, Node* target);
	static int CalculateDistance(Node* a,  Node* b);

public :
	static Node* GeneratePath(Node* source, Node* target);

};