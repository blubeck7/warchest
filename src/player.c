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
	int list_sizes[] = RESOURCES;
	int i;

	player = malloc(sizeof(struct player));

	player->name = name;
	player->color = color;
	player->num_types = 0;
	player->initiative_coin = NULL;
	player->control_coins = create_list(NUM_CONTROL_COINS);
	player->supply = create_listarray(GAMEBOX_SIZE);
	for (i = 0; i < GAMEBOX_SIZE; i++)
		add_listarray(player->supply, i, create_list(list_sizes[i]));
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

	//num_types
	gold->num_types = GOLD_PLAYER_FIRST_TYPES;
	silver->num_types = SILVER_PLAYER_FIRST_TYPES;

	//control_coins
	for (i = NUM_CONTROL_COINS_BOARD; i < NUM_CONTROL_COINS; i++) {
		coin = (Coin) peak_list(get_listarray(gamebox, GOLD_CONTROL_COIN), i);
		add_list(gold->control_coins, (Item) coin);
		coin = (Coin) peak_list(get_listarray(gamebox, SILVER_CONTROL_COIN),i);
		add_list(silver->control_coins, (Item) coin);
	}

	//supply
	list_src = get_listarray(gamebox, ARCHER);
	list_d = get_listarray(gold->supply, ARCHER);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, CAVALRY);
	list_d = get_listarray(gold->supply, CAVALRY);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, LANCER);
	list_d = get_listarray(gold->supply, LANCER);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, SCOUT);
	list_d = get_listarray(gold->supply, SCOUT);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, GOLD_ROYAL_COIN);
	list_d = get_listarray(gold->supply, GOLD_ROYAL_COIN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}
	
	list_src = get_listarray(gamebox, CROSSBOWMAN);
	list_d = get_listarray(silver->supply, CROSSBOWMAN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, LIGHT_CAVALRY);
	list_d = get_listarray(silver->supply, LIGHT_CAVALRY);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, PIKEMAN);
	list_d = get_listarray(silver->supply, PIKEMAN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, SWORDSMAN);
	list_d = get_listarray(silver->supply, SWORDSMAN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	list_src = get_listarray(gamebox, SILVER_ROYAL_COIN);
	list_d = get_listarray(silver->supply, SILVER_ROYAL_COIN);
	n = len_list(list_src);
	for (i = 0; i < n; i++) {	
		coin = (Coin) peak_list(list_src, i);
		add_list(list_d, (Item) coin);
	}

	//to bag from supply
	list_src = get_listarray(gold->supply, ARCHER);
	for (i = 0; i < NUM_START_COINS; i++) {
		add_list(gold->bag, remove_pos_list(list_src, 0));
	}

	list_src = get_listarray(gold->supply, CAVALRY);
	for (i = 0; i < NUM_START_COINS; i++) {
		add_list(gold->bag, remove_pos_list(list_src, 0));
	}

	list_src = get_listarray(gold->supply, LANCER);
	for (i = 0; i < NUM_START_COINS; i++) {
		add_list(gold->bag, remove_pos_list(list_src, 0));
	}

	list_src = get_listarray(gold->supply, SCOUT);
	for (i = 0; i < NUM_START_COINS; i++) {
		add_list(gold->bag, remove_pos_list(list_src, 0));
	}

	list_src = get_listarray(gold->supply, GOLD_ROYAL_COIN);
	add_list(gold->bag, remove_pos_list(list_src, 0));

	list_src = get_listarray(silver->supply, CROSSBOWMAN);
	for (i = 0; i < NUM_START_COINS; i++) {
		add_list(silver->bag, remove_pos_list(list_src, 0));
	}

	list_src = get_listarray(silver->supply, LIGHT_CAVALRY);
	for (i = 0; i < NUM_START_COINS; i++) {
		add_list(silver->bag, remove_pos_list(list_src, 0));
	}

	list_src = get_listarray(silver->supply, PIKEMAN);
	for (i = 0; i < NUM_START_COINS; i++) {
		add_list(silver->bag, remove_pos_list(list_src, 0));
	}

	list_src = get_listarray(silver->supply, SWORDSMAN);
	for (i = 0; i < NUM_START_COINS; i++) {
		add_list(silver->bag, remove_pos_list(list_src, 0));
	}

	list_src = get_listarray(silver->supply, SILVER_ROYAL_COIN);
	add_list(silver->bag, remove_pos_list(list_src, 0));

	//from bag to hand
	for (i = 0; i < MAX_COINS_HAND; i++) {
		n = rand() % len_list(gold->bag);
		add_list(gold->hand, remove_pos_list(gold->bag, n));
	}

	for (i = 0; i < MAX_COINS_HAND; i++) {
		n = rand() % len_list(silver->bag);
		add_list(silver->hand, remove_pos_list(silver->bag, n));
	}

	return 0;
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
