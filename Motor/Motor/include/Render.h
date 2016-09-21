#pragma once
#include <iostream>
#include <Windows.h>
class Render
{
public:
	static Render instance()
	{
		static Render *render = new Render();
		return *render;
	}
	Render Start();
	Render Run();
	Render ShutDown();
private:
	Render() {}
};