#include "CollaborativeRobot.h"
#include <iostream>
#include "Method.h"

using namespace std;

void CollaborativeRobot::MoveToPosition(Vector3 position)
{
	cout << "robot " << _id << " is moving to position: " << position << endl;
	_currentPosition = position;
}

Vector3 CollaborativeRobot::GetCurrentPosition()
{
	return _currentPosition;
}

/*
* A collaboraqtive robot can execute two methods per cycle.
*/
void CollaborativeRobot::PerformTask()
{
	if (_queue.size() >= PROCESS_PER_CYCLE_COL)
	{
		for (size_t i = 0; i < PROCESS_PER_CYCLE_COL; i++)
		{
			auto step = _queue.front();
			step->RunMethod();
			_queue.pop();
		}
	}
}
