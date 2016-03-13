#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

struct Vector3;
class Command;
class Method;

/*
* A pure abstract class that defines the behavior for each robot.
*/
class RobotController
{
public:
	virtual ~RobotController(){}

	virtual void MoveToPosition(Vector3 position) = 0;
	virtual Vector3 GetCurrentPosition() = 0;
	virtual void PerformTask(Method* method) = 0;
};

#endif
