#include <stdio.h>
#include <stdlib.h>
#include "../inc/coin.h"
#include "../inc/ds.h"
#include "../inc/game.h"
#include "../inc/hex.h"
#include "../inc/history.h"
#include "../inc/move.h"
#include "../inc/player.h"
#include "../inc/types.h"

struct coin {
	Player owner;
	int type;
	Hex hex;
	int face; //up or down
	GenMoveFunc deploy;
	GenMoveFunc bolster;
	GenMoveFunc claim;
	GenMoveFunc recruit;
	GenMoveFunc pass;
	GenMoveFunc move;
	GenMoveFunc control;
	GenMoveFunc attack;
	GenMoveFunc tactic;
};


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

int destroy_coin(Coin coin)
{
	free(coin);

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
	List hexes;
	Hex rhexes[MAX_COINS] = {NULL};
	Move move;
	int i;

	/* deploy function for all coins except the scout and footman*/
	if (num_coin_stacks_player(coin->owner, coin))
		return -1;

	if (!has_unoccupied_control_hexes_game(game, coin->owner))
		return -1;

	hexes = get_unoccupied_control_hexes_game(game, coin->owner);
	for (i = 0; i < len_list(hexes); i++) {
		move = create_move();
		set_player_move(move, coin->owner);
		set_played_coin_move(move, coin);
		set_num_types_move(move, 1);
		rhexes[0] = peak_list(hexes, i);
		set_receiver_hexes(move, rhexes);
		add_list(move_space, move);
	}

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
