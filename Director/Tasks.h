// -------------------------------------------------
//	Design Pattern - Command
// -------------------------------------------------
#ifndef TASK_H
#define TASK_H

#include "Command.h"
#include "RobotController.h"
#include "Vector3.h"

class ManipulatePlateCommand : public Command
{
public:
	explicit ManipulatePlateCommand(RobotController* robot) : _robot(robot) {};

	void Execute() override;

private:
	RobotController* _robot;
};


class PickItemCommand : public Command
{
public:
	explicit PickItemCommand(RobotController* robot, Vector3 pickLocation) :
		_robot(robot), _pickLocation(pickLocation)
	{
		
	}

	void Execute() override;

private:
	RobotController* _robot;
	Vector3 _pickLocation;
};

class PlaceItemCommand : public Command
{
public:
	explicit PlaceItemCommand(RobotController* robot, Vector3 placeLocation) : 
		_robot(robot), _placeLocation(placeLocation)
	{
		
	}

	void Execute() override;

private:
	RobotController* _robot;
	Vector3 _placeLocation;
};

#endif

