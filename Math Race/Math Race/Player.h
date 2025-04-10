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

void SaveNumberOfPlayers()
{
	FILE* file = fopen("numberOfPlayers.dat", "w"); // Open file
	if (file == NULL)
	{
		printf("Error: Could not open file player.dat for writing.\n");
		return;
	}

	fprintf(file, "%d\n", NumberOfPlayers);// Saveing NumberOfPlayers
	fclose(file); // Close file
	printf("NumberOfPlayers saved successfully.\n");
	return;
}

void SavePlayers() // Save each player
{
	for (int i = 0; i < NumberOfPlayers; i++) 
	{
		char fileName[20];
		snprintf(fileName, sizeof(fileName), "player%d.dat", i + 1);

		FILE* file = fopen(fileName, "w"); // Open files
		if (file == NULL)
		{
			printf("Error: Could not open file %s for writing.\n", fileName);
			continue; // Skip to the next player if the file cannot be opened
		}

		fprintf(file, "%s %.2lf\n", players[i].name, players[i].score); // Save player's name and score
		fclose(file); // Close file
		printf("Player %d saved successfully in %s.\n", i + 1, fileName);
	}
}

void LoadNumberOfPlayers() 
{
	FILE* file = fopen("numberOfPlayers.dat", "r"); // Open file in read mode
	if (file == NULL)
	{
		NumberOfPlayers = 0;
		printf("No players found. Starting with 0 players.\n");
		return;
	}

	if (fscanf_s(file, "%d", &NumberOfPlayers) != 1 || NumberOfPlayers > MAX_PLAYERS) // Load NumberOfPlayers
	{
		printf("Error: Invalid player count in file.\n");
		NumberOfPlayers = 0;
		fclose(file); // Close file
		return;
	}
	printf("Player loaded successfully. Number of players: %d\n", NumberOfPlayers);
	fclose(file); // Close file
}
void LoadPlayers()
{
	for (int i = 0; i < NumberOfPlayers; i++) // Load each player's name and score
	{
		char fileName[20]; // Buffer to hold the file name
		snprintf(fileName, sizeof(fileName), "player%d.dat", i + 1); // Generate file name dynamically

		FILE* file = fopen(fileName, "r"); // Open file for the specific player
		if (file == NULL)
		{
			printf("Error: Could not open file %s for reading.\n", fileName);
			continue; // Skip to the next player if the file cannot be opened
		}

		if (fscanf_s(file, "%49s %lf", players[i].name, (unsigned)_countof(players[i].name), &players[i].score) != 2)
		{
			printf("Error: Invalid data in %s. Stopping load for this player.\n", fileName);
			fclose(file);
			continue; // Skip to the next player if the data is invalid
		}

		printf("Player %d loaded successfully from %s. Name: %s, Score: %.2f\n", i + 1, fileName, players[i].name, players[i].score);
		fclose(file); // Close file
	}
	printf("All players loaded successfully.\n");
}

void PlayerManager()
{	
	LoadNumberOfPlayers(); 
	if (NumberOfPlayers > 0)
	{
		LoadPlayers(); 
	}
	else if(NumberOfPlayers == 0)
	{
		NewPlayer(); 
	}
}

void NewPlayer()
{
	if (NumberOfPlayers < MAX_PLAYERS)
	{
		printf("Enter Your name: ");
		scanf_s("%49s", players[NumberOfPlayers].name, (unsigned)_countof(players[NumberOfPlayers].name));
		NumberOfPlayers++;
		SaveNumberOfPlayers();
		printf("New player created and saved.\n");
	}
	else
	{
		printf("Maximum number of players reached\n");
	}
}

#endif