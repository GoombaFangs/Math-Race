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

#endif
