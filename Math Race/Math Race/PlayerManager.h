#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <stdio.h>
#include <stdbool.h>
#include "ScoreCalculator.h"
#include "Player.h"
#include "SaveLoadData.h"
#include "Visuals.h"

#define _countof(array) (sizeof(array) / sizeof(array[0]))

Player PlayerManager(int decision);


Player NewPlayer(int numberOfPlayers)
{
	if (numberOfPlayers < MAX_PLAYERS)
	{
		printf("Enter Your name: ");
		scanf_s("%19s", players[numberOfPlayers].name, (unsigned)_countof(players[numberOfPlayers].name));

		NameArrangement(numberOfPlayers);//VISUALS_H

		players[numberOfPlayers].playerNumber = numberOfPlayers + 1;
		players[numberOfPlayers].place = numberOfPlayers + 1;

		SavePlayers(numberOfPlayers + 1);
		return players[numberOfPlayers];
	}
	else
	{
		printf("Maximum number of players reached\n");
		return players[0];
	}
}

void UpdatePlayerScore(Player player)
{
	double finalScore = FinalScore(player.playerNumber);//SCORECALCULATOR_H
	if (finalScore > players[player.playerNumber - 1].score)
	{
		players[player.playerNumber - 1].score = finalScore;
	}

	printf("Yours final score is: %.2f\n", players[player.playerNumber - 1].score);

	if (player.playerNumber > 1) 
	{
		PlacePlayers(player.playerNumber);//SCORECALCULATOR_H
	}

	SavePlayers(player.playerNumber);
}

Player ChooseAPlayer(int numberOfPlayers)
{
	PrintPlayerOptions(numberOfPlayers);//VISUALS_H
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
			else if(choice == numberOfPlayers + 1)
			{
				Player newPlayer = PlayerManager(3); //New Player
				return newPlayer;
			}
			else
			{
				PrintPlayerOptions(numberOfPlayers);//VISUALS_H
			}
		}
		else
		{
			PrintPlayerOptions(numberOfPlayers);//VISUALS_H
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

	case 2: // Try again
		currentPlayer = ChooseAPlayer(players);
		break;

	case 3: // New Player
		currentPlayer = NewPlayer(players);
		players++;
		SaveNumberOfPlayers(players);
		break;
	}
	return currentPlayer;
}
#endif

