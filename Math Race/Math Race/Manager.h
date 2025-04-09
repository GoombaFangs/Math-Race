#include <stdio.h>
#include <string.h> 
#include <time.h>
#include "Player.h"
#include "Timer.h"



void GameStart()
{
	int round = 0;
	//ready for next round?
	while (round < 3)
	{
		clock_t start = TimerStart();
		printf("Round %d\n", round + 1);
		for (int i = 0; i < 2; i++)//need to change to 10 questions
		{
			printf("Question %d: What is %d + %d?\n", i + 1, i, i);//random question by difficukty (bass on round number)
			int answer;
			scanf_s("%d", &answer);
			printf("Your answer: %d\n", answer); //answer checker
		}
		TimerStop(start);
		round++;
	}
}

int WhatNext()
{
	printf("\n\nprass...\nA)Try again\nB)New Player\nC)Exit\n");
	char choice[10];
	scanf_s("%9s", choice, (unsigned)_countof(choice));
	if (strcmp(choice, "a") == 0 || strcmp(choice, "Try again") == 0 || strcmp(choice, "TryAgain") == 0)// Try Agian
	{
		// ask the user who is playing?
		return 1;
	}
	else if (strcmp(choice, "b") == 0 || strcmp(choice, "New Player") == 0 || strcmp(choice, "NewPlayer") == 0)// New Player
	{
		NewPlayer();
		return 1;
	}
	else if (strcmp(choice, "c") == 0 || strcmp(choice, "Exit") == 0)// Exit
	{
		//exit
		return 0;
	}
	else
	{
		printf("Invalid choice..\n");
		WhatNext();
		return 1;
	}
}

void ScoreCalculator()
{
	printf("Thanks for playing!");
}

void AppStart()
{
	int theGameIsRunning = 1;
	printf("Welcome to Math Race!\n\n");
	NewPlayer();
	while (theGameIsRunning == 1)
	{
		//Game tutorial
		GameStart();
		ScoreCalculator();
		theGameIsRunning = WhatNext();
	}
}
