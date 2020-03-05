#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/coin.h"
#include "../inc/ds.h"
#include "../inc/game.h"
#include "../inc/hex.h"
#include "../inc/history.h"
#include "../inc/move.h"
#include "../inc/player.h"
#include "../inc/types.h"

struct player {
	char *name;
	int color;
	Coin initiative_coin;
	List supply;
	List hand;
	List discard;
	Queue control_coins;
	GetMoveFunc get_move;
	//int num_types;
	//Unit units[MAX_TYPE_UNITS];
	//int num_bag;
	//int bag[MAX_NUM_UNITS];
	//int num_hand;
	/*List hex_stacks; //the hexes with deployed unit stacks*/
	//int num_deployed;
	//List deployed[MAX_NUM_UNITS]; 
	//int num_discarded;
	//Discard discarded[MAX_NUM_UNITS];
	//int num_removed;
	//int removed[MAX_NUM_UNITS];
};

Player create_player(GetMoveFunc movefunc, char *name, int color)
{
	Player player;

	player = malloc(sizeof(struct player));

	player->name = name;
	player->color = color;
	player->initiative_coin = NULL;
	player->supply = create_list(MAX_NUM_UNITS);
	player->hand = create_list(MAX_COINS_HAND);
	player->discard = create_list(MAX_NUM_UNITS);
	player->control_coins = create_queue(NUM_CONTROL_COINS);
	player->get_move = movefunc;

	return player;
}

Move get_move_player(Player player, Game game)
{
	return player->get_move(player, game);
}

int remove_coin_hand_player(Player player, Coin coin)
{
	if (remove_list(player->hand, (Item) coin) == NULL)
		return -1;

	return 0;
}

int add_coin_discard_player(Player player, Coin coin)
{
	return add_list(player->discard, (Item) coin);
}

Coin remove_initiative_coin_player(Player player)
{
	Coin coin;

	coin = player->initiative_coin;
	player->initiative_coin = NULL;
	
	return coin;
}

int add_initiative_coin_player(Player player, Coin coin)
{
	player->initiative_coin = coin;

	return 0;
}

Move random_move_player(Player player, Game game)
{
	List moves;
	Move move;
	
	srand(time(NULL));

	moves = create_list(MOVE_SPACE_SIZE);
	gen_moves_game(player->hand, game, moves);
	move = (Move) peak_list(moves, rand() % len_list(moves));
	destroy_list(moves);

	return move;
}

int num_coin_stacks_player(Player player, Coin coin)
{
	/*int i, n;*/
	/*Hex hex;*/

	/*n = 0;*/
	/*for (i = 0; i < len_list(player->hex_stacks); i++) {*/
		/*hex = (Hex) peak_list(player->hex_stacks, i);*/
		/*if (has_unit_coin_hex(hex, coin))*/
			/*n++;*/
	/*}*/

	/*return n;*/
	return 0;
}
