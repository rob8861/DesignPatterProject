#include "RobotSteps.h"
#include <iostream>

void DispenseStep::RunStep() const
{
	std::cout << "Dispensing liquid" << std::endl;
}

void AspirateStep::RunStep() const
{
	std::cout << "Aspirating liquid" << std::endl;
}

void WashStep::RunStep() const
{
	std::cout << "Washing plate" << std::endl;
}
