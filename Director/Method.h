// -------------------------------------------------
//	Design Pattern - Composite
// 
//	A method is a set of instructions a robot can
//  process. Each mathod may conatain one or more
//	steps, which are processed sequentially.
// -------------------------------------------------
#ifndef METHOD_H
#define METHOD_H

#include <vector>

const int PROCESS_PER_CYCLE_COL = 2;
const int PROCESS_PER_CYCLE_IND = 5;

class Method
{
public:
	Method(const char* string) : _name(string) {}
	virtual ~Method() {}

	const char* Name() const	{ return _name;	}
	void ClearAllSteps() { _steps.clear(); }
	void RunMethod() const;	// execute the entire method and all its steps

	virtual void RunStep() const {} // runs a single step, assuming the method has only one step

	virtual void AddStep(Method* step);
	virtual void RemoveStep(Method* step);

private:
	const char* _name;
	std::vector<Method*> _steps;	// stores the steps
	
};

#endif

