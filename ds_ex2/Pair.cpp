#include "Pair.h"

// Getters:
float Pair::getLowestBridgeHeight()	const
{
	return lowestBridgeHeight;
}

int Pair::getRoadIndex()	const
{
	return roadIndex;
}

// Setters:

void Pair::setLowestBridgeHeight(float lowestBridgeHeight)
{
	this->lowestBridgeHeight = lowestBridgeHeight;
}

void Pair::setRoadIndex(int roadIndex)
{
	this->roadIndex = roadIndex;
}