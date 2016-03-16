// -------------------------------------------------
//	Design Patterns - State and Singleton
// -------------------------------------------------
#ifndef ROBOT_STATES_H
#define ROBOT_STATES_H

#include "State.h"

class RobotController;

/*
*	The robots can transition between idle and working states.
*	While in idle state, the robot can queue in tasks.
*	While in working state, the robot execute all the queued tasks.
*/
class Idle : public State<RobotController>
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

class Working : public State<RobotController>
{
public:
	void Enter(RobotController* robot) override;
	void Execute(RobotController* robot) override;
	void Exit(RobotController* robot) override;

	static Working* Instance();

private:
	Working() {}
	Working(const Working&);
	Working& operator=(const Working&) = default;
};

#endif
