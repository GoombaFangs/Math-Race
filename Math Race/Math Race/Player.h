#ifndef PLAYER_H
#define PLAYER_H

#define MAX_PLAYERS 15 

typedef struct player 
{
	int playerNumber;
	char name[20];
	double score;
	int place;
} Player;

extern Player players[MAX_PLAYERS];
#endif

