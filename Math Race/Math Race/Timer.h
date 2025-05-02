#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <time.h>
#include "Visuals.h"

clock_t TimerStart();
clock_t TimerStop();
double ElapsedTime(clock_t start, clock_t end);
void HoldSeconds(double second);
#endif