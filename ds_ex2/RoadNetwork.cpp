#include "RoadNetwork.h"
#include <iostream>

// Constructor:
RoadNetwork::RoadNetwork(int numOfRoads) : numOfRoads(numOfRoads), roadsMaxHeap(numOfRoads)
{
	init();
}

// Destructor:
RoadNetwork::~RoadNetwork()
{
	delete[] roadsArray;
}

// Getters:

int RoadNetwork::getNumOfRoads() const
{
	return numOfRoads;
}

Road* const RoadNetwork::getRoadsArray()
{
	return roadsArray;
}

const MaxHeap& RoadNetwork::getRoadsMaxHeap()
{
	return roadsMaxHeap;
}

// Methods:

void RoadNetwork::init() // O(m)
{
	roadsArray = new Road[numOfRoads]; // O(m)
	roadsMaxHeap.setHeapSize(numOfRoads); // Theta(1)

	for (int i = 0; i < numOfRoads; i++) // O(m)
	{
		roadsArray[i].setPairIndex(i); // Theta(1)
		roadsMaxHeap.getMaxHeapArray()[i].setRoadIndex(i); // Theta(1)
	}
}

 void RoadNetwork::addBridge(float bridgeHeight, int roadNum) // O(log(m))
 {
 	// Insert the bridge to the road's list
 	roadsArray[roadNum].getBridges().insertDataToEndList(bridgeHeight, nullptr); // Theta(1)

 	int pairIndex = roadsArray[roadNum].getPairIndex(); // Theta(1)
 	Pair& pairNodeRef = roadsMaxHeap.getMaxHeapArray()[pairIndex]; // Theta(1)
	
 	if (bridgeHeight < pairNodeRef.getLowestBridgeHeight()) // Theta(1)
 	{
 		pairNodeRef.setLowestBridgeHeight(bridgeHeight); // Theta(1)
 		roadsMaxHeap.genericFixHeap(roadsArray, pairIndex); // O(log(m))
 	}
 }

void RoadNetwork::whichRoad(float truckHeight) // Theta(1)
{
	Pair max = roadsMaxHeap.max(); // Theta(1)

	if (truckHeight < max.getLowestBridgeHeight()) { // Theta(1)
		std::cout << max.getRoadIndex() + 1 << std::endl; // Theta(1)
	}
	else {
		std::cout << '0' << std::endl; // Theta(1)
	}
}

void RoadNetwork::print(int roadNum) const // O(number of bridges in the road)
{
	roadsArray[roadNum].getBridges().printList(); // O(number of bridges in the road)
}