#ifndef KEYBINDING_H
#define KEYBINDING_H

#include <stdio.h>
#include <conio.h>
#include "MenuScroll.h"
#include "Visuals.h"

void CloseScroll();
int PrintMenuOnPlay();
int PrintMenuOnLeaderBoard();
int PrintMenuOnExit();

int MenuKeys()
{
    int ch;
    int defaultOption = PrintMenuOnPlay();
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
                    defaultOption = PrintMenuOnLeaderBoard();
                }
                else if (defaultOption == 2)
                {
                    defaultOption = PrintMenuOnPlay();
                }
                break;
            case 80://Down arrow
                if (defaultOption == 1)
                {
                    defaultOption = PrintMenuOnLeaderBoard();
                }
                else if (defaultOption == 2)
                {
                    defaultOption = PrintMenuOnExit();
                }
                break;
            }
        }
        else if (ch == 13)
        {
            switch (defaultOption)
            {
            case 1://Play
                CloseScroll();
                return 1;
                break;

            case 2://LeaderBoard
                CloseScroll();
                return 1;
                break;

            case 3://Exit
                CloseScroll();
                return 0;

            }
        }
    }
}
#endif
