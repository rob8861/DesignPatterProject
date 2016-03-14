#ifndef ROBOT_FACTORY_H
#define ROBOT_FACTORY_H

#include "CollaborativeRobot.h"
#include "IndustrialRobot.h"
#include "RobotStates.h"

class RobotController;


class RobotFactory
{
public:
	virtual ~RobotFactory()	{}

	virtual RobotController* MakeRobot(int) const = 0;

};

class CollaborativeRobotFactory : public RobotFactory
{
public:
	RobotController* MakeRobot(int id) const override
	{
		return new CollaborativeRobot(id, CollaborativeIdleState::Instance());
	}
};

class IndustialRobotFactory : public RobotFactory
{
public:
	RobotController* MakeRobot(int id) const override
	{
		 return new IndustrialRobot(id, IndustrialIdleState::Instance());
	}
};

#endif
