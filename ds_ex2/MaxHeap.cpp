#include "MaxHeap.h"

// Constructor:
MaxHeap::MaxHeap(int maxSize)
{
	maxHeapArray = new Pair[maxSize];
	
	this->maxSize = maxSize;

	this->heapSize = 0;
}

MaxHeap::MaxHeap(Road* const roadsArray, Pair* const arr, int size)
{
	buildHeap(roadsArray, arr, size);
}

// Destructor:
MaxHeap::~MaxHeap()
{
	delete[] maxHeapArray;
}

// Getters;

Pair* const MaxHeap::getMaxHeapArray()
{
	return maxHeapArray;
}

int MaxHeap::getMaxSize()
{
	return maxSize;
}

int MaxHeap::getHeapSize()
{
	return heapSize;
}

// Setters:
void MaxHeap::setHeapSize(int heapSize) 
{
	if (heapSize > maxSize)
		throw InvalidInputException();

	this->heapSize = heapSize;
}

// Methods:

int MaxHeap::parent(int nodeIndex)
{
	return (nodeIndex - 1) / 2;
}

int MaxHeap::left(int nodeIndex)
{
	return (2 * nodeIndex + 1);
}

int MaxHeap::right(int nodeIndex)
{
	return (2 * nodeIndex + 2);
}

void MaxHeap::fixHeap(Road* const roadsArray, int pairIndex) const
{
	int max;
	int leftIndex = left(pairIndex);
	int rightIndex = right(pairIndex);

	// if node has left child and left child is bigger than node
	if (leftIndex < heapSize && maxHeapArray[leftIndex].getLowestBridgeHeight() > maxHeapArray[pairIndex].getLowestBridgeHeight()) {
		max = leftIndex;
	}
	else {
		max = pairIndex;
	}

	// if node has right child and right child is bigger than max
	if (rightIndex < heapSize && maxHeapArray[rightIndex].getLowestBridgeHeight() > maxHeapArray[max].getLowestBridgeHeight()) {
		max = rightIndex;
	}

	if (max != pairIndex) {
		swap(roadsArray, pairIndex, max);
		fixHeap(roadsArray, max);
	}
}

int MaxHeap::isNodeSmallerThanItsChildren(int nodeIndex)	const
{
	int leftIndex = left(nodeIndex);
	int rightIndex = right(nodeIndex);

	float leftHeight = NO_HEIGHT, rightHeight = NO_HEIGHT;
	float nodeHeight = maxHeapArray[nodeIndex].getLowestBridgeHeight();


	if (leftIndex < heapSize) // node has left child
	{
		leftHeight = maxHeapArray[leftIndex].getLowestBridgeHeight();
	}
	if (rightIndex < heapSize) // node has right child
	{
		rightHeight = maxHeapArray[rightIndex].getLowestBridgeHeight();
	}
	
	if (nodeHeight >= leftHeight && nodeHeight >= rightHeight)
	{
		return 0;
	}
	else
	{
		return leftHeight > rightHeight ? leftIndex : rightIndex;
	}

}

bool MaxHeap::isNodeBiggerThanItsParent(int nodeIndex) const
{
	
	float nodeLowestBridge = maxHeapArray[nodeIndex].getLowestBridgeHeight();

	if (nodeIndex != 0 && nodeLowestBridge > maxHeapArray[parent(nodeIndex)].getLowestBridgeHeight())
	{
		return true;
	}
	else // Node is smaller than its parent or its the root
	{
		return false;
	}
}

void MaxHeap::swap(Road* const roadsArray, int nodeIndex1, int nodeIndex2) const
{
	Pair temp = maxHeapArray[nodeIndex1];
	maxHeapArray[nodeIndex1] = maxHeapArray[nodeIndex2];
	maxHeapArray[nodeIndex2] = temp;
	
	updatePairIndexOfRoad(roadsArray, nodeIndex1);
	updatePairIndexOfRoad(roadsArray, nodeIndex2);
}

void MaxHeap::MoveNodeToHigherLevel(Road* const roadsArray, int& pairIndex)	const
{
	int parentIndex;

	while (pairIndex > 0 && isNodeBiggerThanItsParent(pairIndex))
	{
		parentIndex = parent(pairIndex);
		maxHeapArray[pairIndex] = maxHeapArray[parentIndex];
		updatePairIndexOfRoad(roadsArray, pairIndex); // update pair index of road
		pairIndex = parentIndex;
	}

}

bool MaxHeap::MoveNodeToLowerLevel(Road* const roadsArray, int& pairIndex)	const
{

    if (pairIndex == 0)
    {
        fixHeap(roadsArray, pairIndex);
		return false; // beacause fixheap is already taking care of the updating the pair node
    }
    else
    {
		int maxChildIndex;
		while (pairIndex < heapSize && (maxChildIndex = isNodeSmallerThanItsChildren(pairIndex)))
        {
            maxHeapArray[pairIndex] = maxHeapArray[maxChildIndex];
            updatePairIndexOfRoad(roadsArray, pairIndex); // update pair index of road
            pairIndex = maxChildIndex;
        } 
		return true;
    }
}

void MaxHeap::buildHeap(Road* const roadsArray, Pair* const arr, int size)
{
	heapSize = maxSize = size;

	maxHeapArray = new Pair[size];

	// Copy the array
	for (int i = 0; i < size; i++) {
		maxHeapArray[i] = arr[i];
	}

	// Fix the heap
	for (int i = (size / 2) - 1; i >= 0; i--) {
		fixHeap(roadsArray, i);
	}
}

void MaxHeap::updatePairIndexOfRoad(Road* const roadsArray, int pairIndex)	const
{
	roadsArray[maxHeapArray[pairIndex].getRoadIndex()].setPairIndex(pairIndex);
}

void MaxHeap::genericFixHeap(Road* const roadsArray, int pairIndex)
{
	bool updatePairNode = false;

	if (pairIndex < 0 || pairIndex >= heapSize)
		throw InvalidInputException();

	Pair node = maxHeapArray[pairIndex];

	// node is bigger than its parent
	if (pairIndex != 0 && isNodeBiggerThanItsParent(pairIndex))
	{
		MoveNodeToHigherLevel(roadsArray, pairIndex);
		updatePairNode = true;
	}
	// if node is smaller than its children (if exist)
	else if (isNodeSmallerThanItsChildren(pairIndex))
	{
		updatePairNode = MoveNodeToLowerLevel(roadsArray, pairIndex);
	}

	if (updatePairNode)
	{
		maxHeapArray[pairIndex] = node;
		updatePairIndexOfRoad(roadsArray, pairIndex);
	}


}

void MaxHeap::insert(Road* const roadsArray, Pair& newNode) 
{
	if (heapSize == maxSize)
		throw InvalidInputException();

	maxHeapArray[heapSize] = newNode;
	heapSize++;

	genericFixHeap(roadsArray, heapSize-1);
}

const Pair& MaxHeap::max()
{
	return maxHeapArray[0];
}

const Pair MaxHeap::deleteMax(Road* const roads)
{
	int index = 0;

	if (heapSize < 1) {
		throw InvalidInputException();
	}

	Pair max = maxHeapArray[index]; // getting the root (max)
	heapSize--;

	if (heapSize)
	{
		maxHeapArray[index] = maxHeapArray[heapSize];
		fixHeap(roads, index);
		updatePairIndexOfRoad(roads, index); // update pair index of road
	}
	
	return max;
}