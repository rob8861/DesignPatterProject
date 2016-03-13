#include "Method.h"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>

const int SLEEP = 3000;

void Method::RunMethod() const
{
	for (auto itr = _steps.cbegin(); itr != _steps.cend() ; ++itr)
	{
		// get the step
		Method* step = *itr;
		// run the step 
		std::cout << "running step " << step->Name() << std::endl;
		// simulate step being run
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP));
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