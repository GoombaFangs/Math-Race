#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include "SaveLoad.h"
#include "ScoreCalculator.h"

#define MAX_PLAYERS 3 
#define _countof(array) (sizeof(array) / sizeof(array[0]))


typedef struct player {
	char name[50];
	double score;
} Player;

Player players[MAX_PLAYERS];

// save and load functions
void SavePlayers(int playerNumber, Player player);
void LoadPlayers(int numberOfPlayers);
void SaveNumberOfPlayers(int numberOfPlayers);
int LoadNumberOfPlayers(int numberOfPlayers);

Player NewPlayer(int numberOfPlayers)
{
	static Player newPlayer;
	if (numberOfPlayers < MAX_PLAYERS)
	{
		printf("Enter Your name: ");
		scanf_s("%49s", players[numberOfPlayers].name, (unsigned)_countof(players[numberOfPlayers].name));
		newPlayer = players[numberOfPlayers];
	}
	else
	{
		printf("Maximum number of players reached\n");
	}
	return newPlayer;
}

double UpdatePlayerScore(Player currentPlayer)
{
	currentPlayer.score = 100 - (score[0] + score[1] + score[2]);
	printf("%s, your final score is: %.1f\n", currentPlayer.name, currentPlayer.score);
	return currentPlayer.score;
}

Player PlayerManager(int decision, Player player)
{
	static int Players = 0;																 
	static Player currentPlayer;
	switch (decision)
	{
	case 1: // Default
		Players = LoadNumberOfPlayers(Players);
		//if (Players > 0)//need to fix
		//{
		//	LoadPlayers(Players);
		//	currentPlayer = players[0];
		//}
		 if (Players == 0)//good
		{
			currentPlayer = NewPlayer(Players);
			Players++;
			SaveNumberOfPlayers(Players);
		}
		return currentPlayer;
		break;

	case 2: // New Player //good
		currentPlayer = NewPlayer(Players);
		Players++;
		SaveNumberOfPlayers(Players);
		for (int i = 0; i < Players; i++)
		{
			SavePlayers(i, currentPlayer);
		}
		
		return currentPlayer;
		break;

	case 3: // Just Save //need to fix
		SaveNumberOfPlayers(Players);
		for (int i = 0; i < Players; i++)
		{
			SavePlayers(i, player);
		}
		currentPlayer = player;
		return currentPlayer;
		break;

	default:
		return currentPlayer;
		break;
	}
}
#endif