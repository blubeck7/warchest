#ifndef COIN_H
#define COIN_H

#include "ds.h"
#include "game.h"
#include "types.h"

Coin create_coin(int type, GenMoveFunc movefuncs[9]);
int destroy_coin(Coin coin);
int print_coin(Coin coin);
int print_coin_all(Coin coin);
int set_face_down_coin(Coin coin);
int set_face_up_coin(Coin coin);
int gen_moves_coin(Coin coin, Game game, List move_space);
int same_type(Coin coin1, Coin coin2);

#endif //COIN_H
