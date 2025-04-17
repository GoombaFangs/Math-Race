#ifndef SCORECALCULATOR_H
#define SCORECALCULATOR_H

#include <stdio.h>
#include "Player.h"
#include "Timer.h"

double score[3] = { 0.0, 0.0 , 0.0 };


void GetScore(double seconds, int round)
{
    switch (round)
    {
    case 0:
        score[0] = seconds * 0.2;
        break;
    case 1:
        score[1] = seconds * 0.3;
        break;
    case 2:
        score[2] = seconds * 0.5;
        break;
    default:
        break;
    }
}

double FinalScore(int playerNumber) 
{
    double finalScore = score[0] + score[1] + score[2];
	clearConsole();
	HoldSeconds(0.3);
    printg("%s\n", players[playerNumber - 1].name);
    printg("Yours final Score THIS ROUND is: %.2f\n", finalScore);
	return finalScore;
}

void PlacePlayers(int numberOfPlayer)//sort
{
	for (int i = 0; i < numberOfPlayer - 1; i++)
	{
        for (int j = 0; j < numberOfPlayer - i - 1; j++)
        {
            if (players[j].score > players[j + 1].score)
            {
                int temp = players[j].place;
                players[j].place = players[j+1].place;
                players[j+1].place = temp;
            }
        }
	}
}
#endif


