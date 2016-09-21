#pragma once

#include <vector>
#include <list>
#include <iostream>

class EventList
{
public:
	int type;
	EventList(int Itype) {
		type = Itype;
	}

	bool Callback();

	EventList() {}
};