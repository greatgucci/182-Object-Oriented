#include "Entity.h"

 bool Entity::MoveToNode(Node *target)
{
	 if (target == nullptr || target->GetState() != 0)//�̵��Ϸ���ĭ�� ��ĭ�� �ƴ϶�� ����
	 {
		 return false;
	 }
	 if (target->GetState() == 10 && num == 2)
	 {
		 //GAMEWIN!!
	 }
	 currentNode->SetState(0);
	 currentNode = target;
	 currentNode->SetState(num);
	 return true;
}
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