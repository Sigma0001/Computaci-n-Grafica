#pragma once
#include <iostream>
#include <Windows.h>
class Physics
{
public:
	static Physics instance()
	{
		static Physics *physics = new Physics();
		return *physics;
	}

	Physics Start();
	Physics Run();
	Physics ShutDown();

private:
	Physics() {}
};