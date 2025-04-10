#ifndef ROUNDS_H
#define ROUNDS_H

#include <stdio.h>
#include <string.h> 
#include <time.h>
#include "Timer.h"
#include "ScoreCalculator.h"

#define TOTAL_ROUNDS 3

void RoundTime(clock_t* startTime, clock_t* endTime, int* round)
{
	double roundDuration[TOTAL_ROUNDS];
	roundDuration[*round] = ElapsedTime(*startTime, *endTime);
	printf("round %d: %.2f seconds\n", *round + 1, roundDuration[*round]);
	GetScore(roundDuration[*round], *round);	
}

void GetReadyForNextRound(int round)
{
	if (round != 0) 
	{
	printf("Get ready for the next round!\n");
	}
	for (int i = 3; i > 0; i--)
	{
		printf("%d...\n", i);
		HoldSceonds(1.0);
	}
	printf("Go!\n");
}

void PlayTheGame()
{
	 int round = 0; 
	while (round < TOTAL_ROUNDS)
	{
		GetReadyForNextRound(round);
		clock_t startTime = TimerStart();
		printf("Round %d\n", round + 1);
		for (int i = 0; i < 2; i++)//need to change to 10 questions
		{
			printf("%d + %d?\n",i, i);//random question by difficukty (bass on round number)
			int answer;
			scanf_s("%d", &answer);
			//answer checker
		}
		clock_t endTime = TimerStop();
		RoundTime(&startTime, &endTime ,&round);
		round++;
	}
}
#endif


