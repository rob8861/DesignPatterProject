#ifndef ROBOT_STATES_H
#define ROBOT_STATES_H

#include "State.h"

class RobotController;

class Idle : State<RobotController>
{
public:
	void Enter(RobotController* robot) override;
	void Execute(RobotController* robot) override;
	void Exit(RobotController* robot) override;

	static Idle* Instance();

private:
	Idle() {}
	Idle(const Idle&);
	Idle& operator=(const Idle&) = default;
};

class BusyWorkingInTheAssemblyLine : State<RobotController>
{
public:
	void Enter(RobotController* robot) override;
	void Execute(RobotController* robot) override;
	void Exit(RobotController* robot) override;

	static BusyWorkingInTheAssemblyLine* Instance();

private:
	BusyWorkingInTheAssemblyLine() {}
	BusyWorkingInTheAssemblyLine(const BusyWorkingInTheAssemblyLine&);
	BusyWorkingInTheAssemblyLine& operator=(const BusyWorkingInTheAssemblyLine&) = default;
};

#endif
