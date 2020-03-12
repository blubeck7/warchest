#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/coin.h"
#include "../inc/ds.h"
#include "../inc/game.h"
#include "../inc/hex.h"
#include "../inc/history.h"
#include "../inc/player.h"
#include "../inc/types.h"

Game create_game(GetMoveFunc movefuncs[NUM_PLAYERS], char *names[NUM_PLAYERS])
{
	int i, color;
	Game game;

	srand(time(NULL));

	game = malloc(sizeof(struct game));
	game->board = NULL;
	for (i = 0; i < NUM_PLAYERS; i++) {
		color = GOLD_PLAYER;
		if (i)
			color = SILVER_PLAYER;
		game->players[i] = create_player(movefuncs[i], names[i], color);
	}
	game->history = create_history();

	return game;
}

int destroy_game(Game game)
{
	int i;

	for (i = 0; i < NUM_PLAYERS; i++)
		destroy_player(game->players[i]);
	destroy_history(game->history);
	free(game);

	return 0;
}

int init_game(Game game, int game_type, ListArray gamebox)
{
	Coin coin;

	game->num_moves = 0;
	game->max_moves = MAX_MOVES;
	game->has_winner = 0;
	game->winner = NULL;

	game->board = peak_list(get_listarray(gamebox, BOARD2), 0);
	init_board(game->board, gamebox);

	switch (game_type) {
	case FIRST_GAME:
		init_first_game_players(game->players, gamebox);
		game->players[GOLD_PLAYER]->pos.x = game->board->pos.x +
			game->board->bitmap.width + 2;
		game->players[GOLD_PLAYER]->pos.y = 192;
		game->players[GOLD_PLAYER]->display_labels = 1;
		game->players[GOLD_PLAYER]->hide = 0;
		game->players[SILVER_PLAYER]->pos.x = game->board->pos.x +
			game->board->bitmap.width + 2;
		game->players[SILVER_PLAYER]->pos.y = 0;
		game->players[SILVER_PLAYER]->display_labels = 1;
		game->players[SILVER_PLAYER]->hide = 1;
		break;
	case RANDOM_GAME:
		/*init_players_random();*/
		break;
	case SNAKE_GAME:
		/*init_players_snake();*/
		break;
	}

	//initiative_coin
	coin = (Coin) peak_list(get_listarray(gamebox, INITIATIVE_COIN), 0);
	if (rand() % 2) {
		add_initiative_coin_player(game->players[GOLD_PLAYER], coin);
		game->initiative_player = game->players[GOLD_PLAYER];
		game->cur_player = game->players[GOLD_PLAYER];
		game->cur_player_id = GOLD_PLAYER;
	} else {
		add_initiative_coin_player(game->players[SILVER_PLAYER], coin);
		game->initiative_player = game->players[SILVER_PLAYER];
		game->cur_player = game->players[SILVER_PLAYER];
		game->cur_player_id = SILVER_PLAYER;
	}

	game->round_start = 1;
	game->triggered = 0;
	game->did_initiative_coin_switch = 0;

	return 0;
}

History play_game(Game game)
{
	Move move;

	while(!is_done_game(game)) {
		move = get_move_player(game->cur_player, game);
		update_game(game, move);
		add_move_history(game->history, move);
		display_game(game);
	}

	return game->history;
}

int display_game(Game game)
{
	int i;
	display_board(game->board);

	for (i = 0; i < NUM_PLAYERS; i++)
		display_player(game->players[i]);

	fprintf(out, "\n");
	fprintf(out, "Turn %d/%d\n", game->num_moves + 1, game->max_moves);
	if (game->has_winner) {
		print_color_player(game->winner);
		fprintf(out, " wins!\n"); 
	} else {
		if (game->round_start)
			fprintf(out, "It is a new round.\n");
		print_color_player(game->cur_player);
		fprintf(out, " is the current player.\n");
		print_color_player(game->initiative_player);
		fprintf(out, " has the initiative coin.\n");
		if (game->did_initiative_coin_switch)
			fprintf(out, "The initiative coin has switched.\n");
		if (game->triggered)
			fprintf(out, "A unit is triggered.\n");
	}

	return 0;
}

int is_done_game(Game game)
{
	if (game->has_winner || game->num_moves >= game->max_moves)
		return 1;

	return 0;
}

int update_game(Game game, Move move)
{
	/*do_move(move, game);*/
	/*add_move_history(game->history, move);*/

	return 0;
}

int switch_initiative_coin_game(Player to_player, Game game)
{
	Coin coin;

	coin = remove_initiative_coin_player(game->initiative_player);
	add_initiative_coin_player(to_player, coin);
	game->did_initiative_coin_switch = 1;
	game->initiative_player = to_player;

	return 0;
}

int set_triggered_game(Game game)
{
	game->triggered = 1;

	return 0;
}

int gen_moves_game(List hand, Game game, List move_space)
{
	Coin coin;
	int i;

	clear_list(move_space);
	/*If a coin was triggered by a previous move then we need to handle that;
	 *otherwise, a new coin is to be played.
	 */
	if (!game->triggered)
		for (i = 0; i < len_list(hand); i++) {
			coin = (Coin) peak_list(hand, i);
			gen_moves_coin(coin, game, move_space);
		}
	else
		;

	return 0;
}
