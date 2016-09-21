#include "Animation.h"

Animation Animation::Start()
{
	Sleep(500);
	std::cout << "Animator Start\n";
	return Animation();
}

Animation Animation::Run()
{
	Sleep(500);
	std::cout << "Animator Run\n";
	return Animation();
}

Animation Animation::ShutDown()
{
	Sleep(500);
	std::cout << "Animator Shut Down\n";
	return Animation();
}
