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
		printf("Error: Could not open file %s for writing.\n", "player.dat");
		return;
	}

	fprintf(file, "%d\n", NumberOfPlayers);// Saveing NumberOfPlayers

	for (int i = 0; i < NumberOfPlayers; i++) // Saveing each player's name and score
	{
		fprintf(file, "%s %.2lf\n", players[i].name, players[i].score);
	}

	fclose(file); // Close file
	printf("Players and NumberOfPlayers saved successfully.\n");
}

void LoadPlayers()
{
	FILE* file = fopen("player.dat", "r"); // Open file 
	if (file == NULL)
	{
		printf("Error: Could not open file player.dat for reading.\n");
		return;
	}

	for (int i = 0; i < NumberOfPlayers; i++) // Load each player's name and score
	{
		if (fscanf_s(file, "%49s %lf", players[i].name, (unsigned)_countof(players[i].name), &players[i].score) != 2)
		{
			printf("welcome back %s your score is: %1f\n", players[i].name, players[i].score);
			fclose(file);
			return;
		}
	}
	fclose(file); // Close  file
	printf("Players loaded successfully.\n");
}
void PlayerManager()
{
	FILE* file = fopen("player.dat", "r"); // Open file 
	if (file == NULL)
	{
		printf("No players found. Starting with 0 players.\n");
		NumberOfPlayers = 0;
		NewPlayer();
		SavePlayers();
		printf("New player created and saved.\n");
		return;
	}

	if (fscanf_s(file, "%d", &NumberOfPlayers) != 1 || NumberOfPlayers > MAX_PLAYERS)//loading NumberOfPlayers
	{
		printf("Error: Invalid number of players in file.\n");
		fclose(file);
		return;
	}
	fclose(file); // Close file
	printf("Player count loaded successfully. Number of players: %d\n", NumberOfPlayers);

	if (NumberOfPlayers > 0)
	{
		LoadPlayers(); // Load players if there are any
	}
}

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