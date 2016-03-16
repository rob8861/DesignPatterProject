// -------------------------------------------------
//	Design Pattern - State
// -------------------------------------------------
#ifndef STATE_H
#define STATE_H

template<class T>
class State
{
public:
	virtual ~State() {}

	virtual void Enter(T* robot) = 0;
	virtual void Execute(T* robot) = 0;
	virtual void Exit(T* robot) = 0;
};

#endif
