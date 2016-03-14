#include "RobotStates.h"

// ------------------------------------------
//	Collaborative robot states
// ------------------------------------------
void CollaborativeIdleState::Enter(CollaborativeRobot* robot)
{
	 
}

void CollaborativeIdleState::Execute(CollaborativeRobot* robot)
{
}

void CollaborativeIdleState::Exit(CollaborativeRobot* robot)
{
}

CollaborativeIdleState* CollaborativeIdleState::Instance()
{
	static CollaborativeIdleState instance;
	return &instance;
}

void CollaborativeWorkingState::Enter(CollaborativeRobot* robot)
{
}

void CollaborativeWorkingState::Execute(CollaborativeRobot* robot)
{
}

void CollaborativeWorkingState::Exit(CollaborativeRobot* robot)
{
}

CollaborativeWorkingState* CollaborativeWorkingState::Instance()
{
	static CollaborativeWorkingState instance;
	return &instance;
}

// --------------------------------------------------------------
//		Industrial robot states
// --------------------------------------------------------------

void IndustrialIdleState::Enter(IndustrialRobot* robot)
{
}

void IndustrialIdleState::Execute(IndustrialRobot* robot)
{
}

void IndustrialIdleState::Exit(IndustrialRobot* robot)
{
}

IndustrialIdleState* IndustrialIdleState::Instance()
{
	static IndustrialIdleState instance;
	return &instance;
}

void IndustrialWorkingState::Enter(IndustrialRobot* robot)
{
}

void IndustrialWorkingState::Execute(IndustrialRobot* robot)
{
}

void IndustrialWorkingState::Exit(IndustrialRobot* robot)
{
}

IndustrialWorkingState* IndustrialWorkingState::Instance()
{
	static IndustrialWorkingState instance;
	return &instance;
}