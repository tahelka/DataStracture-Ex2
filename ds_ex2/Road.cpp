#include "Road.h"

// Getters:

int Road::getPairIndex() const 
{
    return pairIndex;
}

List& Road::getBridges() {
    return bridges;
}

// Setters:

void Road::setPairIndex(int index) 
{
    pairIndex = index;
}
