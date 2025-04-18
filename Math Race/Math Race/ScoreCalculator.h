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
    printg(0.025 ,"%s\n", players[playerNumber - 1].name);
    printg(0.025, "Yours final Score THIS ROUND is: %.2f\n", finalScore);
	return finalScore;
}

void PlacePlayers(int numberOfPlayer)// Bubble sort
{
	for (int i = 0; i < numberOfPlayer; i++)
	{
        for (int j = i + 1; j < numberOfPlayer ; j++)
        {
            if (players[i].score > players[j].score)
            {
                int temp = players[i].place;
                players[i].place = players[j].place;
                players[j].place = temp;
            }
        }
	}
}
#endif


