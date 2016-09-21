#include "Texture.h"

Texture Texture::Start()
{
	Sleep(500);
	std::cout << "Texture Start\n";
	return Texture();
}

Texture Texture::Run()
{
	Sleep(500);
	std::cout << "Texture Run\n";
	return Texture();
}

Texture Texture::ShutDown()
{
	Sleep(500);
	std::cout << "Texture Shut Down\n";
	return Texture();
}
