#include "..\include\EventList.h"
#include "..\include\GamePad.h"

bool EventList::Callback()
{
	switch (type)
	{
		case 1:
			cout << "Soy 1\n";
			return true;
		case 2:
			cout << "Soy 2\n";
			return true;
		case 3:
			cout << "Soy 3\n";
			return true;
		case 4:
			cout << "Soy 4\n";
			return true;
		case 5:
			cout << "Soy 5\n";
			return true;

	}
}
