#ifndef ROBOT_STEPS_H
#define ROBOT_STEPS_H

#include "Method.h"

class DispenseStep : Method
{
public:
	explicit DispenseStep(const char* string)
		: Method(string)
	{
	}
};

class AspirateStep : Method
{
public:
	explicit AspirateStep(const char* string)
		: Method(string)
	{
	}
};

class WashStep : Method
{
public:
	explicit WashStep(const char* string)
		: Method(string)
	{
	}
};

#endif

