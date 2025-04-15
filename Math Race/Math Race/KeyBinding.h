#ifndef KEYBINDING_H
#define KEYBINDING_H

#include <stdio.h>
#include <conio.h>
#include "MenuScroll.h"
#include "Visuals.h"


int MenuKeys()
{
    int ch;
    int defaultOption = 0;
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
                    //defaultOption = PrintMenuOnLeaderBoard();
                }
                else if (defaultOption == 2)
                {
                    //defaultOption = PrintMenuOnPlay();
                }
                break;
            case 80://Down arrow
                if (defaultOption == 1)
                {
                    //defaultOption = PrintMenuOnLeaderBoard();
                }
                else if (defaultOption == 2)
                {
                    //defaultOption = PrintMenuOnExit();
                }
                break;
            }
        }
        else if (ch == 13)
        {
            switch (defaultOption)
            {
            case 1://Play
                return 1;
                break;

            case 2://LeaderBoard
                return 1;
                break;

            case 3://Exit
                return 0;

            }
        }
    }
}
#endif
