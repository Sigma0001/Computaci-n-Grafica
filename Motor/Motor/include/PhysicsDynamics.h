#pragma once
#include <iostream>
#include <Windows.h>
class PhysicsDynamics
{
public:
	static PhysicsDynamics instance()
	{
		static PhysicsDynamics *physicsDynamic = new PhysicsDynamics();
		return *physicsDynamic;
	}

	PhysicsDynamics Start();
	PhysicsDynamics Run();
	PhysicsDynamics ShutDown();

private:
	PhysicsDynamics() {}
};