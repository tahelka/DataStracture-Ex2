#ifndef __ROAD_H
#define __ROAD_H
#include "List.h"

class Road
{
	List bridges; // list of all bridges on this road.
	int pairIndex; // index of the pair that represents this road on the heap.

public:
	// Getters:

	// This method is used to get the index of the pair that represents this road on the heap.
	int getPairIndex() const;
	List& getBridges();

	// Setters:

	// This method is used to set the index of the pair that represents this road on the heap.
	void setPairIndex(int index);
};

#endif