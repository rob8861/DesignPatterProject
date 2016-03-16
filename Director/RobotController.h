// -------------------------------------------------
//	Design Pattern - Factory Method
// -------------------------------------------------
#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include "StateMachine.h"

struct Vector3;
class Method;


/*
* A pure abstract class that defines the behavior for each robot.
*/
class RobotController
{
public:
	virtual ~RobotController(){}

	virtual int GetId() const = 0;
	virtual void MoveToPosition(Vector3 position) = 0;
	virtual Vector3 GetCurrentPosition() = 0;
	virtual void PerformTask() = 0;
	virtual void AddTask(Method* method) = 0;
	virtual bool IsBusy() const = 0;
	virtual StateMachine<RobotController>* GetSM() = 0;

};

#endif
