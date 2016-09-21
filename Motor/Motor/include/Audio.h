#pragma once
#include<iostream>
#include <Windows.h>

class Audio
{
public:
	static Audio instance()
	{
		static Audio *audio = new Audio();
		return *audio;
	}

	Audio Start();
	Audio Run();
	Audio ShutDown();

private:
	Audio() {}
};