#include "RobotStates.h"
#include "RobotController.h"
#include "Tasks.h"
#include <iostream>


void Idle::Enter(RobotController* robot)
{
	std::cout << "robot [" << robot->GetId() << "] is idling and waiting for more work." << std::endl;
}

void Idle::Execute(RobotController* robot)
{
	// if the robot queue has filled up, we can transition to working state
	// where it will begin executing the methods.
	if (robot->IsBusy())
	{
		robot->GetSM()->ChangeState(Working::Instance());
	}
}

void Idle::Exit(RobotController* robot)
{
	std::cout << "robot [" << robot->GetId() << "] is about to start work." << std::endl;
}

Idle* Idle::Instance()
{
	static Idle instance;
	return &instance;
}

void Working::Enter(RobotController* robot)
{
	std::cout << "robot [" << robot->GetId() << "] is executing tasks in the queue." << std::endl;
}

void Working::Execute(RobotController* robot)
{
	// send a command that will run once per cycle, so long there are
	// methods in the queue
	ManipulatePlateCommand cmd(robot);
	cmd.Execute();
	// once the queue is depleted, we can transition back to idle
	if (!robot->IsBusy())
	{
		robot->GetSM()->ChangeState(Idle::Instance());
	}
}

void Working::Exit(RobotController* robot)
{
	std::cout << "robot [" << robot->GetId() << "] finshed executing all its tasks in the queue." << std::endl;
}

Working* Working::Instance()
{
	static Working instance;
	return &instance;
}