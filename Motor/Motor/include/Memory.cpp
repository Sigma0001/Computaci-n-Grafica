#include "Memory.h"

Memory Memory::Start()
{
	Sleep(500);
	std::cout << "Memory Start\n";
	return Memory();
}

Memory Memory::Run()
{
	Sleep(500);
	std::cout << "Memory Run\n";
	return Memory();
}

Memory Memory::ShutDown()
{
	Sleep(500);
	std::cout << "Memory Shut Down\n";
	return Memory();
}
