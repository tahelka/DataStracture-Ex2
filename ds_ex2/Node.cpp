#include "Node.h"


// Getters:

Node* const Node::getNext() const 
{
	return next;
}

float Node::getBridgeHeight() const
{
	return bridgeHeight;
}

// Setters:

void Node::setNext(Node* const _next)
{
	this->next = _next;
}

void Node::setBridgeHeight(float bridgeHeight)
{
	this->bridgeHeight = bridgeHeight;
}
