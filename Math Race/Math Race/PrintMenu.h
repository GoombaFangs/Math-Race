#ifndef PRINTMENU_H
#define PRINTMENU_H

#include <stdio.h>
#include "Visuals.h"

void printg(double duration, const char* format, ...);

int OnStart()
{
	clearConsole();
	printg(0.035, "  Press an Up or Down arrow and Enter to confirm :\n");
	HoldSeconds(0.2);
    printf("                                                                                                         \n");
    printf("                 _________                                                                               \n");
    printf("                |  Play!  |                                                                              \n");
    printf("                 ---------                                                                               \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                   Leader Board                                                                          \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                   Exit                                                                                  \n");
    printf("                                                                                                         \n");
	return 1;
}
int OnPlay()
{
	clearConsole();
    printf("  Press an Up or Down arrow and Enter to confirm :                                                       \n");
    printf("                                                                                                         \n");
    printf("                 _________                                                                               \n");
    printf("                |  Play!  |                                                                              \n");
    printf("                 ---------                                                                               \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                   Leader Board                                                                          \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                   Exit                                                                                  \n");
    printf("                                                                                                         \n");
	return 1;
}
int OnLeaderBoard()
{
	clearConsole();
    printf("  Press an Up or Down arrow and Enter to confirm :                                                       \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                   Play!                                                                                 \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                  _______________                                                                        \n");
    printf("                 | Leader Board  |                                                                       \n");
    printf("                  ---------------                                                                        \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                   Exit                                                                                  \n");
    printf("                                                                                                         \n");
    return 2;
}
int OnExit()
{
    clearConsole();
    printf("  Press an Up or Down arrow and Enter to confirm :                                                       \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                   Play!                                                                                 \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                   Leader Board                                                                          \n");
    printf("                                                                                                         \n");
    printf("                                                                                                         \n");
    printf("                  _______                                                                                \n");
    printf("                 | exit  |                                                                               \n");
    printf("                  -------                                                                                \n");
    return 3;
}

#endif