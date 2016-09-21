#include "..\include\GamePad.h"
#include <queue>
#include <deque>
#include <list>
#include <iterator>
#include "..\include\Events.h"
#include "..\include\EventList.h"

class Input
{
public:
	static Input instance()
	{
		static Input *input = new Input();
		return *input;
	}

	EventList lTemp;
	Events qTemp;
	int eType = 1;
	bool start = false;
	
	Input Start();
	Input Run();
	Input ShutDown();
	Input Listener();
	Input Dispatcher();

	queue<Events> Tail;
	list<EventList> List;

private:
	Input() {}
};