#ifndef ROBOT_STATES_H
#define ROBOT_STATES_H

#include "State.h"

class CollaborativeRobot;
class IndustrialRobot;

// collaborative robot states

class CollaborativeIdleState : public State<CollaborativeRobot>
{
public:
	void Enter(CollaborativeRobot* robot) override;
	void Execute(CollaborativeRobot* robot) override;
	void Exit(CollaborativeRobot* robot) override;

	static CollaborativeIdleState* Instance();

private:
	CollaborativeIdleState() {}
	CollaborativeIdleState(const CollaborativeIdleState&);
	CollaborativeIdleState& operator=(const CollaborativeIdleState&) = default;
};

class CollaborativeWorkingState : public State<CollaborativeRobot>
{
public:
	void Enter(CollaborativeRobot* robot) override;
	void Execute(CollaborativeRobot* robot) override;
	void Exit(CollaborativeRobot* robot) override;

	static CollaborativeWorkingState* Instance();

private:
	CollaborativeWorkingState() {}
	CollaborativeWorkingState(const CollaborativeWorkingState&);
	CollaborativeWorkingState& operator=(const CollaborativeWorkingState&) = default;
};

// industrial robot states

class IndustrialIdleState : public State<IndustrialRobot>
{
public:
	void Enter(IndustrialRobot* robot) override;
	void Execute(IndustrialRobot* robot) override;
	void Exit(IndustrialRobot* robot) override;

	static IndustrialIdleState* Instance();

private:
	IndustrialIdleState() {}
	IndustrialIdleState(const IndustrialIdleState&);
	IndustrialIdleState& operator=(const IndustrialIdleState&) = default;
};

class IndustrialWorkingState : public State<IndustrialRobot>
{
public:
	void Enter(IndustrialRobot* robot) override;
	void Execute(IndustrialRobot* robot) override;
	void Exit(IndustrialRobot* robot) override;

	static IndustrialWorkingState* Instance();

private:
	IndustrialWorkingState() {}
	IndustrialWorkingState(const IndustrialWorkingState&);
	IndustrialWorkingState& operator=(const IndustrialWorkingState&) = default;
};

#endif
