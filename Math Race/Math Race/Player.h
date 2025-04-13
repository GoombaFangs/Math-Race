#ifndef PLAYER_H
#define PLAYER_H

#define MAX_PLAYERS 15 

typedef struct player 
{
	int playerNumber;
	char name[50];
	double score;
} Player;

extern Player players[MAX_PLAYERS];

#endif

