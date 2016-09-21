#include "Render.h"

Render Render::Start()
{
	Sleep(500);
	std::cout << "Render start\n";
	return Render();
}

Render Render::Run()
{
	Sleep(500);
	std::cout << "Render Run\n";
	return Render();
}

Render Render::ShutDown()
{
	Sleep(500);
	std::cout << "Render Shut Down\n";
	return Render();
}
