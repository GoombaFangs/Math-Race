#ifndef VISUALS_H
#define VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
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

void printg(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    char buffer[256]; // Temporary buffer to store the formatted string
    vsnprintf(buffer, sizeof(buffer), format, args); // Format the string
    va_end(args);

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        printf("%c", buffer[i]);
        HoldSeconds(0.004);//0.030
    }
}
void PrintRound(int round)
{
    double durition = 0.005;
    if (round == 1)
    {
        clearConsole();
        printf(" _____                       _      \n");
        printf("|  __ \\                     | |     \n");
        printf("| |__) |___  _   _ _ __   __| |     \n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |     \n");
        printf("| | \\ \\ (_) | |_| | | | | (_| |     \n");
        printf("|_|  \\_\\___/ \\__,_|_| |_|\\__,_|  \n");
        HoldSeconds(0.4);
        clearConsole();
        printf(" _____                       _   |_|\n");
        printf("|  __ \\                     | |     \n");
        printf("| |__) |___  _   _ _ __   __| |     \n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |     \n");
        printf("| | \\ \\ (_) | |_| | | | | (_| |     \n");
        printf("|_|  \\_\\___/ \\__,_|_| |_|\\__,_|  \n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _   | |\n");
        printf("|  __ \\                     | |  |_|\n");
        printf("| |__) |___  _   _ _ __   __| |     \n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |     \n");
        printf("| | \\ \\ (_) | |_| | | | | (_| |     \n");
        printf("|_|  \\_\\___/ \\__,_|_| |_|\\__,_|  \n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _   | |\n");
        printf("|  __ \\                     | |  | |\n");
        printf("| |__) |___  _   _ _ __   __| |  |_|\n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |     \n");
        printf("| | \\ \\ (_) | |_| | | | | (_| |     \n");
        printf("|_|  \\_\\___/ \\__,_|_| |_|\\__,_|  \n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _   | |\n");
        printf("|  __ \\                     | |  | |\n");
        printf("| |__) |___  _   _ _ __   __| |  | |\n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |  |_|\n");
        printf("| | \\ \\ (_) | |_| | | | | (_| |     \n");
        printf("|_|  \\_\\___/ \\__,_|_| |_|\\__,_|  \n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _  /_ |\n");
        printf("|  __ \\                     | |  | |\n");
        printf("| |__) |___  _   _ _ __   __| |  | |\n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |  | |\n");
        printf("| | \\ \\ (_) | |_| | | | | (_| |  |_|\n");
        printf("|_|  \\_\\___/ \\__,_|_| |_|\\__,_|  \n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _   __ \n");
        printf("|  __ \\                     | | /_ |\n");
        printf("| |__) |___  _   _ _ __   __| |  | |\n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |  | |\n");
        printf("| | \\ \\ (_) | |_| | | | | (_| |  | |\n");
        printf("|_|  \\_\\___/ \\__,_|_| |_|\\__,_|  |_|\n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _   __ \n");
        printf("|  __ \\                     | | /_ |\n");
        printf("| |__) |___  _   _ _ __   __| |  | |\n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |  | |\n");
        printf("| | \\ \\ (_) | |_| | | | | (_| |  | |\n");
        printf("|_|  \\_\\___/ \\__,_|_| |_|\\__,_|  |_|\n");
        HoldSeconds(1.5);////
        clearConsole();
        printf(" _____                       _   __ \n");
        printf("|  __ \\                     | | /_ |\n");
        printf("| |__) |___  _   _ _ __   __| |  | |\n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |  | |\n");
        printf("| | \\ \\ (_) | |_| | | | | (_| |  | |\n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _   __ \n");
        printf("|  __ \\                     | | /_ |\n");
        printf("| |__) |___  _   _ _ __   __| |  | |\n");
        printf("|  _  // _ \\| | | | '_ \\ / _` |  | |\n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _   __ \n");
        printf("|  __ \\                     | | /_ |\n");
        printf("| |__) |___  _   _ _ __   __| |  | |\n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _   __ \n");
        printf("|  __ \\                     | | /_ |\n");
        HoldSeconds(durition);
        clearConsole();
        printf(" _____                       _   __ \n");
        HoldSeconds(durition);
    }		
}

void GetReadyForNextRound(int round)//ROUNDS.H
{
	if (round == 0)
	{
        clearConsole();
        printg("Get ready!\n\n");
        HoldSeconds(0.4);
	}
    else
    {
        clearConsole();
        HoldSeconds(0.4);
    }
	for (int i = 3; i > 0; i--)
	{
        printg("%d...\n", i);
		HoldSeconds(1.0);
	}
    printg("\nGo!\n");
    HoldSeconds(0.1);
}

int PrintPlayerOptions(int numberOfPlayers)//PLAYERMANAGER.H
{
    int ch;
    int defaultOption = 0; 

    printg("Choose a player\n\n");
    for (int i = 0; i < numberOfPlayers; i++)
    {
        if (i == defaultOption)
        {
            printg("  - %s -\n", players[i].name);
        }
        else
        {
            printg("    %s\n", players[i].name);
        }
    }

    if (defaultOption == numberOfPlayers)
    {
        printg("\n  - New Player -\n");
    }
    else
    {
        printg("\n    New Player\n");
    }

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