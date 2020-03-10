#ifndef COIN_H
#define COIN_H

#include "ds.h"
#include "game.h"
#include "types.h"

struct coin {
	Player owner;
	int type;
	Hex hex;
	int face; //up or down
	Bitmap front;
	Bitmap back;
	Pos pos;
	int (*deploy)(Coin coin, Game game, List move_space);
	GenMoveFunc bolster;
	GenMoveFunc claim;
	GenMoveFunc recruit;
	GenMoveFunc pass;
	GenMoveFunc move;
	GenMoveFunc control;
	GenMoveFunc attack;
	GenMoveFunc tactic;
	int display_ind;
	int (*display)(Coin coin);
};

Coin create_coin(int type, GenMoveFunc movefuncs[9]);
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
int same_type_coin(Coin coin1, Coin coin2);


#endif //COIN_H
