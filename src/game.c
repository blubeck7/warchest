#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "../inc/game.h"

#define NUM_PLAYERS 2
#define GOLD_PLAYER 0
#define SILVER_PLAYER 1

struct game {
	int has_winner;
	int num_moves;
	int max_moves;
	int cur_player;
	int round_start;
	int who_initiative_coin;
	int did_initiative_coin_switch;
	Player players[NUM_PLAYERS];
};

int play_game(Game game)
{
	while(!is_done(game)) {
		cur_player = whose_move(game);
		move = get_move(cur_player, game);
		update_game(move, game);
	}

	return 0;
}

int is_done(Game game)
{
	if (game->has_winner || game->num_moves >= game->max_moves)
		return 1;

	return 0;
}

Player whose_move(Game game)
{
	int i;

	if (game->round_start)
		return game->players[game->who_initiative_coin];

	return NULL;
}
