#include "FileSystem.h"

FileSystem FileSystem::Start()
{
	Sleep(500);
	std::cout << "File System Start\n";
	return FileSystem();
}

FileSystem FileSystem::Run()
{
	Sleep(500);
	std::cout << "File System Run\n";
	return FileSystem();
}

FileSystem FileSystem::ShutDown()
{
	Sleep(500);
	std::cout << "File System Shut Down\n";
	return FileSystem();
}
