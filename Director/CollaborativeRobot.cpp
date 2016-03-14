#include "CollaborativeRobot.h"
#include <iostream>
#include "Method.h"

using namespace std;

void CollaborativeRobot::MoveToPosition(Vector3 position)
{
	cout << "robot " << _id << " is moving to position: " << position;
	_currentPosition = position;
}

Vector3 CollaborativeRobot::GetCurrentPosition()
{
	return _currentPosition;
}

void CollaborativeRobot::PerformTask(Method* method)
{
	method->RunMethod();
}

void CollaborativeRobot::ChangeState(State<CollaborativeRobot>* newState)
{
	_currentState->Exit(this);
	_currentState = newState;
	_currentState->Enter(this);
}
