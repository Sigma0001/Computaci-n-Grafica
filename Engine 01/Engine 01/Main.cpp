#include "Main.h"

void engineStat()
{
	memoStart();
	audioStart();
	videoStart();
	physicStart();
	renderStart();
}

void engineStop()
{	
	renderStop();
	physicStop();
	videoStop();
	audioStop();
	memoStop();
}

int main()
{
	engineStat();
	std::cout << "\n";
	engineStop();
	return 0;
}

