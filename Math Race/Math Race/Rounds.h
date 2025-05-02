#ifndef ROUNDS_H
#define ROUNDS_H

#include <stdio.h>
#include <string.h> 
#include <time.h>
#include "Timer.h"
#include "ScoreCalculator.h"
#include "visuals.h"
#include "Q&A.h"

#define TOTAL_ROUNDS 3

void RoundTime(clock_t* startTime, clock_t* endTime, int* round, double penalty);
void PlayTheGame();
#endif