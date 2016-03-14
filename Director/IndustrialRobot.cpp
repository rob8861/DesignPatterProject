#include "IndustrialRobot.h"
#include <iostream>
#include "Method.h"

using namespace std;

void IndustrialRobot::MoveToPosition(Vector3 position)
{
	cout << "robot " << _id << " is moving to position: " << position;
	_currentPosition = position;
}

Vector3 IndustrialRobot::GetCurrentPosition()
{
	return _currentPosition;
}

void IndustrialRobot::PerformTask(Method* method)
{
	method->RunMethod();
}

void IndustrialRobot::ChangeState(State<IndustrialRobot>* newState)
{
	_currentState->Exit(this);
	_currentState = newState;
	_currentState->Enter(this);
}
