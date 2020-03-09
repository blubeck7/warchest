#ifndef HEX_H
#define HEX_H

#include <stdio.h>
#include "types.h"

Board create_board(void);
int init_board(Board board, ListArray gamebox);
int destroy_board(Board board);
int display_board(Board board);
int print_board(Board board);
int print_all_board(Board board);
int toggle_display_board(Board board);

Hex create_hex(FILE *hex_data, int n);
int destroy_hex(Hex hex);
int display_hex(Hex hex);
int toggle_display_hex(Hex hex);

int add_unit_coin_hex(Hex hex, Coin coin);
Coin remove_unit_coin_hex(Hex hex);
int has_unit_coin_hex(Hex hex, Coin coin);

#endif //HEX_H

