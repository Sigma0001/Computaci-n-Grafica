#pragma once
#include <iostream>
#include <Windows.h>
class  Update
{
public:
	static  Update instance()
	{
		static  Update *update = new  Update();
		return *update;
	}

	 Update Start();
	 Update Run();
	 Update ShutDown();


private:
	 Update() {}

};