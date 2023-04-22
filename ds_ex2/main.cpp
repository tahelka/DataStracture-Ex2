#include <iostream>
#include "RoadNetwork.h"
#include "Interaction.h"
#include "InvalidInputException.h"

int main()
{

	try
	{
		Interaction myInteraction;
		if (myInteraction.getNumOfActions())
		{
			myInteraction.buildBaseRoadNetworkCheck();
			RoadNetwork roadNetwork(myInteraction.getNumOfRoads());
			myInteraction.getActionsFromUser(roadNetwork);
		}
	}
	catch(const InvalidInputException& e)
	{
		std::cout << e.what() << std::endl;
	}

}