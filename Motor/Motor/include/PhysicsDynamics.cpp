#include "PhysicsDynamics.h"

PhysicsDynamics PhysicsDynamics::Start()
{
	Sleep(500);
	std::cout << "Physics Dynamics Start\n";
	return PhysicsDynamics();
}

PhysicsDynamics PhysicsDynamics::Run()
{
	Sleep(500);
	std::cout << "Physics Dynamics Run\n";
	return PhysicsDynamics();
}

PhysicsDynamics PhysicsDynamics::ShutDown()
{
	Sleep(500);
	std::cout << "Physics Dynamics Shut Down\n";
	return PhysicsDynamics();
}
