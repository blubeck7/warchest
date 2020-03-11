#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

struct player {
	char *name;
	int color;
	int num_types;
	int unit_types[MAX_TYPE_UNITS];
	Coin initiative_coin;
	List control_coins;
	ListArray supply;
	List bag;
	List hand;
	List discard;
	List removed;
	GetMoveFunc get_move;
	Pos pos;
	int display_labels;
	//int num_hand;
	/*List hex_stacks; //the hexes with deployed unit stacks*/
	//int num_deployed;
	//List deployed[MAX_NUM_UNITS]; 
	//int num_discarded;
	//Discard discarded[MAX_NUM_UNITS];
	//int num_removed;
	//int removed[MAX_NUM_UNITS];
};

Player create_player(GetMoveFunc movefunc, char *name, int color);
int destroy_player(Player player);
int init_first_game_players(Player players[NUM_PLAYERS], ListArray gamebox);
int display_player(Player player);
int display_labels(Pos init_pos);
int display_supply(Player player, Pos pos);
int display_bag(Player player, Pos pos, int hide);
int display_hand(Player player, Pos pos, int hide);
int print_color_player(Player player);
Move get_move_player(Player cur_player, Game game);
int remove_coin_hand_player(Player player, Coin coin);
int add_coin_discard_player(Player player, Coin coin);
Coin remove_initiative_coin_player(Player player);
int add_initiative_coin_player(Player player, Coin coin);
Move random_move_player(Player player, Game game);
int remove_coin_supply_player(Player player, Coin coin);
int num_coin_stacks_player(Player player, Coin coin);

#endif //PLAYER_H
