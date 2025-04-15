#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <conio.h>
#include "Visuals.h"
#include "PrintMenu.h"

int OnPlay();
int OnLeaderBoard();
int OnExit();


int MenuDecision()
{
    int ch;
    int defaultOption = OnPlay();
    while (1) 
    {
        ch = _getch();
        if (ch == 0 || ch == 224)
        {
            ch = _getch();

            switch (ch) 
            {
            case 72://Up arrow
                if (defaultOption == 3)
                {
                    defaultOption = OnLeaderBoard();
                }
                else if (defaultOption == 2)
                {
                    defaultOption =  OnPlay();
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
        else if (ch == 13)
        {
            switch (defaultOption)
            {
            case 1://Play
                clearConsole();
                return 1;
                break;

            case 2://LeaderBoard
                clearConsole();
                return 1;
                break;

            case 3://Exit
                clearConsole();
                return 0;

            }
        }
    }
}
#endif
