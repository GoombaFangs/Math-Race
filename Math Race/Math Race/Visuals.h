#ifndef VISUALS_H
#define VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Player.h"


void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void PrintTitle()
{
    HoldSceonds(0.2);
    printf("    _       _\n");
    printf("   | |     / /\n");
    printf("   | | /| / / _ \\/ \n");
    printf("   | |/ |/ / \n");
    printf("   |__/|__/\\___/_/\\_\n");
    HoldSceonds(0.006);
    clearConsole();
    printf("    _       __     __               \n");
    printf("   | |     / /__  / /________  ____ _\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / /\n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\_\n");
    HoldSceonds(0.006);
    clearConsole();
    printf("    _       __     __                             __\n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ _\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/\n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\___\n");
    HoldSceonds(0.006);
    clearConsole();
    printf("    _       __     __                             __           __\n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_____     /  |\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  \n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\n");
    HoldSceonds(0.006);
    clearConsole();
    printf("    _       __     __                             __           __  ___      _\n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_____     /  |/  /___ _/ /\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/ / __ `/ __/\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  / / /_/ / /_\n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\__,_/\\__/_\n");
    HoldSceonds(0.006);
    clearConsole();
    printf("    _       __     __                             __           __  ___      __  __      \n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_____     /  |/  /___ _/ /_/ /_     /\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/ / __ `/ __/ __ \\   / \n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  / / /_/ / /_/ / / /  / \n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\__,_/\\__/_/ /_/  /_/ \n");
    HoldSceonds(0.006);
    clearConsole();
    printf("    _       __     __                             __           __  ___      __  __       ____     \n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_____     /  |/  /___ _/ /_/ /_     / __ \\____\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/ / __ `/ __/ __ \\   / /_/ / __ `\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  / / /_/ / /_/ / / /  / _, _/ /_/ \n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\__,_/\\__/_/ /_/  /_/ |_|\\__,_/\n");
    HoldSceonds(0.006);
	clearConsole();
    printf("    _       __     __                             __           __  ___      __  __       ____                  __     \n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_____     /  |/  /___ _/ /_/ /_     / __ \\____ _________  / /     \n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/ / __ `/ __/ __ \\   / /_/ / __ `/ ___/ _ \\/ /      \n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  / / /_/ / /_/ / / /  / _, _/ /_/ / /__/  __/_/       \n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\__,_/\\__/_/ /_/  /_/ |_|\\__,_/\\___/\\___(_)        \n");
    HoldSceonds(1.5);
    clearConsole();
    ////////////////////////////////////////////////////////////////////////////////////////////////
    printf("    _       __     __                             __           __  ___      __  __       ____     \n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_____     /  |/  /___ _/ /_/ /_     / __ \\____\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/ / __ `/ __/ __ \\   / /_/ / __ `\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  / / /_/ / /_/ / / /  / _, _/ /_/ \n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\__,_/\\__/_/ /_/  /_/ |_|\\__,_/\n");
    HoldSceonds(0.05);
    clearConsole();
    printf("    _       __     __                             __           __  ___      __  __      \n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_____     /  |/  /___ _/ /_/ /_     /\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/ / __ `/ __/ __ \\   / \n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  / / /_/ / /_/ / / /  / \n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\__,_/\\__/_/ /_/  /_/ \n");
    HoldSceonds(0.03);
    clearConsole();
    printf("    _       __     __                             __           __  ___      _\n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_____     /  |/  /___ _/ /\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/ / __ `/ __/\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  / / /_/ / /_\n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\__,_/\\__/_\n");
    HoldSceonds(0.02);
    clearConsole();
    printf("    _       __     __                             __           __\n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_____     /  |\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\   / /|_/\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /  / /  \n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\____/  /_/  /_/\\n");
    HoldSceonds(0.01);
    clearConsole();
    printf("    _       __     __                             __\n");
    printf("   | |     / /__  / /________  ____ ___  ___     / /_\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ _\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/\n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\___/   \\__/\\___\n");
    HoldSceonds(0.01);
    clearConsole();
    printf("    _       __     __               \n");
    printf("   | |     / /__  / /________  ____ _\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / /\n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\_\n");
    HoldSceonds(0.01);
    clearConsole();
    printf("    _       __     __               \n");
    printf("   | |     / /__  / /________  ____ _\n");
    printf("   | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\\n");
    printf("   | |/ |/ /  __/ / /__/ /_/ / / / /\n");
    printf("   |__/|__/\\___/_/\\____/\\___/_/ /_/ /_/\\_\n");
    HoldSceonds(0.02);
    clearConsole();
    printf("    _       _\n");
    printf("   | |     / /\n");
    printf("   | | /| / / _ \\/ \n");
    printf("   | |/ |/ / \n");
    printf("   |__/|__/\\___/_/\\_\n");
    HoldSceonds(0.03);
    clearConsole();
    HoldSceonds(0.5);
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