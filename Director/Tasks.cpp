#include "Tasks.h"
#include <iostream>

void ManipulatePlateCommand::Execute()
{
	std::cout << "robot [" << _robot->GetId() << "] is executing a method" << std::endl;
	_robot->PerformTask();
}

void PickItemCommand::Execute()
{
	_robot->MoveToPosition(_pickLocation);
}

void PlaceItemCommand::Execute()
{
	_robot->MoveToPosition(_placeLocation);
}
