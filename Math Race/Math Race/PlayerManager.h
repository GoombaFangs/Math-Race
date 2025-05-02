#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <stdio.h>
#include <stdbool.h>
#include "ScoreCalculator.h"
#include "Player.h"
#include "SaveLoadData.h"
#include "Visuals.h"

Player NewPlayer(int numberOfPlayers);
void UpdatePlayerScore(Player player, int numberOfPlayers);
Player ChooseAPlayer(int numberOfPlayers);
int GetNumberOfPlayers();
Player PlayerManager(int decision);
#endif

