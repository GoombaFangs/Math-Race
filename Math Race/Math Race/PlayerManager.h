#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <stdio.h>
#include <stdbool.h>
#include "ScoreCalculator.h"
#include "Player.h"
#include "SaveLoadData.h"

#define MAX_PLAYERS 15 
#define _countof(array) (sizeof(array) / sizeof(array[0]))


void UpdatePlayerScore(int numberOfPlayers)
{
	players[numberOfPlayers - 1].score = FinalScore();
	printf("%s, your final score is: %.1f\n", players[numberOfPlayers - 1].name, players[numberOfPlayers - 1].score);
	SavePlayers(numberOfPlayers);
}

Player NewPlayer(int numberOfPlayers)
{
	if (numberOfPlayers < MAX_PLAYERS)
	{
		printf("Enter Your name: ");
		scanf_s("%49s", players[numberOfPlayers].name, (unsigned)_countof(players[numberOfPlayers].name));
		players[numberOfPlayers].playerNumber = numberOfPlayers + 1;
		return players[numberOfPlayers];
	}
	else
	{
		printf("Maximum number of players reached\n");
		return players[0];

	}

}

void PrintPlayerOptions(int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		printf("Player %d, Name: %s, Score: %.2f\n", i + 1, players[i].name, players[i].score);
	}
	printf("Choose a player\nPress.. ");
	for (int i = 1; i <= numberOfPlayers; i++)
	{
		printf("%d", i);
		if (i != numberOfPlayers) printf(" or ");

	}
	printf(":");
}

Player ChooseAPlayer(int numberOfPlayers)
{
	PrintPlayerOptions(numberOfPlayers);

	int choice;
	while (true)
	{
		if (scanf_s("%d", &choice) == 1)
		{
			if (choice >= 1 && choice <= numberOfPlayers)
			{
				printf("You chose %s\n", players[choice - 1].name);
				return players[choice - 1];
			}
			else
			{
				PrintPlayerOptions(numberOfPlayers);
			}
		}
		else
		{
			PrintPlayerOptions(numberOfPlayers);
			while (getchar() != '\n'); // Clear the input buffer
		}
	}

}

Player PlayerManager(int decision)
{
	static int players = 0;
	static Player currentPlayer;
	switch (decision)
	{
	case 1: // Default
		players = LoadNumberOfPlayers(players);
		if (players > 0)
		{
			LoadPlayers(players);
			currentPlayer = ChooseAPlayer(players);
		}
		else if (players == 0)
		{
			currentPlayer = NewPlayer(players);
			players++;
			SaveNumberOfPlayers(players);
		}
		break;

	case 2: // New Player
		currentPlayer = NewPlayer(players);
		players++;
		SaveNumberOfPlayers(players);
		break;

	case 3:	// Choose Player
		currentPlayer = ChooseAPlayer(players);
		break;
	}
	return currentPlayer;
}
#endif

