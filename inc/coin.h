#ifndef COIN_H
#define COIN_H

#include <stdio.h>
#include "graphics.h"
#include "types.h"
#include "window.h"

#define COIN_DOWN 0
#define COIN_UP 1
#define MAX_COINS_STACK 5

#define ARCHER 0
#define BESERKER 1
#define CAVALRY 2
#define CROSSBOWMAN 3
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

typedef struct coin_data {
	int type;
	int face;
	Bitmap *front;
	Bitmap *back;
	Win *win;
	Pos pos;
	char *txt;
	FILE *term;
} CoinData;

struct coin {
	CoinData data;
	// int (*gen_deploy_moves)(Coin coin, Game game, Moves moves);
	// int (*gen_bolster_moves)(Coin coin, Game game, Moves moves);
	// int (*gen_claim_moves)(Coin coin, Game game, Moves moves);
	// int (*gen_recruit_moves)(Coin coin, Game game, Moves moves);
	// int (*gen_pass_moves)(Coin coin, Game game, Moves moves);
	// int (*gen_move_moves)(Coin coin, Game game, Moves moves);
	// int (*gen_control_moves)(Coin coin, Game game, Moves moves);
	// int (*gen_attack_moves)(Coin coin, Game game, Moves moves);
	// int (*gen_tactic_moves)(Coin coin, Game game, Moves moves); 
};

struct coin_stack {
	int num_coins;
	Coin coins[MAX_COINS_STACK];
	Bitmap *nums;
	Win *win;
	Pos pos;
};

struct coin_box {
	int num_stacks;			
};

int set_face_up_coin(Coin coin);
int set_face_down_coin(Coin coin);
int set_front_coin(Coin coin, Bitmap *front);
int set_back_coin(Coin coin, Bitmap *back);
int set_win_coin(Coin coin, Win *win);
int set_pos_coin(Coin coin, Pos *pos);
int set_txt_coin(Coin coin, char *txt);
int set_term_coin(Coin coin, FILE *term);
int display_coin(Coin coin);
int print_coin(Coin coin);
int init_coin(Coin coin, int face, Bitmap *front, Bitmap *back, Win *win,
	Pos *pos, char *txt, FILE *term);
Coin create_archer_coin(void);
Coin create_cavalry_coin(void);
Coin create_crossbowman_coin(void);
Coin create_lancer_coin(void);
Coin create_light_cavalry_coin(void);
Coin create_pikeman_coin(void);
Coin create_scout_coin(void);
Coin create_swordsman_coin(void);

CoinStack create_coin_stack(void);
int init_coin_stack(CoinStack coin_stack, Bitmap *nums, Win *win, Pos *pos);
int add_coin_stack(CoinStack coin_stack, Coin coin);
Coin remove_coin_stack(CoinStack coin_stack);
int display_coin_stack(CoinStack coin_stack);

CoinBox create_coin_box(void);
int init_coin_box(CoinBox coin_box, Win *win, Pos *pos);



/* #include "ds.h"
#include "game.h"
#include "types.h"

struct coin {
	int type;
	int face; //up or down
	Hex hex;
	Player owner;
	int (*deploy)(Coin coin, Game game, List move_space);
	GenMoveFunc bolster;
	GenMoveFunc claim;
	GenMoveFunc recruit;
	GenMoveFunc pass;
	GenMoveFunc move;
	GenMoveFunc control;
	GenMoveFunc attack;
	GenMoveFunc tactic;
	Pos pos;
	int display_ind;
	int (*display)(Coin coin);
};

Coin create_archer_coin(void);
Coin create_beserker_coin(void);
Coin create_cavalry_coin(void);
Coin create_crossbowman_coin(void);
Coin create_ensign_coin(void);
Coin create_footman_coin(void);
Coin create_knight_coin(void);
Coin create_lancer_coin(void);
Coin create_light_cavalry_coin(void);
Coin create_marshall_coin(void);
Coin create_mercenary_coin(void);
Coin create_pikeman_coin(void);
Coin create_royal_guard_coin(void);
Coin create_scout_coin(void);
Coin create_swordsman_coin(void);
Coin create_warrior_priest_coin(void);
Coin create_gold_royal_coin(void);
Coin create_silver_royal_coin(void);
Coin create_gold_control_coin(void);
Coin create_silver_control_coin(void);
Coin create_initiative_coin(void);
int destroy_coin(Coin coin);
int display_coin(Coin coin);
int toggle_display_coin(Coin coin);
int print_coin(Coin coin);
int print_coin_all(Coin coin);
int set_face_down_coin(Coin coin);
int set_face_up_coin(Coin coin);
int set_coin_pos(Coin coin, Pos pos);
int gen_moves_coin(Coin coin, Game game, List move_space);
int same_type_coin(Coin coin1, Coin coin2); */

#endif //COIN_H
