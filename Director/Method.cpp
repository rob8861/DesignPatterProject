#include "Method.h"
#include <algorithm>

// execute each step of the method
void Method::RunMethod() const
{
	for (auto itr = _steps.cbegin(); itr != _steps.cend() ; ++itr)
	{
		// get the step
		Method* step = *itr;
		// run the step 
		step->RunStep();
	}
}

void Method::AddStep(Method* step)
{
	_steps.push_back(step);
}

void Method::RemoveStep(Method* step)
{
	auto pos = remove(_steps.begin(), _steps.end(), step);
	_steps.erase(pos, _steps.end());
}