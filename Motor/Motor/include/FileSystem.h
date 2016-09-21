#pragma once
#include <iostream>
#include <Windows.h>

class FileSystem
{
public:
	static FileSystem instance()
	{
		static FileSystem *file = new FileSystem();
		return *file;
	}
	FileSystem Start();
	FileSystem Run();
	FileSystem ShutDown();
private:
	FileSystem() {}
};