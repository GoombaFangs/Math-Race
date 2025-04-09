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
	static double elapsedTime[TOTAL_ROUNDS];
	elapsedTime[*round] = ElapsedTime(*startTime, *endTime);
	printf("Elapsed time for round %d: %.2f seconds\n", *round + 1, elapsedTime[*round]);
	GetScore(elapsedTime[*round], *round);	
}

void MainGame()
{
	static int round = 0;
	//ready for next round?
	while (round < TOTAL_ROUNDS)
	{
		clock_t startTime = TimerStart();
		printf("Round %d\n", round + 1);
		for (int i = 0; i < 2; i++)//need to change to 10 questions
		{
			printf("Question %d: What is %d + %d?\n", i + 1, i, i);//random question by difficukty (bass on round number)
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


