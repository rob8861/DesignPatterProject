// -------------------------------------------------
//	Design Pattern - State
// -------------------------------------------------
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "State.h"

template<class T>
class StateMachine
{
public:
	StateMachine(T* owner) : _owner(owner), _currentState(nullptr) {}

	void SetCurrentState(State<T>* state) { _currentState = state; }

	void Run() const
	{
		if (_currentState)
			_currentState->Execute(_owner);
	}

	void ChangeState(State<T>* newState)
	{
		_currentState->Exit(_owner);
		_currentState = newState;
		_currentState->Enter(_owner);
	}

	State<T>* GetState() const { return _currentState; }

private:
	T* _owner;
	State<T>* _currentState;
};

#endif