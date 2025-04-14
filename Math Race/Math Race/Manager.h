#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <string.h> 
#include <time.h>
#include "PlayerManager.h"
#include "Rounds.h"
#include "Timer.h"
#include "ScoreCalculator.h"
#include "Visuals.h"


int WhatNext()
{
	printf("\n\nPress...\nA) Try again\nB) New Player\nC) Exit\n");
	char choice[2];
	scanf_s("%1s", choice, (unsigned)_countof(choice));

	switch (choice[0])
	{
	case 'a':// Try again
		return 2;

	case 'b': // New Player
		return 3;

	case 'c': // Exit
		return 0;

	default:
		printf("Invalid choice. Please enter A, B, or C\n");
		return WhatNext();
	}
}

void AppStart()
{
	VisualManager();
	int theGameIsRunning = 1;
	int DoNext = 1;
	Player currentPlayer;
	currentPlayer = PlayerManager(DoNext);
	while (theGameIsRunning != 0)
	{
		switch (DoNext)
		{
		case 0:// exit the game
			theGameIsRunning = 0;
			break;

		case 1:// default
			PlayTheGame();//ROUNDS.H
			UpdatePlayerScore(currentPlayer);//PLAYERMANAGER.H
			printf("Thanks for playing!");
			DoNext = WhatNext();
			break;

		case 2:// try again
			currentPlayer = PlayerManager(DoNext);
			PlayTheGame();//ROUNDS.H
			UpdatePlayerScore(currentPlayer);//PLAYERMANAGER.H
			printf("Thanks for playing!");
			DoNext = WhatNext();
			break;

		case 3: //new player
			PlayerManager(DoNext);
			DoNext = 1;
			break;

		default:
			break;
		}
	}
}
#endif


