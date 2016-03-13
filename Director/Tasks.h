#ifndef TASK_H
#define TASK_H

#include "Command.h"

class RobotController;

class ManipulatePlateCommand : public Command
{
public:
	explicit ManipulatePlateCommand(RobotController* robot);

	void Execute() override;
	bool CanExecute() override;

private:
	RobotController* _robot;
};


class PickItemCommand : public Command
{
public:
	explicit PickItemCommand(RobotController* robot);

	void Execute() override;
	bool CanExecute() override;

private:
	RobotController* _robot;
};

class PlaceItemCommand : public Command
{
public:
	explicit PlaceItemCommand(RobotController* robot);

	void Execute() override;
	bool CanExecute() override;

private:
	RobotController* _robot;
};

#endif

