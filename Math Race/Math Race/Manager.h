#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "PlayerManager.h"
#include "Rounds.h"
#include "Timer.h"
#include "ScoreCalculator.h"
#include "Visuals.h"
#include "PrintMenu.h"


int Menu()
{
    int keyboardInput;
    int defaultOption = OnStart();
    while (1)
    {
        keyboardInput = _getch();
        if (keyboardInput == 0 || keyboardInput == 224)
        {
            keyboardInput = _getch();

            switch (keyboardInput)
            {
            case 72://Up arrow
                if (defaultOption == 3)
                {
                    defaultOption = OnLeaderBoard();
                }
                else if (defaultOption == 2)
                {
                    defaultOption = OnPlay();
                }
                break;
            case 80://Down arrow
                if (defaultOption == 1)
                {
                    defaultOption = OnLeaderBoard();
                }
                else if (defaultOption == 2)
                {
                    defaultOption = OnExit();
                }
                break;
            }
        }
        else if (keyboardInput == 13)
        {
            switch (defaultOption)
            {
            case 1://Play
                clearConsole();
                return 1;
                break;

            case 2://LeaderBoard
                clearConsole();
                return 2;
                break;

            case 3://Exit
                clearConsole();
                return 3;

            }
        }
    }
}
void EndSceen()
{
	HoldSeconds(0.5);
    printg(0.045, "Thanks for playing!\n");
	HoldSeconds(0.5);
	printg(0.045, "Press any key to continue...");
    _getch();
}

void AppStart()
{
	srand((unsigned int)time(NULL));
	VisualManager();
	int theGameIsRunning = 1;
	int DoNext = Menu();	
	Player currentPlayer;
	while (theGameIsRunning != 0)
	{
		switch (DoNext)
		{
		case 1:// Play
            currentPlayer = PlayerManager(DoNext);
			PlayTheGame();//ROUNDS.H
			UpdatePlayerScore(currentPlayer, GetNumberOfPlayers());//PLAYERMANAGER.H
            EndSceen();
			DoNext = Menu();
			break;

		case 2:// Leaderboad
            PlayerManager(2);
            printLeaderboard(GetNumberOfPlayers());
            EndSceen();
			DoNext = Menu();
            break;

        case 3:// Exit
            theGameIsRunning = 0;
            break;

		default:
			break;
		}
	}
}
#endif


