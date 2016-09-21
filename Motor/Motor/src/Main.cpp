#include "..\include\Libraries.h"

Memory& memory = Memory::instance();
FileSystem& file = FileSystem::instance();
Video& video = Video::instance();
Audio& audio = Audio::instance();
Texture& texture = Texture::instance();
Render& render = Render::instance();
Animation& animate = Animation::instance();
PhysicsDynamics& physicsDynamic = PhysicsDynamics::instance();
Physics& physics = Physics::instance();
Input& input = Input::instance();
 Update& update =  Update::instance();

void StartUp();
void Run();
void ShutDown();

void main()
{
	
	StartUp();
	Run();
	ShutDown();
}

void StartUp()
{
	cout << "Inicio......" << endl;
	memory.Start();
	file.Start();
	video.Start();
	audio.Start();
	texture.Start();
	render.Start();
	animate.Start();
	physicsDynamic.Start();
	physics.Start();
	input.Start();
	update.Start();
}

void Run()
{
	bool end = false;

	while (end == false)
	{
		cout << "Run........." << endl;
		memory.Run();
		file.Run();
		video.Run();
		audio.Run();
		texture.Run();
		render.Run();
		animate.Run();
		physicsDynamic.Run();
		physics.Run();
		input.Run();
		update.Run();

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			cout << "Apagar......" << endl;
			end = true;
		}
	}
	
}

void ShutDown()
{
	update.ShutDown();
	input.ShutDown();
	physics.ShutDown();
	physicsDynamic.ShutDown();
	animate.ShutDown();
	render.ShutDown();
	texture.ShutDown();
	audio.ShutDown();
	video.ShutDown();
	file.ShutDown();
	memory.ShutDown();
}
		