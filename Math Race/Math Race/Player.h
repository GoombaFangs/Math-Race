#ifndef PLAYER_H
#define PLAYER_H

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
int NumberOfPlayers = 0;

void NewPlayer()
{
	if (NumberOfPlayers < MAX_PLAYERS) 
	{
		printf("Enter Your name: ");
		scanf_s("%49s", player[NumberOfPlayers].name, (unsigned)_countof(player[NumberOfPlayers].name));
		NumberOfPlayers++;
	}
	else
	{
		printf("Maximum number of players reached\n");
	}
}
#endif
