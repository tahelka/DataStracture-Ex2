#ifndef __PAIR_H
#define __PAIR_H

// The highest bridge in the world is "Le Viaduc de Millau" in France and its 343 meters tall.
enum { MAX_BRIDGE_HEIGHT = 345, NO_ROAD_CONNECTED = -1 };

class Pair
{
	float lowestBridgeHeight; // Priority
	int roadIndex;

public:
	// Constructor:
	Pair() : lowestBridgeHeight(MAX_BRIDGE_HEIGHT), roadIndex(NO_ROAD_CONNECTED) {};

	// Getters:

	// This method is used to get the lowest bridge height of the pair.
	float getLowestBridgeHeight() const;
	// This method is used to get the road index of the pair.
	int getRoadIndex() const;

	// Setters:
	
	// This method is used to set the lowest bridge height of the pair.
	void setLowestBridgeHeight(float lowestBridgeHeight);
	// This method is used to set the road index of the pair.
	void setRoadIndex(int roadIndex);

};

#endif
