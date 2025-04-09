#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <time.h>


clock_t TimerStart()
{
    clock_t start = clock();
    printf("Timer started...\n");
    return start;
}

clock_t TimerStop()
{
	
    clock_t end = clock();
    printf("Timer stopped...\n"); 
	return end;
}

double ElapsedTime(clock_t start, clock_t end)
{
    double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    return seconds;
}

void HoldoneSceond()
{
	clock_t start = clock();
	while (1)
	{
		clock_t end = clock();
		double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
		if (seconds >= 1.0)
		{
			break;
		}
	}
}
#endif
