#ifndef __INTERACTION_H
#define __INTERACTION_H
#include <iostream>
#include <string>
#include "RoadNetwork.h"
#include "InvalidInputException.h"

enum {EMPTY = 0, INITIAL_INDEX = 0, CHAR_LEN = 1};

class Interaction
{
	int numOfRoads;
	int numOfActions;

public:
	// Constructor:
	Interaction()  noexcept (false);

	// Getters:

	// This method is used to get the number of roads.
	int getNumOfRoads();
	// This method is used to get the number of actions.
	int getNumOfActions();

	// Methods:

	// This method is used to get the line from the user.
	const std::string getLineFromUser() const noexcept (false);
	// This method is used to get a non-negative number from the user.
	int getNonNegativeNumberFromUser()	const noexcept (false);
	// This method is used to build the base of the road network.
	void buildBaseRoadNetworkCheck() noexcept (false);
	// This method is used to get the actions from the user.
	void getActionsFromUser(RoadNetwork& roadNetwork) const noexcept (false);
	// This method is used to check if a number is non-negative.
	bool isNonNegativeNumber(const std::string& num)	const;
	// This method is used to check if a char is a non-negative digit.
	bool isNonNegativeDigit(char ch) const;
	// This method is used to return a char from the line (string)
	char getCharFromLine(const std::string& line, int& index) const noexcept (false);
	// This method is used to return a positive number from the line (string)
	float getPositiveNumFromLine(const std::string& line, int& index, bool isInt, bool& isLineOver) const noexcept (false);
	// This method is used to return a road index from the line
	int getRoadIndexFromLine(const std::string& line, int& index, bool isInt, bool& isLineOver) const noexcept (false);
};

#endif
