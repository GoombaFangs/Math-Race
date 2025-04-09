#ifndef SCORECALCULATOR_H
#define SCORECALCULATOR_H

#include <stdio.h>
#include "Player.h"
#include "Timer.h"

double ScroeCalculator(double* scoreFirstRound, double* scoreSecondRound, double* scoreThirdRound)
{
    double finalScore = *scoreFirstRound + *scoreSecondRound + *scoreThirdRound;
    printf("Total score: %.1f\n", finalScore);
    return finalScore;
}

double score[3] = { 0.0, 0.0 , 0.0 };

void GetScore(double seconds , int round)
{
    switch (round)
    {
    case 0:
        score[0] = seconds * 0.2;
        printf("First round score: %.1f\n", score[0]);
        break;
    case 1:
        score[1] = seconds * 0.3;
        printf("Second round score: %.1f\n", score[1]);;
        break;
	case 2:
        score[2] = seconds * 0.5;
		printf("Third round score: %.1f\n", score[2]);
		break;
    default:
		printf("Invalid round number\n");
        break;
    }
    if (score[0] != 0.0 && score[1] != 0.0 && score[2] != 0.0) 
    {
        ScroeCalculator(&score[0], &score[1], &score[2]);
    }
}
 void UpdatePlayerScore()
 {
	 for (int i = 0; i < NumberOfPlayers; i++)
	 {
		 players[i].score = score[0] + score[1] + score[2];
		 printf("Player %s, your final score is: %.1f\n", players[i].name, players[i].score);
	 }
 }
#endif
