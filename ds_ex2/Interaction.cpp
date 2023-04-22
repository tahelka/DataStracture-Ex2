#include "Interaction.h"

// Constructor:
Interaction::Interaction()
{
    numOfRoads = getNonNegativeNumberFromUser();
    numOfActions = getNonNegativeNumberFromUser();
}

// Getters:
int Interaction::getNumOfRoads()
{
    return numOfRoads;
}

int Interaction::getNumOfActions()
{
    return numOfActions;
}


// Methods:
const std::string Interaction::getLineFromUser()    const
{
    std::string line;
    std::getline(std::cin, line);

    if (line.length() == EMPTY)
        throw InvalidInputException();

    return line;
}

int Interaction::getNonNegativeNumberFromUser()    const
{
    std::string num;
    num = getLineFromUser();

    if (!isNonNegativeNumber(num))
        throw InvalidInputException();

    return stoi(num);

}

bool Interaction::isNonNegativeNumber(const std::string& num)  const
{
    int len = num.length();
    
    if (len == EMPTY)
        return false;

    for (int i = 0; i < len; i++) {

        if (i == 0 && num[i] == '0' && len > 1)
            return false;

        if (isNonNegativeDigit(num[i]) == false) {
            return false;
        }
    }
    return true;
}

bool Interaction::isNonNegativeDigit(char ch)  const
{
    return ch >= '0' && ch <= '9';
}

void Interaction::buildBaseRoadNetworkCheck()
{
    std::string line = getLineFromUser();

    if (line.length() != CHAR_LEN)
        throw InvalidInputException();

    int index = INITIAL_INDEX;

    char ch = getCharFromLine(line, index);

    if (ch != 'a')
        throw InvalidInputException();

    numOfActions--;
}

void Interaction::getActionsFromUser(RoadNetwork& roadNetwork) const
{
    float height;
    int roadIndex;
    std::string line;
    int index;
    char ch;
    bool isLineOver = false;

    for (int i = 0; i < numOfActions; i++)
    {
        index = INITIAL_INDEX;
        line = getLineFromUser();
        ch = getCharFromLine(line, index);

        switch (ch)
        {
        case 'b': // add bridge
            height = getPositiveNumFromLine(line, index, false, isLineOver);
            roadIndex = getRoadIndexFromLine(line, index, true, isLineOver);
            roadNetwork.addBridge(height, roadIndex);
            break;

        case 'c': // which road
            height = getPositiveNumFromLine(line, index, false, isLineOver);
            roadNetwork.whichRoad(height);
            break;

        case 'd': // print
            roadIndex = getRoadIndexFromLine(line, index, true, isLineOver);
            roadNetwork.print(roadIndex);
            break;

        default:
            throw InvalidInputException();
        }

        if(!isLineOver)
            throw InvalidInputException();
    }
}

char Interaction::getCharFromLine(const std::string& line, int& index) const
{

    int lengthLeft = line.length() - index;

    if(lengthLeft < CHAR_LEN)
        throw InvalidInputException();

    char ch = line[index];
    index++;

    if ((line.length() - index) != EMPTY && line[index] != ' ')
        throw InvalidInputException();

    index++;
    return ch;
}

float Interaction::getPositiveNumFromLine(const std::string& line, int& index, bool isInt, bool& isLineOver) const
{
    int numFirstIndex = index;
    bool firstTime = true;

    if ((line.length() - index) <= EMPTY || line[index] == ' ' || line[index] == '.' || line[index] == '0')
        throw InvalidInputException();

    while ((line.length() - index) != EMPTY && line[index] != ' ')
    {
        if (!isInt && line[index] == '.') 
        {         
            // if user entered '.' at the end of the number without entering more digits after it
            if(( line.length() - (index+1) ) == EMPTY || line[index + 1] == ' ')
                throw InvalidInputException();

            if (firstTime)
                firstTime = false;
            else // there is more than one dot in curr string
                throw InvalidInputException();
        }
        else if (!(isNonNegativeDigit(line[index])))
            throw InvalidInputException();

        index++;
    }

    if ((line.length() - index) == EMPTY) // we exited the loop bc line is over
    {
        isLineOver = true;
    }
    else
    {
        index++;
    }

    std::string num = line.substr(numFirstIndex, index - numFirstIndex);

    if (isInt)
        return std::stoi(num);
    else
        return std::stof(num);
}

int Interaction::getRoadIndexFromLine(const std::string& line, int& index, bool isInt, bool& isLineOver)  const
{
    // -1 for matching road number to its actual index
    int roadIndex = getPositiveNumFromLine(line, index, true, isLineOver) - 1;  

    if(roadIndex >= numOfRoads)
        throw InvalidInputException();

    return roadIndex;
}