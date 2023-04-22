#include "InvalidInputException.h"

// Methods:

const std::string InvalidInputException::what()	const
{
	return "invalid input";
}