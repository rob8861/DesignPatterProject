#ifndef INDUSTRIAL_ROBOT_H
#define INDUSTRIAL_ROBOT_H

#include "RobotController.h"
#include "Vector3.h"
#include <iostream>
#include "State.h"

class IndustrialRobot : public RobotController
{
public:
	explicit IndustrialRobot(int id, State<IndustrialRobot>* state)
		: _id(id), _currentPosition(0.0f, 0.0f, 0.0f), _currentState(state)
	{
		std::cout << "A new industrial robot created with id " << _id
			<< " and starting position " << _currentPosition;
	}

	void MoveToPosition(Vector3 position) override;
	Vector3 GetCurrentPosition() override;
	void PerformTask(Method* method) override;

	void ChangeState(State<IndustrialRobot>* newState);

private:
	int _id;
	Vector3 _currentPosition;
	State<IndustrialRobot>* _currentState;
};

#endif

