#ifndef ROUNDS_H
#define ROUNDS_H

#include <stdio.h>
#include <string.h> 
#include <time.h>
#include "Timer.h"
#include "ScoreCalculator.h"
#include "visuals.h"

#define TOTAL_ROUNDS 3


void RoundTime(clock_t* startTime, clock_t* endTime, int* round)
{
	double roundDuration[TOTAL_ROUNDS];
	double finalScore = 0;
	roundDuration[*round] = ElapsedTime(*startTime, *endTime);//TIMER_H
	printf("round %d: %.2f seconds\n", *round + 1, roundDuration[*round]);
	GetScore(roundDuration[*round], *round);//SCORECALCULATOR_H
}

void PlayTheGame()
{
	int round = 0; 
	while (round < TOTAL_ROUNDS)
	{
		GetReadyForNextRound(round);//VISUALS_H
		clock_t startTime = TimerStart();
		printf("Round %d\n", round + 1);
		for (int i = 0; i < 2; i++)
		{
			printf("%d + %d?\n",i, i);
			int answer;
			scanf_s("%d", &answer);
		}
		clock_t endTime = TimerStop();
		RoundTime(&startTime, &endTime ,&round);
		round++;
	}
}
#endif


