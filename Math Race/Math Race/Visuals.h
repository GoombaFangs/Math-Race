#ifndef VISUALS_H
#define VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Player.h"
#include "Title.h"

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void VisualManager()
{
	clearConsole();
	PrintTitle();
    //Main Menu
    //Game tutorial
}


void NameArrangement(int PlayerNumber) 
{
    // Capitalize the first letter
    players[PlayerNumber].name[0] = toupper((unsigned char)players[PlayerNumber].name[0]);
    // Convert the rest of the name to lowercase
    for (int i = 1; players[PlayerNumber].name[i] != '\0'; i++)
    {
        players[PlayerNumber].name[i] = tolower((unsigned char)players[PlayerNumber].name[i]);
    }

}

#endif