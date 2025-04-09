#include <stdio.h>
#include <string.h> 
#include <time.h>
#include "Player.h"
#include "Timer.h"
#include "ScoreCalculator.h"


void MainGame()
{
	int round = 0;
	//ready for next round?
	while (round < 3)
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
		ElapsedTime(startTime , endTime);
		round++;
	}
}

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
	   NewPlayer();
	   return 1;

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
	printf("Welcome to Math Race!\n\n");
	NewPlayer();
	while (theGameIsRunning == 1)
	{
		//Game tutorial
		MainGame();
		printf("Thanks for playing!");
		GetScore();
		theGameIsRunning = WhatNext();
	}
}
