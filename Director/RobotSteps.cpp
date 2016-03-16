#include "RobotSteps.h"
#include <iostream>

void DispenseStep::RunStep() const
{
	std::cout << "->\tDispensing liquid" << std::endl;
}

void AspirateStep::RunStep() const
{
	std::cout << "->\tAspirating liquid" << std::endl;
}

void WashStep::RunStep() const
{
	std::cout << "->\tWashing plate" << std::endl;
}
