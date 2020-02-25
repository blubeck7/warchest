#include <stdio.h>
#include <stdlib.h>
#include "../inc/coin.h"
#include "../inc/game.h"
#include "../inc/hex.h"
#include "../inc/move.h"
#include "../inc/player.h"
#include "../inc/types.h"

#define MAX_COINS 2

//Move types
#define NONE 0
#define DEPLOY 1
#define BOLSTER 2
#define INITIATIVE 3
#define RECRUIT 4
#define PASS 5
#define MOVE 6
#define CONTROL 7
#define ATTACK 8
#define TACTIC 9
#define DRAW 10
#define SELECT 11
#define REMOVE 12
#define MANEUVER 13
#define ENSIGN_MOVE 14

struct move {
	Player player; //The player whose move it is
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

int do_move(Move move, Game game)
{
	return move->do_move(move, game);
}

int deploy_move(Move move, Game game)
{
	remove_coin_hand_player(move->played_coin, move->player);
	add_coin_hex(move->played_coin, move->receiver_hexes[0]);

	return 0;
}
