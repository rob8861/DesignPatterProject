#ifndef METHOD_H
#define METHOD_H

#include <vector>

class Method
{
public:
	Method(const char* string) : _name(string) {}
	virtual ~Method() {}

	const char* Name() const	{ return _name;	}
	void ClearAllSteps() { _steps.clear(); }
	void RunMethod() const;

	virtual void RunStep() const {}

	virtual void AddStep(Method* step);
	virtual void RemoveStep(Method* step);

private:
	const char* _name;
	std::vector<Method*> _steps;
	
};

#endif

