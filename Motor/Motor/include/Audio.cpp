#include "Audio.h"

Audio Audio::Start()
{
	Sleep(500);
	std::cout << "Audio Start\n";
	return Audio();
}

Audio Audio::Run()
{
	Sleep(500);
	std::cout << "Audio Run\n";
	return Audio();
}

Audio Audio::ShutDown()
{
	Sleep(500);
	std::cout << "Audio Shut Down\n";
	return Audio();
}
