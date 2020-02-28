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

struct move {
	Player player; //The player who performed the move
	Coin played_coin; //The coin played from a player's hand
	int num_types; //The number of types of moves made
	int types[MAX_COINS]; //The types of moves made
	int num_doers; //The number of coins doing the moves
	Coin doers[MAX_COINS]; //The coins doing the moves
	Coin triggered_doers[MAX_COINS]; //Any doers whose abilities are triggered 
	int num_receivers; //The number of coins receiving the moves
	Coin receivers[MAX_COINS]; //The coins receiving the move
	Coin triggered_receivers[MAX_COINS]; //Any receivers with abilities trig
	int triggered_types[MAX_COINS]; //The types of moves that are triggered
	Hex doer_hexes[MAX_COINS]; //The hexes of the doer coins
	Hex receiver_hexes[MAX_COINS]; //The hexes receiving the action
	int (*do_move)(Move move, Game game);
};

Move create_move(void)
{
	Move move;
	int i;

	move = malloc(sizeof(struct move));

	move->player = NULL;
	move->played_coin = NULL;
	move->num_types = 0;
	move->num_doers = 0;
	move->num_receivers = 0;
	move->do_move = NULL;
	for (i = 0; i < MAX_COINS; i++) {
		move->types[i] = NONE;
		move->doers[i] = NULL;
		move->triggered_doers[i] = NULL;
		move->receivers[i] = NULL;
		move->triggered_receivers[i] = NULL;
		move->triggered_types[i] = NONE;
		move->doer_hexes[i] = NULL;
		move->receiver_hexes[i] = NULL;
	}

	return move;
}

int set_player_move(Move move, Player player)
{
	move->player = player;

	return 0;
}

int set_played_coin_move(Move move, Coin played_coin)
{
	move->played_coin = played_coin;

	return 0;
}

int set_num_types_move(Move move, int num_types)
{
	move->num_types = num_types;

	return 0;
}

int set_types_move(Move move, int types[MAX_COINS])
{
	int i;

	for (i = 0; i < MAX_COINS; i++)
		move->types[i] = types[i];

	return 0;
}

int set_num_doers(Move move, int num_doers)
{
	move->num_doers = num_doers;

	return 0;
}

int set_doers_move(Move move, Coin doers[MAX_COINS])
{
	int i;

	for (i = 0; i < MAX_COINS; i++)
		move->doers[i] = doers[i];

	return 0;
}

int set_triggered_doers(Move move, Coin triggered_doers[MAX_COINS])
{
	int i;

	for (i = 0; i < MAX_COINS; i++)
		move->triggered_doers[i] = triggered_doers[i];

	return 0;
}

int set_num_receivers(Move move, int num_receivers)
{
	move->num_receivers = 0;

	return 0;
}

int set_receivers(Move move, Coin receivers[MAX_COINS])
{
	int i;

	for (i = 0; i < MAX_COINS; i++)
		move->receivers[i] = receivers[i];

	return 0;
}

int set_triggered_receivers(Move move, Coin triggered_receivers[MAX_COINS])
{
	int i;

	for (i = 0; i < MAX_COINS; i++)
		move->triggered_receivers[i] = triggered_receivers[i];

	return 0;
}

int set_triggered_types(Move move, int triggered_types[MAX_COINS])
{
	int i;

	for (i = 0; i < MAX_COINS; i++)
		move->triggered_types[i] = triggered_types[i];

	return 0;
}

int set_doer_hexes(Move move, Hex doer_hexes[MAX_COINS])
{
	int i;

	for (i = 0; i < MAX_COINS; i++)
		move->doer_hexes[i] = doer_hexes[i];

	return 0;
}

int set_receiver_hexes(Move move, Hex receiver_hexes[MAX_COINS])
{
	int i;

	for (i = 0; i < MAX_COINS; i++)
		move->receiver_hexes[i] = receiver_hexes[i];

	return 0;
}

int set_do_move(Move move, int (*do_move)(Move move, Game game))
{
	move->do_move = do_move;

	return 0;
}

int destroy_move(Move move)
{
	free(move);

	return 0;
}

int do_move(Move move, Game game)
{
	return move->do_move(move, game);
}

int deploy_move(Move move, Game game)
{
	remove_coin_hand_player(move->player, move->played_coin);
	add_coin_hex(move->receiver_hexes[0], move->played_coin);

	return 0;
}

int bolster_move(Move move, Game game)
{
	remove_coin_hand_player(move->player, move->played_coin);
	add_coin_hex(move->receiver_hexes[0], move->played_coin);

	return 0;
}

int initiative_move(Move move, Game game)
{
	remove_coin_hand_player(move->player, move->played_coin);
	set_face_down_coin(move->played_coin);
	add_coin_discard_player(move->player, move->played_coin);
	switch_initiative_coin_game(move->player, game);

	return 0;
}

int recruit_move(Move move, Game game)
{
	int i;

	remove_coin_hand_player(move->player, move->played_coin);
	set_face_down_coin(move->played_coin);
	add_coin_discard_player(move->player, move->played_coin);
	remove_coin_supply_player(move->player, move->receivers[0]);
	set_face_up_coin(move->receivers[0]);
	add_coin_discard_player(move->player, move->receivers[0]);

	for (i = 0; move->num_types; i++)
		if (move->triggered_receivers[i])
			set_triggered_game(game);

	return 0;
}

