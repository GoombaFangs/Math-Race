#include <stdio.h>
#include <string.h> 
#include "Player.c"


#ifndef _countof
#define _countof(array) (sizeof(array) / sizeof(array[0]))
#endif


void NewPlayer(int playerNumber)
{	
    printf("Enter Your name: ");
	char name[50];
	scanf_s("%49s", name, (unsigned int)_countof(name));
	strcpy_s(player[playerNumber].name, sizeof(name), name);

}

void GameEnd()
{
	printf("Thanks for playing!\n\n\nprass...\nA)Try again\nB)New Player\nC)Exit...\n");
	char choice[10];
	scanf_s("%9s", choice, (unsigned)_countof(choice));
	if (strcmp(choice, "a") == 0 || strcmp(choice, "Try again") == 0 || strcmp(choice, "Tryagain") == 0)// Try Agian
	{
		printf("Try again\n");
	}
	else if (strcmp(choice, "b") == 0 || strcmp(choice, "New Player") == 0 || strcmp(choice, "NewPlayer") == 0)// New Player
	{
		printf("New Player\n");
	}
	else if (strcmp(choice, "c") == 0 || strcmp(choice, "Exit") == 0)// Exit
	{
		printf("Exit\n");
		exit(0);
	}
	else
	{
		printf("Invalid choice..\n");
		GameEnd();
	}

}
void GameStart()
{
	int round = 0;
	while (round < 3)
	{
		//timer start
		printf("Round %d\n", round + 1);
		for (int i = 0; i < 2; i++)//need to change to 10 questions
		{
			printf("Question %d: What is %d + %d?\n", i + 1, i, i);//random question by difficukty (bass on round number)
			int answer;
			scanf_s("%d", &answer);
			printf("Your answer: %d\n", answer); //answer checker
		}
		//timer stop
		round++;
	}
}
void main() 
{
    printf("Welcome to Math Race!\n\n");
	int playerCount = 0;
	NewPlayer(playerCount);
	playerCount++;
	printf("Player 1 name is: %s\n", player[0].name);

	printf("game tuturial\n");// need to be more detailed
	GameStart();
	GameEnd();
}
