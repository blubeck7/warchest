#ifndef TYPES_H
#define TYPES_H

#include "ds.h"

typedef struct board *Board;
typedef struct coin *Coin;
typedef struct game *Game;
typedef struct hex *Hex;
typedef struct history *History;
typedef struct move *Move;
typedef struct player *Player;
typedef Move (*GetMoveFunc)(Player player, Game game);
typedef int (*GenMoveFunc)(Coin coin, Game game, List move_space);

#define NUM_PLAYERS 2
#define GOLD_PLAYER 0
#define SILVER_PLAYER 1
#define FIRST_GAME 0
#define RANDOM_GAME 1
#define SNAKE_GAME 2
#define GOLD_PLAYER_FIRST_UNITS 18 //includes the royal coin
#define SILVER_PLAYER_FIRST_UNITS 20 //includes the royal coin 
#define GOLD_PLAYER_FIRST_TYPES 5 //includes the royal coin
#define SILVER_PLAYER_FIRST_TYPES 5 //includes the royal coin 
#define NUM_CONTROL_MARKERS 6
#define MOVE_SPACE_SIZE 200

#define MAX_COINS 2
#define NONE 0
#define DEPLOY 1
#define BOLSTER 2
#define INITIATIVE 3
#define RECRUIT 4
#define PASS 5
#define MOVE 6
#define CONTROL 7
#define ATTACK 8
#define TACTIC 9

#define COIN_DOWN 0
#define COIN_UP 1

#define NUM_ADJ_HEXES 6

#define MAX_NUM_STACKS 5
#define MAX_NUM_UNITS 21
#define MAX_TYPE_UNITS 5
#define MAX_HAND 3

/*#define DRAW 10*/
/*#define SELECT 11*/
/*#define REMOVE 12*/
/*#define MANEUVER 13*/
/*#define ENSIGN_MOVE 14*/

//Player constants
//#define MAX_NUM_UNITS 21
//#define MAX_TYPE_UNITS 5
//#define MAX_HAND 3

//#define NUM_PLAYERS 2

//#define HUMAN 0
//#define COMPUTER 1

//#define FIRST 0
//#define RANDOM 1
//#define SNAKE 2
//#define GOLD_PLAYER_FIRST_UNITS 18 //includes the royal coin
//#define SILVER_PLAYER_FIRST_UNITS 20 //includes the royal coin 
//#define GOLD_PLAYER_FIRST_TYPES 5 //includes the royal coin
//#define SILVER_PLAYER_FIRST_TYPES 5 //includes the royal coin 
//#define NUM_CONTROL_MARKERS 6
//#define MOVE_SPACE 200

////Hex occupiers, i.e. coins
//#define SILVER (-2)
//#define GOLD (-1)
//#define EMPTY 0
//#define ARCHER 1
//#define BESERKER 2
//#define CAVALRY 3
//#define CROSSBOWMAN 4
//#define ENSIGN 5
//#define FOOTMAN 6
//#define KNIGHT 7
//#define LANCER 8
//#define LIGHT_CAVALRY 9
//#define MARSHALL 10
//#define MERCENARY 11
//#define PIKEMAN 12
//#define ROYAL_GUARD 13
//#define SCOUT 14
//#define SWORDSMAN 15
//#define WARRIOR_PRIEST 16

////Hex constants
//#define NUM_HEXES 37 
//#define BOUND 7
//#define NUM_ADJ_HEXES 6
//#define NO_HEX (-1)

////History constants
//#define MAX_MOVES 300 

////Move types
//#define DEPLOY 1
//#define BOLSTER 2
//#define INITIATIVE 3
//#define RECRUIT 4
//#define PASS 5
//#define MOVE 6
//#define CONTROL 7
//#define ATTACK 8
//#define TACTIC 9
//#define DRAW 10
//#define SELECT 11

////Unit side
//#define UP 0
//#define DOWN 1

//typedef struct game Game;
//typedef struct board Board;
//typedef struct hex Hex;
//typedef struct player Player;
//typedef struct move Move;
//typedef struct turn Turn;
//typedef struct round Round;
//typedef struct history History;
//typedef struct discard Discard;
//typedef struct unit Unit;
//typedef struct deployed Deployed;
//typedef Move (*GetMoveFunc)(Game *game_ptr, int n);

//typedef int (*MoveFunc)(Game *game, Move *move);

//struct deployed {
	//int n;
//};

//struct hex {
	//int id;
	//int num_adj;
	//int adj[NUM_ADJ_HEXES];
	//int control_space;
	//int control_marker;
	//int num_units;
	//int unit;
//};

//struct board {
	//Hex hexes[NUM_HEXES];
//};

//struct unit {
	//int type;
	//int num;
//};

//struct discard {
	//int type;
	//int face;
//};

//struct player {
	//char *name;
	//int color;
	//int control_coin;
	//int control_markers;
	//int num_types;
	//Unit units[MAX_TYPE_UNITS];
	//int num_supply;
	//int supply[MAX_NUM_UNITS];
	//int num_bag;
	//int bag[MAX_NUM_UNITS];
	//int num_hand;
	//int hand[MAX_HAND];
	//int num_deployed;
	//Deployed deployed[MAX_NUM_UNITS]; 
	//int num_discarded;
	//Discard discarded[MAX_NUM_UNITS];
	//int num_removed;
	//int removed[MAX_NUM_UNITS];
	//GetMoveFunc get_move;
//};

//struct move {
	//int player;
	//int type;
	//int unit;
	//int from_hex;
	//int to_hex;
//};

////Stores changes to the board
//struct history {
	//Unit *units[NUM_PLAYERS][MAX_TYPE_UNITS];
	//int num_moves;
	//Move moves[MAX_MOVES];
//};

//struct game {
	//int cur_player;
	//int resolve; [> whether a played coin has follow up actions to handle <]
	//Board board;
	//Player players[NUM_PLAYERS];
	//History history;
//};

#endif //TYPES_H
