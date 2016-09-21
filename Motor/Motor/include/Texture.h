#pragma once
#include <iostream>
#include <Windows.h>
class Texture
{
public:
	static Texture instance()
	{
		static Texture *texture = new Texture();
		return *texture;
	}

	Texture Start();
	Texture Run();
	Texture ShutDown();

private:
	Texture() {}
};