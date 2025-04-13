#ifndef SAVELOADDATA_H
#define SAVELOADDATA_H

#include <stdio.h>
#include <stdbool.h>
#include "ScoreCalculator.h"
#include "Player.h"
#include "PlayerManager.h"

#define MAX_PLAYERS 15 
#define _countof(array) (sizeof(array) / sizeof(array[0]))

Player players[MAX_PLAYERS];

void SaveNumberOfPlayers(int numberOfPlayers)
{
	FILE* file = fopen("numberOfPlayers.dat", "w"); // Open file
	if (file == NULL)
	{
		printf("Error: Could not open file player.dat for writing\n");
		return;
	}

	fprintf(file, "%d\n", numberOfPlayers);// Saveing NumberOfPlayers
	fclose(file); // Close file
	return;
}

void SavePlayers(int numberOfPlayers) // Save each player
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		char fileName[20];
		snprintf(fileName, sizeof(fileName), "player%d.dat", i + 1);

		FILE* file = fopen(fileName, "w"); // Open files
		if (file == NULL)
		{
			printf("Error: Could not open file %s for writing\n", fileName);
			continue; // Skip to the next player if the file cannot be opened
		}

		fprintf(file, "Player number:%d\nName:%s\nScore:%.2lf\n", players[i].playerNumber, players[i].name, players[i].score); // Save player's name and score
		fclose(file); // Close file
	}
}

int LoadNumberOfPlayers(int numberOfPlayers)
{
	FILE* file = fopen("numberOfPlayers.dat", "r"); // Open file
	if (file == NULL)
	{
		printf("No players found. Starting with 0 players\n");
		return 0;
	}

	if (fscanf_s(file, "%d", &numberOfPlayers) != 1 || numberOfPlayers > MAX_PLAYERS)
	{
		printf("Error: Invalid player count in file\n");
		fclose(file); // Close file
		return 0;
	}
	printf("Number of players found: %d\n", numberOfPlayers);
	fclose(file); // Close file
	return numberOfPlayers;
}

void LoadPlayers(int numberOfPlayers) // Load each player
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		char fileName[20];
		snprintf(fileName, sizeof(fileName), "player%d.dat", i + 1);

		FILE* file = fopen(fileName, "r"); // Open files
		if (file == NULL)
		{
			printf("Error: Could not open file %s for reading\n", fileName);
			continue; // Skip to the next player if the file cannot be opened
		}

		if (fscanf_s(file, "Player number:%d\nName:%49s\nScore:%lf\n", &players[i].playerNumber, players[i].name, (unsigned)_countof(players[i].name), &players[i].score) != 3)
		{
			printf("Error: Invalid data in %s. Stopping load for this player\n", fileName);
			fclose(file);
			continue; // Skip to the next player if the data is invalid
		}
		fclose(file); // Close file
	}
}
#endif