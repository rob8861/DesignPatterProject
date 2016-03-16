/*****************************************************************************************
*	DESIGN PATTERN COURSE PROJECT
*	
* AUTHOR: Rem Fazio
*
*	DATE:   March 12th 2016
*
*	DESCRIPTION: 
*	Director is a small framework which can be used to dispatch commands 
* to robots in order to automate various tasks. 
*	The Director is implemented using the following design patterns:
*	Abstract Factory, Composit, State and Command. In addition, each State will be
* implemented as a Singleton.
*
*	UCSD EXTENSION, SAN DIEGO
******************************************************************************************
*/


#include "RobotController.h"
#include "RobotFactory.h"
#include "Tasks.h"
#include "Method.h"
#include "RobotSteps.h"
#include <random>
#include <chrono>
#include <thread>

const int SLEEP = 1000;

// forward declare a factory method
RobotController* CreateRobot(RobotFactory& factory, int id);

int main(int argc, char** argv)
{
	// ---  demostrate usage of abstract factory --- //

	// create collaborative robot with id 1
	CollaborativeRobotFactory colRobotFactory;
	RobotController* collaborativeRobot1 = CreateRobot(colRobotFactory, 1);

	// create industrial robot with id 1
	IndustialRobotFactory indRobotFactory;
	RobotController* industrialRobot1 = CreateRobot(indRobotFactory, 2);

	// ---  demostrate usage of command pattern --- //

	// instruct the collaborative robot to pick an item from location
	Vector3 pickLocation(6.0f, 78.0f, 10.0f);
	PickItemCommand cmd(collaborativeRobot1, pickLocation);
	cmd.Execute();
	// instruct the industrial robot to pick an item from location
	PickItemCommand cmd2(industrialRobot1, pickLocation);
	cmd2.Execute();

	// instruct both robots to place the item at location
	Vector3 placeLocation(67.0f, 150.6f, 10.0f);
	PlaceItemCommand cmd3(collaborativeRobot1, placeLocation);
	cmd3.Execute();
	PlaceItemCommand cmd4(industrialRobot1, placeLocation);
	cmd4.Execute();

	// ---  demostrate usage of composite pattern --- //

	// create few methods for both robots to run.
	Method* bigMethod = new Method("BigMethod");
	bigMethod->AddStep(new DispenseStep("10mL"));
	bigMethod->AddStep(new AspirateStep("1uL"));
	bigMethod->AddStep(new DispenseStep("15mL"));
	bigMethod->AddStep(new WashStep("4mL water"));

	Method* smallMethod = new Method("Small Method");
	smallMethod->AddStep(new DispenseStep("20uL"));
	smallMethod->AddStep(new WashStep("1mL water"));

	Method* washMethod = new Method("wash method");
	washMethod->AddStep(new WashStep("50mL"));

	std::vector<Method*> methodPool = { bigMethod, smallMethod, washMethod };

	// randomly generate a number between 0 to 2.
	uint32_t methodIndex;
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 2);
	
	// ---  demostrate usage of state and singleton --- //

	// execute the state machine for 20 simulation cycles
	for (size_t i = 0; i < 20; i++)
	{
		// pick a random method index from the pool.
		methodIndex = dist6(rng);
		// add methods to each robot 
		collaborativeRobot1->AddTask(methodPool[methodIndex]);
		industrialRobot1->AddTask(methodPool[methodIndex]);
		// invoke the state machine
		collaborativeRobot1->GetSM()->Run();
		industrialRobot1->GetSM()->Run();
		// slow down the simulation
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP));
	}

#if defined(_WIN32) || defined(WIN32) || defined(__WIN32)
	system("pause");
#else
	std::cout << "Press any key to quit...";
	std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
#endif
	return 0;
}


RobotController* CreateRobot(RobotFactory& factory, int id)
{
	return factory.MakeRobot(id);
}