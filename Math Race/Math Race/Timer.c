#include "Timer.h"

clock_t TimerStart()
{
	clock_t start = clock();
	return start;
}

clock_t TimerStop()
{
	clock_t end = clock();
	return end;
}

double ElapsedTime(clock_t start, clock_t end)
{
	double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
	return seconds;
}

void HoldSeconds(double second)
{
	clock_t start = clock();
	while (1)
	{
		clock_t end = clock();
		double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
		if (seconds >= second)
		{
			break;
		}
	}
}