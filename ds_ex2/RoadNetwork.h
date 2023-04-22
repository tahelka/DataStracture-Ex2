#ifndef __ROADNETWORK_H
#define __ROADNETWORK_H

#include "Pair.h"
#include "Road.h"
#include "MaxHeap.h"


class RoadNetwork
{
	int numOfRoads;
	Road* roadsArray;
	MaxHeap roadsMaxHeap;

public:
	// Constructor:
	RoadNetwork(int numOfRoads);
	// Destructor:
	~RoadNetwork();

	// Getters:

	// This method is used to get the number of roads in the network
	int getNumOfRoads() const;
	// This method is used to get the array of roads in the network
	Road* const getRoadsArray();
	// This method is used to get the max heap of roads in the network
	const MaxHeap& getRoadsMaxHeap();

	// Methods:

	// This method is used to initialize the road network, done in O(numOfRoads) at worst case
	void init();
	// This method is used to add a bridge to the road network, done in O(log(numOfRoads)) at worst case
	void addBridge(float bridgeHeight, int roadNum);
	// This method is used to find the most suitable road for the truckHeight, done in Theta(1) at worst case
	void whichRoad(float truckHeight);
	// This method is used to print all the bridges on a specific road, done in O(Number of bridges on specified road) at worst case
	void print(int roadNum) const;
};

#endif