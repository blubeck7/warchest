#ifndef GAME_H
#define GAME_H

#include "types.h"


int play_game(Game game);
int print_game(Game game);
int print_all_game(Game game);
int is_done(Game game);
Player whose_move(Game game);

#endif //GAME_H
