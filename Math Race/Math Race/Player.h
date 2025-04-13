#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include "SaveLoad.h"

#define MAX_PLAYERS 3 
#define _countof(array) (sizeof(array) / sizeof(array[0]))


typedef struct player {
	char name[50];
	double score;
} Player;

Player players[MAX_PLAYERS];

void SavePlayers(int numberOfPlayers);
void LoadPlayers(int numberOfPlayers);
void SaveNumberOfPlayers(int numberOfPlayers);
int LoadNumberOfPlayers(int numberOfPlayers);

void NewPlayer(int numberOfPlayers)
{
	if (numberOfPlayers < MAX_PLAYERS)
	{
		printf("Enter Your name: ");
		scanf_s("%49s", players[numberOfPlayers].name, (unsigned)_countof(players[numberOfPlayers].name));
	}
	else
	{
		printf("Maximum number of players reached\n");
	}
}

int PlayerManager(int decision)
{
	static int Players = 0;
	static int currentPlayer = 0;
	switch (decision)
	{
	case 1: // Default
		Players = LoadNumberOfPlayers(Players);
		if (Players > 0)
		{
			LoadPlayers(Players);
		}
		else if (Players == 0)
		{
			NewPlayer(Players);
			Players++;
			SaveNumberOfPlayers(Players);
			SavePlayers(Players);
		}
		break;

	case 2: // New Player
		NewPlayer(Players);
		Players++;
		SaveNumberOfPlayers(Players);
		SavePlayers(Players);
		break;

	case 3: // Just Save
		SaveNumberOfPlayers(Players);
		SavePlayers(Players);
		break;

	default:
		break;
	}
	return Players;
}
#endif