#include "Physics.h"

Physics Physics::Start()
{
	Sleep(500);
	std::cout << "Physics Start\n";
	return Physics();
}

Physics Physics::Run()
{
	Sleep(500);
	std::cout << "Physics Run\n";
	return Physics();
}

Physics Physics::ShutDown()
{
	Sleep(500);
	std::cout << "Physics Shut Down\n";
	return Physics();
}
