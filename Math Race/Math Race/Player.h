#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_PLAYERS 3 
#define _countof(array) (sizeof(array) / sizeof(array[0]))


typedef struct player 
{
	int playerNumber;
	char name[50];
	double score;
} Player;

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
		printf("Player %d saved successfully in %s\n", i + 1, fileName);
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

		printf("Player %d, Name: %s, Score: %.2f\n", i + 1, players[i].name, players[i].score);
		fclose(file); // Close file
	}
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
		return players[0]; // Return the first player as a fallback

	}

}
void PrintPlayerOptions(int numberOfPlayers)
{
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

	default:
		break;
	}
	return currentPlayer;
}
#endif

