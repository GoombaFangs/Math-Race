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

void GameEnd()
{
	printf("\n\nprass...\nA)Try again\nB)New Player\nC)Exit\n");
	char choice[10];
	scanf_s("%9s", choice, (unsigned)_countof(choice));
	if (strcmp(choice, "a") == 0 || strcmp(choice, "Try again") == 0 || strcmp(choice, "TryAgain") == 0)// Try Agian
	{
		GameStart();// ask the user who is playing?
	}
	else if (strcmp(choice, "b") == 0 || strcmp(choice, "New Player") == 0 || strcmp(choice, "NewPlayer") == 0)// New Player
	{
		NewPlayer();
	}
	else if (strcmp(choice, "c") == 0 || strcmp(choice, "Exit") == 0)// Exit
	{
		//exit
	}
	else
	{
		printf("Invalid choice..\n");
		GameEnd();
	}

}

void EndScreen()
{
	printf("Thanks for playing!");
	GameEnd();
}

void main() 
{
    printf("Welcome to Math Race!\n\n");
	NewPlayer();
	printf("game tuturial\n");// need to be more detailed
	GameStart();
	EndScreen();
}
