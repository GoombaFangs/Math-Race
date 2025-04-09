#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>

#define MAX_PLAYERS 3 
#define _countof(array) (sizeof(array) / sizeof(array[0]))


typedef struct player {
    char name[50];
    double score;
} Player;

Player players[MAX_PLAYERS];

int NumberOfPlayers = 0;

  void NewPlayer()
{
	if (NumberOfPlayers < MAX_PLAYERS) 
	{
		printf("Enter Your name: ");
		scanf_s("%49s", players[NumberOfPlayers].name, (unsigned)_countof(players[NumberOfPlayers].name));
		NumberOfPlayers++;
	}
	else
	{
		printf("Maximum number of players reached\n");
	}
}
#endif
