#ifndef SAVELOADDATA_H
#define SAVELOADDATA_H

#include <stdio.h>
#include <stdbool.h>
#include "ScoreCalculator.h"
#include "Player.h"
#include "PlayerManager.h"
#include "Visuals.h"

#ifndef _countof
#define _countof(array) (sizeof(array) / sizeof(array[0]))
#endif

Player players[MAX_PLAYERS];


void SaveNumberOfPlayers(int numberOfPlayers)
{
	FILE* file = fopen("numberOfPlayers.dat", "w"); // Open file
	if (file == NULL)
	{
		printg("Error: Could not open file player.dat for writing\n");
		return;
	}

	fprintf(file, "%d\n", numberOfPlayers);
	fclose(file); // Close file
	return;
}

int LoadNumberOfPlayers(int numberOfPlayers)
{
	FILE* file = fopen("numberOfPlayers.dat", "r"); // Open file
	if (file == NULL)
	{
		return 0;
	}

	if (fscanf_s(file, "%d", &numberOfPlayers) != 1 || numberOfPlayers > MAX_PLAYERS)
	{
		printg("Error: Invalid player count in file\n");
		fclose(file); // Close file
		return 0;
	}

	fclose(file); // Close file
	return numberOfPlayers;
}

void SavePlayers(int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		char fileName[20];
		snprintf(fileName, sizeof(fileName), "player%d.dat", i + 1);

		FILE* file = fopen(fileName, "w"); // Open files
		if (file == NULL)
		{
			printg("Error: Could not open file %s for writing\n", fileName);
			continue; 
		}

		// Save
		// player's data (playerNumber, name, score, place)
		fprintf(file, "Player number:%d\nName:%s\nScore:%.2lf\nplace:%d", 
			players[i].playerNumber, 
			players[i].name, 
			players[i].score,
			players[i].place);
		fclose(file); // Close file
	}
}

void LoadPlayers(int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		char fileName[20];
		snprintf(fileName, sizeof(fileName), "player%d.dat", i + 1);

		FILE* file = fopen(fileName, "r"); // Open files
		if (file == NULL)
		{
			printg("Error: Could not open file %s for reading\n", fileName);
			continue;
		}

		// Load 
		// player's data (playerNumber, name, score, place)
		if (fscanf_s(file, "Player number:%d\nName:%19s\nScore:%lf\nplace:%d", 
			&players[i].playerNumber, 
			players[i].name, (unsigned)_countof(players[i].name), 
			&players[i].score , 
			&players[i].place) != 4)
		{
			printg("Error: Invalid data in %s. Stopping load for this player\n", fileName);
			fclose(file);
			continue; 
		}
		fclose(file); // Close file
	}
}
#endif