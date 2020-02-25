#ifndef COIN_H
#define COIN_H

#include "types.h"

#define COIN_DOWN 0
#define COIN_UP 1

Coin create_coin(int type, MoveFunc movefuncs[9]);
int destroy_coin(Coin coin);
int print_coin(Coin coin);
int print_coin_all(Coin coin);

#endif //COIN_H
