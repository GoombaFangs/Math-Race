#ifndef VISUALS_H
#define VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Title.h"
#include "Timer.h"
#include "MenuScroll.h"
#include "KeyBinding.h"


void clearConsole() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void GetReadyForNextRound(int round)//ROUNDS.H
{
	if (round != 0)
	{
		printf("Get ready for the next round!\n");
	}
	for (int i = 3; i > 0; i--)
	{
		printf("%d...\n", i);
		HoldSceonds(1.0);
	}
	printf("Go!\n");
}

void PrintPlayerOptions(int numberOfPlayers)//PLAYERMANAGER.H
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		printf("%d) %s\n", players[i].playerNumber, players[i].name);
	}

	printf("Choose a player\nPress.. ");

	for (int i = 1; i <= numberOfPlayers; i++)
	{
		printf("%d", i);
		if (i - 1 != numberOfPlayers)
		{
			printf(" or ");
		}
		if (i == numberOfPlayers)
		{
			printf("%d(for New Player)", i + 1);
		}
	}
	printf(":");
}

void NameArrangement(int PlayerNumber)//PLAYERMANAGER.H 
{
    //Capitalize the first letter
    players[PlayerNumber].name[0] = toupper((unsigned char)players[PlayerNumber].name[0]);
    //Convert the rest of the name to lowercase
    for (int i = 1; players[PlayerNumber].name[i] != '\0'; i++)
    {
        players[PlayerNumber].name[i] = tolower((unsigned char)players[PlayerNumber].name[i]);
    }
}

void VisualManager()
{
	clearConsole();
	PrintTitle();
	PrintScroll();
	MenuKeys();
	//Game tutorial
}
#endif