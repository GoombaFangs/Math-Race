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
        score[0] = seconds;
        break;
    case 1:
        score[1] = seconds;
        break;
    case 2:
        score[2] = seconds;
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

void PlacePlayers(int numberOfPlayers)// Bubble sort
{
    for (int i = 0; i < numberOfPlayers - 1; i++)
	{
        for (int j = 0; j < numberOfPlayers - i - 1; j++)
        {
            if (players[j].score < players[j + 1].score)
            {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
	}
    for (int i = 0; i < numberOfPlayers; i++)
    {
        players[i].place = numberOfPlayers - i;
    }
}
#endif


