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
	int num_types;
	Coin initiative_coin;
	List control_coins;
	ListArray supply;
	List bag;
	List hand;
	List discard;
	List removed;
	GetMoveFunc get_move;
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
	player->num_types = 0;
	player->initiative_coin = NULL;
	player->control_coins = create_list(NUM_CONTROL_COINS);
	player->supply = create_listarray(GAMEBOX_SIZE);
	player->bag = create_list(MAX_NUM_UNITS);
	player->hand = create_list(MAX_COINS_HAND);
	player->discard = create_list(MAX_NUM_UNITS);
	player->removed = create_list(MAX_NUM_UNITS);
	player->get_move = movefunc;

	return player;
}

int init_first_game_player(Player players[NUM_PLAYERS], ListArray gamebox)
{
	int i, n;
	Player gold, silver;
	List list_src, list_d;
	Coin coin;

	srand(time(NULL));

	gold = players[GOLD_PLAYER];
	silver = players[SILVER_PLAYER];

	gold->num_types = GOLD_PLAYER_FIRST_TYPES;
	silver->num_types = SILVER_PLAYER_FIRST_TYPES;

	coin = (Coin) peak_list(get_listarray(gamebox, INITIATIVE_COIN), 0);
	if (rand() % 2)
		gold->initiative_coin = coin;
	else
		silver->initiative_coin = coin;

	for (i = NUM_CONTROL_COINS_BOARD; i < NUM_CONTROL_COINS; i++) {
		coin = (Coin) peak_list(get_listarray(gamebox, GOLD_CONTROL_COIN), i);
		add_list(players[GOLD_PLAYER]->control_coins, (Item) coin);
		coin = (Coin) peak_list(get_listarray(gamebox, SILVER_CONTROL_COIN),i);
		add_list(players[SILVER_PLAYER]->control_coins, (Item) coin);
	}

	list_src = get_listarray(gamebox, ARCHER);
	list_d = get_listarray(players[GOLD_PLAYER]->supply, ARCHER);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, CAVALRY);
	list_d = get_listarray(players[GOLD_PLAYER]->supply, CAVALRY);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, LANCER);
	list_d = get_listarray(players[GOLD_PLAYER]->supply, LANCER);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, SCOUT);
	list_d = get_listarray(players[GOLD_PLAYER]->supply, SCOUT);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, GOLD_ROYAL_COIN);
	list_d = get_listarray(players[GOLD_PLAYER]->supply, GOLD_ROYAL_COIN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}
	
	list_src = get_listarray(gamebox, CROSSBOWMAN);
	list_d = get_listarray(players[SILVER_PLAYER]->supply, CROSSBOWMAN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, LIGHT_CAVALRY);
	list_d = get_listarray(players[SILVER_PLAYER]->supply, LIGHT_CAVALRY);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, PIKEMAN);
	list_d = get_listarray(players[SILVER_PLAYER]->supply, PIKEMAN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, SWORDSMAN);
	list_d = get_listarray(players[SILVER_PLAYER]->supply, SWORDSMAN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, SILVER_ROYAL_COIN);
	list_d = get_listarray(players[SILVER_PLAYER]->supply, SILVER_ROYAL_COIN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	/*for (i = 0; i < NUM_START_COINS; i++) {*/

	return 0;
}
	/*init_game(game, game_type);*/
