#ifndef __INVALID_INPUT_EXCEPTION_H
#define __INVALID_INPUT_EXCEPTION_H
#include <string>

class InvalidInputException
{
public:
	// Methods:

	// This method is used to get the error message.
	const std::string what()	const;
};

#endif