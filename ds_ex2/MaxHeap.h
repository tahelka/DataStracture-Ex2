#ifndef __MAXHEAP_H
#define __MAXHEAP_H
#include "Pair.h"
#include "Road.h"
#include "InvalidInputException.h"

enum { NO_HEIGHT = -1 };

class MaxHeap
{
	int	maxSize;
	int heapSize;
	Pair* maxHeapArray;

	// Private Methods:

	// This method is used to swap between two nodes in the heap.
	void swap(Road* const roadsArray, int nodeIndex1, int nodeIndex2) const;
	// This method is used to move a node to a higher level in the heap.
	void MoveNodeToHigherLevel(Road* const roadsArray, int& pairIndex) const;
	// This method is used to move a node to a lower level in the heap.
	bool MoveNodeToLowerLevel(Road* const roadsArray, int& pairIndex) const;
	// This method is used to update the index of a pair node in its matching road
	void updatePairIndexOfRoad(Road* const roadsArray, int pairIndex) const;
	// This method is used to determine if a node is smaller than its children.
	int isNodeSmallerThanItsChildren(int nodeIndex)	const;
	// This method is used to determine if a node is bigger than its parent.
	bool isNodeBiggerThanItsParent(int nodeIndex)	const;
	// This method is used to fix the heap when only the root is not in the right index.
	void fixHeap(Road* const roadsArray, int pairIndex) const;
	// This method is used to build the heap.
	void buildHeap(Road* const roadsArray, Pair* const arr, int size);
	// This method is used to find the parent of a node in the heap.
	static int parent(int nodeIndex);
	// This method is used to find the left child of a node in the heap.
	static int left(int nodeIndex);
	// This method is used to find the right child of a node in the heap.
	static int right(int nodeIndex);

public:
	// Constructor:
	MaxHeap(int maxSize);
	MaxHeap(Road* const roadsArray, Pair* const arr, int size);

	// Destructor:
	~MaxHeap();

	// Getters:
	
	// This method is used the get the array of pairs in the heap.
	Pair* const getMaxHeapArray();
	// This method is used to get the maximum size of the heap.
	int getMaxSize();
	// This method is used to get the current size of the heap.
	int getHeapSize();

	// Setters:

	// This method is used to set the heap size.
	void setHeapSize(int heapSize)	noexcept (false);

	// Methods:

	// This method is used to insert a new pair to the heap.
	void insert(Road* const roadsArray, Pair& newNode)	noexcept (false);
	// This method is used to return the maximum pair in the heap depending on priority.
	const Pair& max();
	// This method is used to delete the maximum pair in the heap (and return it).
	const Pair deleteMax(Road* const roads) noexcept (false);
	// This method is used to fix the heap when one node is not in the right index
	void genericFixHeap(Road* const roadsArray, int pairIndex)	noexcept (false);
};

#endif

