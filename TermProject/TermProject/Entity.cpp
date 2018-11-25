#include "Entity.h"


 Entity::Entity(Node* node) :currentNode(node)
 {
 }
 int Entity::GetX() const
 {
	 return currentNode->GetX();
 }
 int Entity::GetY() const
 {
	 return currentNode->GetY();
 }