#ifndef SCORECALCULATOR_H
#define SCORECALCULATOR_H

#include <stdio.h>
#include "Player.h"
#include "Timer.h"

double score[3] = { 0.0, 0.0 , 0.0 };

void GetScore(double seconds , int round)
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
 void UpdatePlayerScore()
 {
     players[NumberOfPlayers - 1].score = 100 - (score[0] + score[1] + score[2]);
     printf("%s, your final score is: %.1f\n", players[NumberOfPlayers - 1].name, players[NumberOfPlayers - 1].score);
	 SavePlayers();
 }
#endif
