#ifndef GAME_TYPES_H
#define GAME_TYPES_H

#include "graphics.h"

#define MAX_NUM_UNITS 21
#define MAX_TYPE_UNITS 5
#define MAX_HAND 3

#define NUM_PLAYERS 2

#define HUMAN 0
#define COMPUTER 1

#define FIRST 0
#define RANDOM 1
#define SNAKE 2
#define FIRST_PLAYER_1_UNITS 18 //includes hte royal coin
#define FIRST_PLAYER_2_UNITS 20 

#define SILVER_COIN (-2)
#define GOLD_COIN (-1)
#define ARCHER 0
#define BESERKER 1
#define CAVALRY 2
#define CROSSBOW 3
#define ENSIGN 4
#define FOOTMAN 5
#define KNIGHT 6
#define LANCER 7
#define LIGHT_CAVALRY 8
#define MARSHALL 9
#define MERCENARY 10
#define PIKEMAN 11
#define ROYAL_GUARD 12
#define SCOUT 13
#define SWORDSMAN 14
#define WARRIOR_PRIEST 15

typedef struct player Player;
typedef struct unit Unit;

struct unit {
	int type;
	int num;
	char *name;
	Bitmap *card;
	Bitmap *coin;
};

struct player {
	int num_units;
	Unit units[MAX_TYPE_UNITS];
	int num_bag;
	Unit *bag[MAX_NUM_UNITS];
	int num_hand;
	Unit *hand[MAX_HAND];
	int num_supply;
	Unit *supply[MAX_NUM_UNITS];
	int num_removed;
	Unit *removed[MAX_NUM_UNITS];
};


#endif //GAME_TYPES_H
