#include "Node.h"
Node::Node()
{
	state = 0;
	x = 0;
	y = 0;
}
Node::~Node()
{

}
char Node::GetState ()
{
	return state;
}
char Node::GetX()
{
	return x;
}
char Node::GetY()
{
	return y;
}
void Node::SetState(char c)
{
	state = c;
}
void Node::SetPosition(char posX, char posY)
{
	x = posX;
	y = posY;
}