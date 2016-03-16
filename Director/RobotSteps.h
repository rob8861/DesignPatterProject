// -------------------------------------------------
//	Design Pattern - Composit
// -------------------------------------------------
#ifndef ROBOT_STEPS_H
#define ROBOT_STEPS_H

#include "Method.h"

class DispenseStep : public Method
{
public:
	explicit DispenseStep(const char* string)
		: Method(string)
	{
	}

	void RunStep() const override;
};

class AspirateStep : public Method
{
public:
	explicit AspirateStep(const char* string)
		: Method(string)
	{
	}

	void RunStep() const override;
};

class WashStep : public Method
{
public:
	explicit WashStep(const char* string)
		: Method(string)
	{
	}

	void RunStep() const override;
};

#endif

