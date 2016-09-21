#pragma once
#include <iostream>
#include <Windows.h>

class Animation
{
public:
	static Animation instance()
	{
		static Animation *animate = new Animation();
		return *animate;
	}

	static Animation Start();
	static Animation Run();
	static Animation ShutDown();

private:
	Animation() {}
};