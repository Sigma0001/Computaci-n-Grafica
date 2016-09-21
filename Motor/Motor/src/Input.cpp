#include "..\include\Input.h"

Input Input::Start()
{
	Sleep(500);
	Listener();
	cout << "Input Start\n";
	start = true;
	return Input();
}

Input Input::Run()
{
	Sleep(500);
	cout << "Input Run\n";
	GamePad gamepad;

	bool wasConnected = true;

	while (start == true)
	{
		Sleep(100);

		if (!gamepad.Refresh())
		{
			if (wasConnected)
			{
				wasConnected = false;

				//cout << "Please connect an Xbox 360 controller." << endl;
			}
		}
		else
		{
			if (!wasConnected)
			{
				wasConnected = true;

				//cout << "Controller connected on port " << gamepad.GetPort() << endl;
			}

			//cout << "Left thumb stick: (" << gamepad.leftStickX << ", " << gamepad.leftStickY << ")   Right thumb stick : (" << gamepad.rightStickX << ", " << gamepad.rightStickY << ")" << endl;

			//cout << "Left analog trigger: " << gamepad.leftTrigger << "   Right analog trigger: " << gamepad.rightTrigger << endl;

			if (gamepad.IsPressed(XINPUT_GAMEPAD_A))
			{
				Events(1);
				Tail.push(1);

				cout << "(A) button pressed" << endl;
			}

			if (gamepad.IsPressed(XINPUT_GAMEPAD_B))
			{
				Events(2);
				Tail.push(2);

				cout << "(B) button pressed" << endl;
			}

			if (gamepad.IsPressed(XINPUT_GAMEPAD_X))
			{
				Events(3);
				Tail.push(3);

				cout << "(X) button pressed" << endl;
			}

			if (gamepad.IsPressed(XINPUT_GAMEPAD_Y))
			{
				Events(4);
				Tail.push(4);

				cout << "(Y) button pressed" << endl;
			}
			
			if (gamepad.IsPressed(XINPUT_GAMEPAD_START))
			{
				Events(5);
				Tail.push(5);
				cout << "(START) button pressed" << endl;
				start = false;
			}
			Dispatcher();
		}
	}//while xinput
	return Input();//666
}

Input Input::ShutDown()
{
	Sleep(500);
	cout << "Input Shut Down\n";
	return Input();
}

Input Input::Listener()
{
	//ask game state

	//create listener depending on game state

	for (int i = 0; i < 16; i++)
	{
		EventList(eType + i);
		List.push_back(i);
	}

	return Input();
}

Input Input::Dispatcher()
{
	while (!Tail.empty())
	{
		qTemp = Tail.front();
		Tail.pop();
		for (list<EventList>::iterator it = List.begin();
		it != List.end(); ++it)
		{
			if (qTemp.type == it->type)
			{
				cout << qTemp.type << ", " << it->type << endl;

				if (it->Callback() == true)
				{
					break;
				}//if
			}//if
		}//for
	}//dispatcher
	return Input();
}
