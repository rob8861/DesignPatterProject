#ifndef COLLABORATIVE_ROBOT_H
#define COLLABORATIVE_ROBOT_H

#include "RobotController.h"
#include "Vector3.h"
#include "State.h"
#include <iostream>

class CollaborativeRobot : public RobotController
{
public:
	explicit CollaborativeRobot(int id, State<CollaborativeRobot>* state)
		: _id(id), _currentPosition(0.0f, 0.0f, 0.0f), _currentState(state)
	{
		std::cout << "A new collaborative robot created with id " << _id
			<< " and starting position " << _currentPosition;
	}

	void MoveToPosition(Vector3 position) override;
	Vector3 GetCurrentPosition() override;
	void PerformTask(Method* method) override;

	void ChangeState(State<CollaborativeRobot>* newState);

private:
	int _id;
	Vector3 _currentPosition;
	State<CollaborativeRobot>* _currentState;
};

#endif

