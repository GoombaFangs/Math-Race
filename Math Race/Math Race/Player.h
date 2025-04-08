#include <stdio.h>

#define MAX_PLAYERS 3

#ifndef _countof
#define _countof(array) (sizeof(array) / sizeof(array[0]))
#endif

typedef struct player {
    char name[50];
    int score;
} Player;

Player player[MAX_PLAYERS];
int playerNumber = 0;

void NewPlayer()
{
	if (playerNumber < MAX_PLAYERS) 
	{
		printf("Enter Your name: ");
		scanf_s("%49s", player[playerNumber].name, (unsigned int)_countof(player[playerNumber].name));
		playerNumber++;
	}
	else
	{
		printf("Maximum number of players reached.\n");
	}
}
