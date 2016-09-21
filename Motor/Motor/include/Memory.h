#pragma once
#include <iostream>
#include <Windows.h>

class Memory
{
public:
	static Memory instance()
	{
		static Memory *memory = new Memory();
		return *memory;
	}

	static Memory Start();
	static Memory Run();
	static Memory ShutDown();

private:
	Memory() {}
};