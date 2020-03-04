#ifndef HEX_H
#define HEX_H

#include "types.h"

Board create_board(void);
int destroy_board(Board board);
int display_board(Board board);

int add_unit_coin_hex(Hex hex, Coin coin);
Coin remove_unit_coin_hex(Hex hex);
int has_unit_coin_hex(Hex hex, Coin coin);

#endif //HEX_H

