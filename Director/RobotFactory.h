#ifndef ROBOT_FACTORY_H
#define ROBOT_FACTORY_H

class RobotController;
class CollaborativeRobot;

class RobotFactory
{
public:
	virtual ~RobotFactory()	{}

	virtual RobotController* MakeRobot() const = 0;

};

class CollaborativeRobotFactory : RobotFactory
{
public:
	RobotController* MakeRobot() const override
	{
		// return new CollaborativeRobot;
		return nullptr;
	}
};

class IndustialRobotFactory : RobotFactory
{
public:
	RobotController* MakeRobot() const override
	{
		// return new IndustrialRobot;
		return nullptr;
	}
};

#endif
