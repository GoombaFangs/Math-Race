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

int NumberOfPlayers;
void NewPlayer();

void SavePlayers()
{
	FILE* file = fopen("player.dat", "w"); // Open file
	if (file == NULL)
	{
		printf("Error: Could not open file player.dat for writing.\n");
		return;
	}

	fprintf(file, "%d\n", NumberOfPlayers);// Saveing NumberOfPlayers

	for (int i = 0; i < NumberOfPlayers; i++) // Saveing each player's name and score
	{
		fprintf(file, "%s %.2lf\n", players[i].name, players[i].score);
	}

	fclose(file); // Close file
	printf("Players and NumberOfPlayers saved successfully.\n");
	return;
}

void LoadPlayers()
{
	FILE* file = fopen("player.dat", "r"); // Open file in read mode
	if (file == NULL)
	{
		printf("Error: Could not open file player.dat for reading.\n");
		return;
	}

	for (int i = 0; i < NumberOfPlayers; i++) // Load each player's name and score
	{
		if (fscanf_s(file, "%d %49s %lf", &NumberOfPlayers, players[i].name, (unsigned)_countof(players[i].name), &players[i].score) != 3)
		{
			printf("Error: Invalid data for player %d. Stopping load.\n", i + 1);
			NumberOfPlayers = i; // Adjust player count to valid entries
			fclose(file);
			return;
		}
		printf("Player number %d, welcome back %s, your score is: %.2f\n", NumberOfPlayers , players[i].name, players[i].score);
	}
	fclose(file); // Close file
	printf("Players loaded successfully.\n");
}
void PlayerManager()
{
	FILE* file = fopen("player.dat", "r"); // Open file in read mode
	if (file == NULL)
	{
		NumberOfPlayers = 0;
		printf("No players found. Starting with 0 players.\n");
		NewPlayer();
		return;
	}

	if (fscanf_s(file, "%d", &NumberOfPlayers) != 1 || NumberOfPlayers > MAX_PLAYERS) // Load NumberOfPlayers
	{
		printf("Error: Invalid player count in file.\n");
		NumberOfPlayers = 0;
		fclose(file);
		NewPlayer();
		return;
	}

	if (NumberOfPlayers > 0)
	{
		fclose(file); // Close file
		LoadPlayers(); // Load players if there are any
	}
	printf("Player count loaded successfully. Number of players: %d\n", NumberOfPlayers);
}

void NewPlayer()
{
	if (NumberOfPlayers < MAX_PLAYERS)
	{
		printf("Enter Your name: ");
		scanf_s("%49s", players[NumberOfPlayers].name, (unsigned)_countof(players[NumberOfPlayers].name));
		NumberOfPlayers++;
		SavePlayers();
		printf("New player created and saved.\n");
	}
	else
	{
		printf("Maximum number of players reached\n");
	}
}

#endif