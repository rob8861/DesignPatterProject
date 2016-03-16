#include "IndustrialRobot.h"
#include <iostream>
#include "Method.h"

using namespace std;

void IndustrialRobot::MoveToPosition(Vector3 position)
{
	cout << "robot " << _id << " is moving to position: " << position << endl;
	_currentPosition = position;
}

Vector3 IndustrialRobot::GetCurrentPosition()
{
	return _currentPosition;
}

/*
* An industrial robot can execute 5 methods per cycle.
*/
void IndustrialRobot::PerformTask()
{
	if (_queue.size() >= PROCESS_PER_CYCLE_IND)
	{
		for (size_t i = 0; i < PROCESS_PER_CYCLE_IND; i++)
		{
			auto step = _queue.front();
			step->RunMethod();
			_queue.pop();
		}
	}
}
