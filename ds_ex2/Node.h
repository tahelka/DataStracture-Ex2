#ifndef __NODE_H
#define __NODE_H

class Node
{
	float bridgeHeight;
	Node* next;

public:
	// Constructor:
	Node(float _bridgeHeight, Node* const _next = nullptr) : bridgeHeight(_bridgeHeight), next(_next) {}

	// Getters:

	// This method is used to get the next node in the path.
	Node* const getNext() const;
	// This method is used to get the height of the bridge.
	float getBridgeHeight() const;

	// Setters:

	// This method is used to set the next node in the path.
	void setNext(Node* const _next);
	// This method is used to set the height of the bridge.
	void setBridgeHeight(float bridgeHeight);
};


#endif