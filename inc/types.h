#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include "ds.h"
#include "graphics.h"
#include "window.h"

typedef struct board *Board;
typedef struct coin *Coin;
typedef struct game *Game;
typedef struct hex *Hex;
typedef struct history *History;
typedef struct move *Move;
typedef struct moves *Moves;
typedef struct player *Player;
typedef struct supply *Supply;

typedef int (*DoMoveFunc)(Move move, Game game);
typedef Move (*GetMoveFunc)(Player player, Game game);
typedef int (*GenMoveFunc)(Coin coin, Game game, List move_space);

struct move {
	void *data;
	DoMoveFunc do_move;
};

extern FILE *out;
extern Win win;
extern Bitmap labels[9];

#define NUM_BITMAPS 35 
extern Bitmap bitmaps[NUM_BITMAPS];

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
#define NUM_START_COINS 2 //coins of each type in the bag 
#define NUM_CONTROL_COINS 6
#define NUM_CONTROL_COINS_BOARD 2
#define MOVE_SPACE_SIZE 200
#define MAX_MOVES 200 

//keys
#define GAMEBOX_SIZE 23
#define BOARD2 0
#define BOARD4 1
#define ARCHER 2
#define BESERKER 3
#define CAVALRY 4
#define CROSSBOWMAN 5
#define ENSIGN 6
#define FOOTMAN 7
#define KNIGHT 8
#define LANCER 9
#define LIGHT_CAVALRY 10
#define MARSHALL 11
#define MERCENARY 12
#define PIKEMAN 13
#define ROYAL_GUARD 14
#define SCOUT 15
#define SWORDSMAN 16
#define WARRIOR_PRIEST 17
#define GOLD_ROYAL_COIN 18
#define SILVER_ROYAL_COIN 19
#define GOLD_CONTROL_COIN 20
#define SILVER_CONTROL_COIN 21
#define INITIATIVE_COIN 22
#define RESOURCES {1,1,4,5,4,5,5,5,4,4,5,5,5,4,5,5,5,4,1,1,6,6,1}
#define BACK_COIN 23 
#define SUPPLY 24
#define BAG 25
#define HAND 26
#define DISCARD 27
#define REMOVED 28
#define TWO 29
#define THREE 30
#define FOUR 31
#define FIVE 32
#define HEX 33
#define HEX_CONTROL 34

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

//hex constants
#define NUM_HEXES 37 
#define NUM_ADJ_HEXES 6
#define BOUND 7
#define NO_HEX 0 

//player constants
#define MAX_STACKS 5
#define MAX_COINS_STACK 5
#define MAX_NUM_UNITS 21
#define MAX_TYPE_UNITS 5
#define MAX_COINS_HAND 3

//init data and bitmap paths
#define BOARD2_DATA "res/board.csv"
#define BOARD2_BITMAP "res/board.bmp"
#define HEX_BITMAP "res/hex.bmp"
#define CONTROL_HEX_BITMAP "res/control_hex.bmp"
#define ARCHER_BITMAP "res/archer_coin.bmp"
#define BESERKER_BITMAP "res/beserker_coin.bmp"
#define CAVALRY_BITMAP "res/cavalry_coin.bmp"
#define CROSSBOWMAN_BITMAP "res/crossbowman_coin.bmp"
#define ENSIGN_BITMAP "res/ensign_coin.bmp"
#define FOOTMAN_BITMAP "res/footman_coin.bmp"
#define KNIGHT_BITMAP "res/knight_coin.bmp"
#define LANCER_BITMAP "res/lancer_coin.bmp"
#define LIGHT_CAVALRY_BITMAP "res/light_cavalry_coin.bmp"
#define MARSHALL_BITMAP "res/marshall_coin.bmp"
#define MERCENARY_BITMAP "res/mercenary_coin.bmp"
#define PIKEMAN_BITMAP "res/pikeman_coin.bmp"
#define ROYAL_GUARD_BITMAP "res/royal_guard_coin.bmp"
#define SCOUT_BITMAP "res/scout_coin.bmp"
#define SWORDSMAN_BITMAP "res/swordsman_coin.bmp"
#define WARRIOR_PRIEST_BITMAP "res/warrior_priest_coin.bmp"
#define GOLD_ROYAL_COIN_BITMAP "res/gold_royal_coin.bmp"
#define SILVER_ROYAL_COIN_BITMAP "res/silver_royal_coin.bmp"
#define GOLD_CONTROL_COIN_BITMAP "res/gold_control_coin.bmp"
#define SILVER_CONTROL_COIN_BITMAP "res/silver_control_coin.bmp"
#define INITIATIVE_COIN_BITMAP "res/initiative_coin.bmp"
#define BACK_BITMAP "res/coin_back.bmp"
#define SUPPLY_BITMAP "res/supply.bmp"
#define BAG_BITMAP "res/bag.bmp"
#define HAND_BITMAP "res/hand.bmp"
#define DISCARD_BITMAP "res/discard.bmp"
#define REMOVED_BITMAP "res/removed.bmp"
#define TWO_BITMAP "res/two.bmp"
#define THREE_BITMAP "res/three.bmp"
#define FOUR_BITMAP "res/four.bmp"
#define FIVE_BITMAP "res/five.bmp"

/*#define DRAW 10*/
/*#define SELECT 11*/
/*#define REMOVE 12*/
/*#define MANEUVER 13*/
/*#define ENSIGN_MOVE 14*/

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
