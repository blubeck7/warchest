#ifndef COIN_H
#define COIN_H

#include "types.h"

#define DOWN 0
#define UP 1

typedef struct coin_data {
	int face;
	Bitmap *front;
	Bitmap *back;	
	Win *win;
	Pos pos;
} CoinData;

struct coin {
	CoinData data;
	int (*gen_deploy_moves)(Coin coin, Game game, Moves moves);
	int (*gen_bolster_moves)(Coin coin, Game game, Moves moves);
	int (*gen_claim_moves)(Coin coin, Game game, Moves moves);
	int (*gen_recruit_moves)(Coin coin, Game game, Moves moves);
	int (*gen_pass_moves)(Coin coin, Game game, Moves moves);
	int (*gen_move_moves)(Coin coin, Game game, Moves moves);
	int (*gen_control_moves)(Coin coin, Game game, Moves moves);
	int (*gen_attack_moves)(Coin coin, Game game, Moves moves);
	int (*gen_tactic_moves)(Coin coin, Game game, Moves moves); 
};

int display_coin(Coin coin);
int set_face_up_coin(Coin coin);
int set_face_down_coin(Coin coin);
int set_pos_coin(Coin coin, Pos pos);
int print_coin(Coin coin);

Coin create_archer_coin(Bitmap *front, Bitmap *back, Win *win);
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
