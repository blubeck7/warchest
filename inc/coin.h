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
	Bitmap bitmap;
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
	int (*display)(Coin coin);
};

Coin create_coin(int type, GenMoveFunc movefuncs[9]);
Coin create_archer_coin(void);
int destroy_coin(Coin coin);
int display_coin(Coin coin);
int print_coin(Coin coin);
int print_coin_all(Coin coin);
int set_face_down_coin(Coin coin);
int set_face_up_coin(Coin coin);
int gen_moves_coin(Coin coin, Game game, List move_space);
int same_type_coin(Coin coin1, Coin coin2);


#endif //COIN_H
