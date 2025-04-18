#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <stdio.h>
#include <stdbool.h>
#include "ScoreCalculator.h"
#include "Player.h"
#include "SaveLoadData.h"
#include "Visuals.h"


Player PlayerManager(int decision);


Player NewPlayer(int numberOfPlayers)
{
	if (numberOfPlayers < MAX_PLAYERS)
	{
		printg(0.035, "Enter Your name: ");
		scanf_s("%19s", players[numberOfPlayers].name, (unsigned)_countof(players[numberOfPlayers].name));

		NameArrangement(numberOfPlayers);//VISUALS_H

		players[numberOfPlayers].score = 1000.0;
		players[numberOfPlayers].playerNumber = numberOfPlayers + 1;
		players[numberOfPlayers].place = numberOfPlayers + 1;

		SavePlayers(numberOfPlayers + 1);
		return players[numberOfPlayers];
	}
	else
	{
		printg(0.025, "Maximum number of players reached\n");
		return players[0];
	}
}

void UpdatePlayerScore(Player player , int numberOfPlayers)
{
	double finalScore = FinalScore(player.playerNumber);//SCORECALCULATOR_H
	if (finalScore < players[player.playerNumber - 1].score)
	{
		players[player.playerNumber - 1].score = finalScore;
	}

	HoldSeconds(0.2);
	printg(0.025, "Yours final score is: %.2f\n", players[player.playerNumber - 1].score);

	if(numberOfPlayers > 1)
	{
		PlacePlayers(numberOfPlayers);//SCORECALCULATOR_H
	}

	SavePlayers(numberOfPlayers);
}

Player ChooseAPlayer(int numberOfPlayers)
{
	HoldSeconds(0.1);
	int choice = PrintPlayerOptions(numberOfPlayers);//VISUALS_H
	if (choice == numberOfPlayers)
	{
		Player newPlayer = PlayerManager(3); // New Player
		return newPlayer;
	}
	else
	{
		return players[choice];
	}
}
int GetNumberOfPlayers()
{
	int numberOfPlayers = LoadNumberOfPlayers(0);
	return numberOfPlayers;
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

	case 2: // leaderborad
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

