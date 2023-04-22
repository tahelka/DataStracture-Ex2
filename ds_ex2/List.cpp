#include "List.h"

// Constructor:
List::List()
{
    Node* dummyHead = new Node(DUMMY_HEAD_HEIGHT, nullptr);
    setHead(dummyHead);
    setTail(dummyHead);
}

// Destructor:
List::~List() 
{
    makeEmpty();
}

// Getters:
Node* const List::getHead()           const
{
    return head->getNext();
}

Node* const List::getTail()           const
{
    return tail;
}

// Setters:
void List::setHead(Node* const _head)
{
    this->head = _head;
}

void List::setTail(Node* const _tail)
{
    this->tail = _tail;
}

// Methods:

bool List::isEmpty() const 
{
	return head == tail; // If the head is the same as the tail, the list is empty.
}

void List::makeEmpty() 
{
    Node* temp = this->head;

    while (temp != nullptr)
    {
        this->head = this->head->getNext();
        delete temp;
        temp = this->head;
    }
}

void List::insertDataToEndList(float bridgeHeight, Node* const next)
{
    Node* newNode = new Node(bridgeHeight, next);
    this->insertAfter(getTail(), newNode);
}

void List::printList()	const {

    Node* temp = getHead();

    while (temp != nullptr)
    {
        std::cout << std::fixed << std::setprecision(4) << temp->getBridgeHeight() << " ";
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

void List::deleteAfter(Node* const after) 
{
    Node* temp = after->getNext();
    after->setNext(temp->getNext());
    delete temp;
}

Node* const List::findNode(float bridgeHeight) 
{
    Node* temp = getHead();

    while (temp != nullptr) 
    {
        if (temp->getBridgeHeight() == bridgeHeight) 
        {
            return temp;
        }
        temp = temp->getNext();
    }

    return nullptr;
}

void List::insertAfter(Node* const after, Node* const newNode)
{
    newNode->setNext(after->getNext());
    after->setNext(newNode);

    if (after == getTail())
        setTail(newNode);
}
