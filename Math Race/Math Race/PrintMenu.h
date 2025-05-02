#ifndef PRINTMENU_H
#define PRINTMENU_H

#include <stdio.h>
#include "Visuals.h"

void printg(double duration, const char* format, ...);

int OnStart();
int OnPlay();
int OnLeaderBoard();
int OnExit();
#endif