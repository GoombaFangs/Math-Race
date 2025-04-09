#include <stdio.h>
#include <time.h>

clock_t TimerStart();
void TimerStop(clock_t start);

clock_t TimerStart()
{
    clock_t start = clock();
    printf("Timer started...\n");
    return start;
}

void TimerStop(clock_t start)
{
	
    clock_t end = clock();
    double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Timer stopped...\n");
    printf("Elapsed time: %f seconds\n", seconds);
}

