#ifndef __LIST_H
#define __LIST_H
#include <iostream>
#include <iomanip>
#include "Node.h"

#define DUMMY_HEAD_HEIGHT 0

class List
{
	Node* head;
	Node* tail;

	// Private Methods:

	// This method is used to insert new node after a specific node
	void insertAfter(Node* const after, Node* const newNode);

	// Setters:

	// This method is used to set the head of the list
	void setHead(Node* const _head);
	// This method is used to set the tail of the list
	void setTail(Node* const _tail);

public:
	// Consturctor
	List();
	// Destructor
	~List();

	// Getters:

	// This method is used to get the head of the list
	Node* const getHead()			const;
	// This method is used to get the tail of the list
	Node* const getTail()			const;

	// Methods:

	// This method is used to check if the list is empty
	bool isEmpty()		const;
	// This method is used to insert new data to the list
	void insertDataToEndList(float bridgeHeight, Node* const next);
	// This method is used to print the list
	void printList()	const;	
	// This method is used to find a node in list
	Node* const findNode(float bridgeHeight);
	// This method is used to make the list empty
	void makeEmpty();
	// This method is used to delete a node that comes after a specific node
	void deleteAfter(Node* const after);
};

#endif