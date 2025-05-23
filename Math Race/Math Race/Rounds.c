#include "Rounds.h"

void RoundTime(clock_t* startTime, clock_t* endTime, int* round, double penalty)
{
	double roundDuration[TOTAL_ROUNDS];
	double finalScore = 0;
	roundDuration[*round] = (ElapsedTime(*startTime, *endTime) + penalty);//TIMER_H
	printg(0.025, "round %d: %.2f seconds\n", *round + 1, roundDuration[*round]);
	HoldSeconds(0.2);
	if (*round < 2)
	{
		printg(0.025, "Get ready for the next round!\n");
	}
	GetScore(roundDuration[*round], *round);//SCORECALCULATOR_H
}

int PlayTheGame()
{
	int round = 0;
	while (round < TOTAL_ROUNDS)
	{
		PrintRounds(round + 1);
		GetReadyForNextRound(round);//VISUALS_H
		clock_t startTime = TimerStart();
		double penalty = GenerateAndCheckQuestion(round); //QGENERATORANDCHECKER_H
		if (penalty < 0)
		{
			return 0;
		}
		else 
		{
			clock_t endTime = TimerStop();
			RoundTime(&startTime, &endTime, &round, penalty);
			HoldSeconds(3);
			round++;
		}
	}
}