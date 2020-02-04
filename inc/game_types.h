#ifndef GAME_TYPES_H
#define GAME_TYPES_H

#define MAX_NUM_UNITS 21
#define MAX_TYPE_UNITS 5
#define MAX_HAND 3

#define NUM_PLAYERS 2

#define HUMAN 0
#define COMPUTER 1

#define FIRST 0
#define RANDOM 1
#define SNAKE 2
#define GOLD_PLAYER_FIRST_UNITS 18 //includes the royal coin
#define SILVER_PLAYER_FIRST_UNITS 20 //includes the royal coin 

//Hex occupiers, i.e. coins
#define SILVER (-2)
#define GOLD (-1)
#define EMPTY 0
#define ARCHER 1
#define BESERKER 2
#define CAVALRY 3
#define CROSSBOWMAN 4
#define ENSIGN 5
#define FOOTMAN 6
#define KNIGHT 7
#define LANCER 8
#define LIGHT_CAVALRY 9
#define MARSHALL 10
#define MERCENARY 11
#define PIKEMAN 12
#define ROYAL_GUARD 13
#define SCOUT 14
#define SWORDSMAN 15
#define WARRIOR_PRIEST 16

//Hex constants
#define NUM_HEXES 37 
#define BOUND 7
#define NUM_ADJ_HEXES 6
#define NO_HEX (-1)

//History constants
#define MAX_MOVES 300 

//Move types
#define DEPLOY 1
#define BOLSTER 2
#define INITIATIVE 3
#define RECRUIT 4
#define PASS 5
#define MOVE 6
#define CONTROL 7
#define ATTACK 8
#define TACTIC 9

//Unit side
#define UP 0
#define DOWN 1

typedef struct game Game;
typedef struct board Board;
typedef struct hex Hex;
typedef struct player Player;
typedef struct move Move;
typedef struct turn Turn;
typedef struct round Round;
typedef struct history History;
typedef struct discard Discard;
typedef struct unit Unit;

struct hex {
	int id;
	int num_adj;
	int adj[NUM_ADJ_HEXES];
	int control_space;
	int control_marker;
	int num_units;
	int unit;
};

struct board {
	Hex hexes[NUM_HEXES];
};

struct unit {
	int type;
	int num;
};

struct discard {
	int unit;
	int face;
};

struct player {
	int color;
	int control_coin;
	int num_units;
	Unit units[MAX_TYPE_UNITS];
	int num_supply;
	int supply[MAX_NUM_UNITS];
	int num_bag;
	int bag[MAX_NUM_UNITS];
	int num_hand;
	int hand[MAX_HAND];
	int num_discarded;
	Discard discarded[MAX_NUM_UNITS];
	int num_removed;
	int removed[MAX_NUM_UNITS];
};

struct move {
	int player;
	int type;
	int type2; //depends on move, e.g. cavalry tactic is move->attack
	int unit; //unit coin played
	int unit2; //depends on move, e.g. recruit, attack, etc.
	int from_hex;
	int to_hex;
};

//Stores changes to the board
struct history {
	int num_moves;
	Move Moves[MAX_MOVES];
};

struct game {
	int cur_player;
	Board board;
	Player players[NUM_PLAYERS];
	History history;
};

#endif //GAME_TYPES_H
