// -------------------------------------------------
//	Design Pattern - Factory Method
// -------------------------------------------------
#ifndef INDUSTRIAL_ROBOT_H
#define INDUSTRIAL_ROBOT_H

#include "RobotController.h"
#include "Vector3.h"
#include <iostream>
#include <queue>
#include "StateMachine.h"
#include "RobotStates.h"

/*
* An industrial robot is a heavy dury, high throughput machine
* capable of operating at high speed. It requires a safe zone and an
* experienced operator.
*/
class IndustrialRobot : public RobotController
{
public:
	// the max number of methods the robot can process.
	static const int MAX_CAN_PROCESS = 10;

	explicit IndustrialRobot(int id)
		: _id(id), _currentPosition(0.0f, 0.0f, 0.0f)
	{
		std::cout << "A new industrial robot created with id " << _id
			<< " and starting position " << _currentPosition << std::endl;

		_stateMachine = new StateMachine<RobotController>(this);
		_stateMachine->SetCurrentState(Idle::Instance());
	}

	int GetId() const override { return _id; };
	void MoveToPosition(Vector3 position) override;
	Vector3 GetCurrentPosition() override;
	void PerformTask() override;
	void AddTask(Method* method) override { _queue.push(method); }
	bool IsBusy() const override { return _queue.size() >= MAX_CAN_PROCESS; }
	StateMachine<RobotController>* GetSM() override {	return _stateMachine;	}

private:
	int _id;
	Vector3 _currentPosition;
	StateMachine<RobotController>* _stateMachine;
	std::queue<Method*> _queue;
};

#endif