/*#define NUM_PLAYERS 2*/
/*#define GOLD_PLAYER 0*/
/*#define SILVER_PLAYER 1*/
/*#define FIRST_GAME 0*/
/*#define RANDOM_GAME 1*/
/*#define SNAKE_GAME 2*/
/*#define GOLD_PLAYER_FIRST_UNITS 18 //includes the royal coin*/
/*#define SILVER_PLAYER_FIRST_UNITS 20 //includes the royal coin */
/*#define GOLD_PLAYER_FIRST_TYPES 5 //includes the royal coin*/
/*#define SILVER_PLAYER_FIRST_TYPES 5 //includes the royal coin */
/*#define NUM_CONTROL_COINS 6*/
/*#define MOVE_SPACE_SIZE 200*/
/*#define MAX_MOVES 200 */
/*#define MAX_TYPE_UNITS 5*/


	/*game.players[0].units[0].type = ARCHER;*/
	/*game.players[0].units[0].num = 4;*/
	/*game.players[0].units[1].type = CAVALRY;*/
	/*game.players[0].units[1].num = 4;*/
	/*game.players[0].units[2].type = LANCER;*/
	/*game.players[0].units[2].num = 4;*/
	/*game.players[0].units[3].type = SCOUT;*/
	/*game.players[0].units[3].num = 5;*/
	/*game.players[0].units[4].type = GOLD;*/
	/*game.players[0].units[4].num = 1;*/

	/*game.players[0].num_supply = GOLD_PLAYER_FIRST_UNITS - 9;*/
	/*game.players[0].supply[0] = ARCHER;*/
	/*game.players[0].supply[1] = ARCHER;*/
	/*game.players[0].supply[2] = CAVALRY;*/
	/*game.players[0].supply[3] = CAVALRY;*/
	/*game.players[0].supply[4] = LANCER;*/
	/*game.players[0].supply[5] = LANCER;*/
	/*game.players[0].supply[6] = SCOUT;*/
	/*game.players[0].supply[7] = SCOUT;*/
	/*game.players[0].supply[8] = SCOUT;*/

	/*game.players[0].num_bag = 9;*/
	/*game.players[0].bag[0] = ARCHER;*/
	/*game.players[0].bag[1] = ARCHER;*/
	/*game.players[0].bag[2] = CAVALRY;*/
	/*game.players[0].bag[3] = CAVALRY;*/
	/*game.players[0].bag[4] = LANCER;*/
	/*game.players[0].bag[5] = LANCER;*/
	/*game.players[0].bag[6] = SCOUT;*/
	/*game.players[0].bag[7] = SCOUT;*/
	/*game.players[0].bag[8] = GOLD;*/

	/*game.players[0].num_hand = 0;*/
	/*game.players[0].num_discarded = 0;*/
	/*game.players[0].num_removed = 0;*/

	/*[> silver player <]*/

	/*game.players[1].name = names[1];*/
	/*game.players[1].color = SILVER;*/
	/*game.players[1].control_coin = 0;*/
	/*if (game.cur_player == SILVER)*/
		/*game.players[1].control_coin = 1;*/
	/*game.players[1].control_markers = NUM_CONTROL_COINS - 2;*/
	/*game.players[1].get_move = move_funcs[1];*/

	/*game.players[1].num_types = SILVER_PLAYER_FIRST_TYPES;*/
	/*game.players[1].units[0].type = CROSSBOWMAN;*/
	/*game.players[1].units[0].num = 5;*/
	/*game.players[1].units[1].type = LIGHT_CAVALRY;*/
	/*game.players[1].units[1].num = 5;*/
	/*game.players[1].units[2].type = PIKEMAN;*/
	/*game.players[1].units[2].num = 4;*/
	/*game.players[1].units[3].type = SWORDSMAN;*/
	/*game.players[1].units[3].num = 5;*/
	/*game.players[1].units[4].type = SILVER;*/
	/*game.players[1].units[4].num = 1;*/

	/*game.players[1].num_supply = SILVER_PLAYER_FIRST_UNITS - 9;*/
	/*game.players[1].supply[0] = CROSSBOWMAN;*/
	/*game.players[1].supply[1] = CROSSBOWMAN;*/
	/*game.players[1].supply[2] = CROSSBOWMAN;*/
	/*game.players[1].supply[3] = LIGHT_CAVALRY;*/
	/*game.players[1].supply[4] = LIGHT_CAVALRY;*/
	/*game.players[1].supply[5] = LIGHT_CAVALRY;*/
	/*game.players[1].supply[6] = PIKEMAN;*/
	/*game.players[1].supply[7] = PIKEMAN;*/
	/*game.players[1].supply[8] = SWORDSMAN;*/
	/*game.players[1].supply[9] = SWORDSMAN;*/
	/*game.players[1].supply[10] = SWORDSMAN;*/

	/*game.players[1].num_bag = 9;*/
	/*game.players[1].bag[0] = CROSSBOWMAN;*/
	/*game.players[1].bag[1] = CROSSBOWMAN;*/
	/*game.players[1].bag[2] = LIGHT_CAVALRY;*/
	/*game.players[1].bag[3] = LIGHT_CAVALRY;*/
	/*game.players[1].bag[4] = PIKEMAN;*/
	/*game.players[1].bag[5] = PIKEMAN;*/
	/*game.players[1].bag[6] = SWORDSMAN;*/
	/*game.players[1].bag[7] = SWORDSMAN;*/
	/*game.players[1].bag[8] = SILVER;*/

	/*game.players[1].num_hand = 0;*/
	/*game.players[1].num_discarded = 0;*/
	/*game.players[1].num_removed = 0;*/

	/*return 0;*/
/*}*/
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
