#ifndef SAVELOADDATA_H
#define SAVELOADDATA_H

#include <stdio.h>
#include <stdbool.h>
#include "ScoreCalculator.h"
#include "Player.h"
#include "PlayerManager.h"
#include "Visuals.h"

#ifndef _countof
#define _countof(array) (sizeof(array) / sizeof(array[0]))
#endif

Player players[MAX_PLAYERS];

void SaveNumberOfPlayers(int numberOfPlayers);
int LoadNumberOfPlayers(int numberOfPlayers);
void SavePlayers(int numberOfPlayers);
void LoadPlayers(int numberOfPlayers);
#endif