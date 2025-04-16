#ifndef VISUALS_H
#define VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Title.h"
#include "Timer.h"
#include "Menu.h"


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
		HoldSeconds(0.4);
	}
	for (int i = 3; i > 0; i--)
	{
		printf("%d...\n", i);
		HoldSeconds(1.0);
	}
	printf("Go!\n");
}

int PrintPlayerOptions(int numberOfPlayers)//PLAYERMANAGER.H
{
    int ch;
    int defaultOption = 0; 

    while (1)
    {
        clearConsole();
        printf("Choose a player\n\n");

        for (int i = 0; i < numberOfPlayers; i++)
        {
            if (i == defaultOption)
            {
                printf("  - %s -\n", players[i].name); 
            }
            else
            {
                printf("    %s\n", players[i].name);
            }
        }

        if (defaultOption == numberOfPlayers)
        {
            printf("\n  - New Player -\n");
        }
        else
        {
            printf("\n    New Player\n");
        }

        ch = _getch();
        if (ch == 0 || ch == 224) 
        {
            ch = _getch();

            switch (ch)
            {
            case 72: // Up arrow
                if (defaultOption > 0)
                {
                    defaultOption--;
                }
                else
                {
                    defaultOption = numberOfPlayers;
                }
                break;

            case 80: // Down arrow
                if (defaultOption < numberOfPlayers)
                {
                    defaultOption++;
                }
                else
                {
                    defaultOption = 0; 
                }
                break;
            }
        }
        else if (ch == 13) // Enter key
        {
			clearConsole();
            return defaultOption;
        }
    }
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

int VisualManager()
{
	clearConsole();
	PrintTitle();
	int DoNext = MenuDecision();
	return DoNext;
	//Game tutorial
}
#endif