#ifndef SCORECALCULATOR_H
#define SCORECALCULATOR_H

#include <stdio.h>
#include "Player.h"
#include "Timer.h"

void GetScore(double seconds , int round)
{
    double score[3];
    switch (round)
    {
    case 0:
        score[0] = seconds * 0.2;
        printf("First round score: %.1f\n", score[0]);
        break;
    case 1:
        score[1] = seconds * 0.3;
        printf("Second round score: %.1f\n", score[1]);
        break;
	case 2:
        score[2] = seconds * 0.5;
		printf("Third round score: %.1f\n", score[2]);
		break;
    default:
        printf("Invalid round. No score calculated.\n");
        break;
    }
}

#endif
