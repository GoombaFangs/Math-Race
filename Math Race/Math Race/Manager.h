#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <string.h> 
#include <time.h>
#include "SaveLoad.h"
#include "Player.h"
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
	   return 1; 

   case 'b': // New Player
	   return 2;

   case 'c': // Exit
	   return 0; 

   default:
	   printf("Invalid choice. Please enter A, B, or C\n");
	   return WhatNext();
   }
}

void AppStart()
{
	int theGameIsRunning = 1;
	int DoNext = 1;
	static Player currentPlayer = { "", 0.0 };
	//PrintTitle();
    currentPlayer = PlayerManager(DoNext, currentPlayer);
	//Main Menu
	//Game tutorial
	while (theGameIsRunning != 0) //the game loop
	{
		switch (DoNext)
		{
		case 0:// exit the game
			theGameIsRunning = 0;
			break;

		case 1:
			//ask the user who is playing
			PlayTheGame();
			double finalScore = UpdatePlayerScore(currentPlayer);
			currentPlayer.score = finalScore;
			PlayerManager(3 , currentPlayer);
			printf("Thanks for playing!");
			DoNext = WhatNext();
			break;

		case 2: //new player
			PlayerManager(DoNext , currentPlayer);
			DoNext = 1;
			break;

		default:
			break;
		}
	}
}
#endif
