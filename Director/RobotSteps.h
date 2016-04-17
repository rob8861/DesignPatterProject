// -------------------------------------------------
//	Design Pattern - Composite
// -------------------------------------------------
#ifndef ROBOT_STEPS_H
#define ROBOT_STEPS_H

#include "Method.h"

class DispenseStep : public Method
{
public:
	explicit DispenseStep(const char* name)
		: Method(name)
	{
	}

	void RunStep() const override;
};

class AspirateStep : public Method
{
public:
	explicit AspirateStep(const char* name)
		: Method(name)
	{
	}

	void RunStep() const override;
};

class WashStep : public Method
{
public:
	explicit WashStep(const char* name)
		: Method(name)
	{
	}

	void RunStep() const override;
};

class MixStep : public Method
{
public:
	explicit MixStep(const char* name)
		: Method(name)
	{
	}

	void RunStep() const override;
};

#endif

