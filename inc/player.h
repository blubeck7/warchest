#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

Move get_move_player(Player cur_player, Game game);
int remove_coin_hand_player(Player player, Coin coin);

#endif //PLAYER_H
