// -------------------------------------------------
//	Design Pattern - Factory Method
// -------------------------------------------------
#ifndef COLLABORATIVE_ROBOT_H
#define COLLABORATIVE_ROBOT_H

#include "RobotController.h"
#include "Vector3.h"
#include <iostream>
#include <queue>
#include "StateMachine.h"
#include "RobotStates.h"

/*
* A collaborative robot is designed with human interaction in mind.
* It is relatively safe to operate.
*/
class CollaborativeRobot : public RobotController
{
public:
	// the max number of methods the robot can process.
	static const int MAX_CAN_PROCESS = 5;	

	explicit CollaborativeRobot(int id)
		: _id(id), _currentPosition(0.0f, 0.0f, 0.0f)
	{
		std::cout << "A new collaborative robot created with id " << _id
			<< " and starting position " << _currentPosition << std::endl;

		// initialize the state machine with the derviced class object
		_stateMachine = new StateMachine<RobotController>(this);
		// set initial state to idle
		_stateMachine->SetCurrentState(Idle::Instance());
	}

	int GetId() const override { return _id; }
	void MoveToPosition(Vector3 position) override;
	Vector3 GetCurrentPosition() override;
	// execute a fixed number of methods sequentially and pop them from the queue
	void PerformTask() override;
	// add a method to the queue
	void AddTask(Method* method) override { _queue.push(method); }
	bool IsBusy() const override { return _queue.size() >= MAX_CAN_PROCESS; }
	StateMachine<RobotController>* GetSM() override { return _stateMachine; }

private:
	int _id;
	Vector3 _currentPosition;
	StateMachine<RobotController>* _stateMachine;
	std::queue<Method*> _queue;
};

#endif

