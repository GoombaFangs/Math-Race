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
		printg("Enter Your name: ");
		scanf_s("%19s", players[numberOfPlayers].name, (unsigned)_countof(players[numberOfPlayers].name));

		NameArrangement(numberOfPlayers);//VISUALS_H

		players[numberOfPlayers].playerNumber = numberOfPlayers + 1;
		players[numberOfPlayers].place = numberOfPlayers + 1;

		SavePlayers(numberOfPlayers + 1);
		return players[numberOfPlayers];
	}
	else
	{
		printg("Maximum number of players reached\n");
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

	printg("Yours final score is: %.2f\n", players[player.playerNumber - 1].score);

	if (player.playerNumber > 1) 
	{
		PlacePlayers(player.playerNumber);//SCORECALCULATOR_H
	}

	SavePlayers(player.playerNumber);
}

Player ChooseAPlayer(int numberOfPlayers)
{
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
			NewPlayer(players);
			players++;
			SaveNumberOfPlayers(players);
			currentPlayer = ChooseAPlayer(players);
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

