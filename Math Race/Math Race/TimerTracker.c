#include <stdio.h>
#include <time.h>

clock_t TimerStart();
void TimerStop(clock_t start);

clock_t TimerStart()
{
    clock_t start = clock();
    return start;
}

void TimerStop(clock_t start)
{
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", cpu_time_used);
}

