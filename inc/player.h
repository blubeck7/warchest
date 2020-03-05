#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

Player create_player(GetMoveFunc movefunc, char *name, int color);
int init_first_game_player(Player players[NUM_PLAYERS], ListArray gamebox);
int destroy_player(Player player);
Move get_move_player(Player cur_player, Game game);
int remove_coin_hand_player(Player player, Coin coin);
int add_coin_discard_player(Player player, Coin coin);
Coin remove_initiative_coin_player(Player player);
int add_initiative_coin_player(Player player, Coin coin);
Move random_move_player(Player player, Game game);
int remove_coin_supply_player(Player player, Coin coin);
int num_coin_stacks_player(Player player, Coin coin);

#endif //PLAYER_H
