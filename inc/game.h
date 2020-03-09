#ifndef GAME_H
#define GAME_H

#include "types.h"

Game create_game(GetMoveFunc movefuncs[NUM_PLAYERS], char *names[NUM_PLAYERS]);
int destroy_game(Game game);
int init_game(Game game, int game_type, ListArray gamebox);
History play_game(Game game);
int display_game(Game game);
int print_game(Game game);
int print_all_game(Game game);
int is_done_game(Game game);
int update_game(Game game, Move move);
int switch_initiative_coin_game(Player to_player, Game game);
int set_triggered_game(Game game);
int gen_moves_game(List hand, Game game, List move_space);
int has_unoccupied_control_hexes_game(Game game, Player player);
List get_unoccupied_control_hexes_game(Game game, Player player);

#endif //GAME_H
