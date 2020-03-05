#include <stdio.h>
#include <stdlib.h>
#include "../inc/coin.h"
#include "../inc/ds.h"
#include "../inc/game.h"
#include "../inc/graphics.h"
#include "../inc/hex.h"
#include "../inc/history.h"
#include "../inc/move.h"
#include "../inc/player.h"
#include "../inc/types.h"
#include "../inc/warchest.h"
#include "../inc/window.h"

Coin create_coin(int type, GenMoveFunc movefuncs[9])
{
	Coin coin;

	coin = malloc(sizeof(Coin));
	coin->type = type;
	coin->hex = NULL;
	coin->face = COIN_DOWN;
	coin->deploy = movefuncs[0];
	coin->bolster = movefuncs[1];
	coin->claim = movefuncs[2];
	coin->recruit = movefuncs[3];
	coin->pass = movefuncs[4];
	coin->move = movefuncs[5];
	coin->control = movefuncs[6];
	coin->attack = movefuncs[7];
	coin->tactic = movefuncs[8];

	return coin;
}

Coin create_archer_coin(void)
{
	Coin coin;
	Pix pix;

	coin = malloc(sizeof(struct coin));
	coin->owner = NULL;
	coin->type = ARCHER;
	coin->hex = NULL;
	coin->face = COIN_UP; //up or down
	load_bitmap(&coin->bitmap, ARCHER_BITMAP);
	pix.r = 0;
	pix.g = 255;
	pix.b = 0;
	set_ind(&coin->bitmap, &pix); 
	coin->pos.x = 0;
	coin->pos.y = 0;
	coin->deploy = NULL;
	coin->bolster = NULL;
	coin->claim = NULL;
	coin->recruit = NULL;
	coin->pass = NULL;
	coin->move = NULL;
	coin->control = NULL;
	coin->attack = NULL;
	coin->tactic = NULL;
	coin->display = display_coin;

	return coin;
}

int destroy_coin(Coin coin)
{
	free(coin);

	return 0;
}

int display_coin(Coin coin)
{
	draw_bitmap(&coin->bitmap, &win, &coin->pos);

	return 0;
}

int print_coin(Coin coin)
{
	printf("coin=%p:\n", coin);
	printf("type=%d, hex=%p, face=%d\n", coin->type, coin->hex, coin->face);

	return 0;
}

int set_face_down_coin(Coin coin)
{
	coin->face = COIN_DOWN;

	return 0;
}

int set_face_up_coin(Coin coin)
{
	coin->face = COIN_UP;

	return 0;
}

int gen_moves_coin(Coin coin, Game game, List move_space)
{
	coin->deploy(coin, game, move_space);
	coin->bolster(coin, game, move_space);
	coin->claim(coin, game, move_space);
	coin->recruit(coin, game, move_space);
	coin->pass(coin, game, move_space);
	coin->move(coin, game, move_space);
	coin->control(coin, game, move_space);
	coin->attack(coin, game, move_space);
	coin->tactic(coin, game, move_space);

	return 0;
}


int gen_deploy_moves_coin(Coin coin, Game game, List move_space)
{
	/*List hexes;*/
	/*Hex rhexes[MAX_COINS] = {NULL};*/
	/*Move move;*/
	/*int i;*/

	/*[> deploy function for all coins except the scout and footman<]*/
	/*if (num_coin_stacks_player(coin->owner, coin))*/
		/*return -1;*/

	/*if (!has_unoccupied_control_hexes_game(game, coin->owner))*/
		/*return -1;*/

	/*hexes = get_unoccupied_control_hexes_game(game, coin->owner);*/
	/*for (i = 0; i < len_list(hexes); i++) {*/
		/*move = create_move();*/
		/*set_player_move(move, coin->owner);*/
		/*set_played_coin_move(move, coin);*/
		/*set_num_types_move(move, 1);*/
		/*rhexes[0] = peak_list(hexes, i);*/
		/*set_receiver_hexes(move, rhexes);*/
		/*add_list(move_space, move);*/
	/*}*/

	return 0;
}

int same_type_coin(Coin coin1, Coin coin2)
{
	if (coin1->type == coin2->type)
		return 1;

	return 0;
}

/*	
	remove_coin_hand_player(move->player, move->played_coin);
	add_coin_hex(move->receiver_hexes[0], move->played_coin);

	return 0;


int set_player_move(Move move, Player player);
int set_played_coin_move(Move move, Coin played_coin);
int set_num_types_move(Move move, int num_types);
int set_types_move(Move move, int types[MAX_COINS]);
int set_num_doers(Move move, int num_doers);
int set_doers_move(Move move, Coin doers[MAX_COINS]);
int set_triggered_doers(Move move, Coin triggered_doers[MAX_COINS]);
int set_num_receivers(Move move, int num_receivers);
int set_receivers(Move move, Coin receivers[MAX_COINS]);
int set_triggered_receivers(Move move, Coin triggered_receivers[MAX_COINS]);
int set_triggered_types(Move move, int triggered_types[MAX_COINS]);
int set_doer_hexes(Move move, Hex doer_hexes[MAX_COINS]);
int set_receiver_hexes(Move move, Hex receiver_hexes[MAX_COINS]);
int set_do_move(Move move, int (*do_move)(Move move, Game game));
*/
