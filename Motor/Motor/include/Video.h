#pragma once
#include <iostream>
#include <Windows.h>
class Video
{
public:
	static Video instance()
	{
		static Video *video = new Video();
		return *video;
	}

	Video Start();
	Video Run();
	Video ShutDown();

private:
	Video() {}
};