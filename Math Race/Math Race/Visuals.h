#ifndef VISUALS_H
#define VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <conio.h> 
#include "Title.h"
#include "Timer.h"
#include "PrintRounds.h"
#include "PlayerManager.h"

void clearConsole();
void printg(double duration, const char* format, ...);
void PrintRounds(int round);
void GetReadyForNextRound(int round);
int PrintPlayerOptions(int numberOfPlayers);
void NameArrangement(int PlayerNumber);
void printLeaderboard(int numberOfPlayers);
void VisualManager();
#endif