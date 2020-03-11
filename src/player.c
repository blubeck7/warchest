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

int destroy_player(Player player)
{
	destroy_list(player->control_coins);
	destroy_listarray(player->supply);
	destroy_list(player->bag);
	destroy_list(player->hand);
	destroy_list(player->discard);
	destroy_list(player->removed);
	free(player);

	return 0;
}

int init_first_game_players(Player players[NUM_PLAYERS], ListArray gamebox)
{
	int i, n;
	Player gold, silver;
	List list_src, list_d;
	Coin coin;

	gold = players[GOLD_PLAYER];
	silver = players[SILVER_PLAYER];

	//num_types
	gold->num_types = GOLD_PLAYER_FIRST_TYPES;
	silver->num_types = SILVER_PLAYER_FIRST_TYPES;
	gold->unit_types[0] = ARCHER;
	gold->unit_types[1] = CAVALRY;
	gold->unit_types[2] = LANCER;
	gold->unit_types[3] = SCOUT;
	gold->unit_types[4] = GOLD_ROYAL_COIN;
	silver->unit_types[0] = CROSSBOWMAN;
	silver->unit_types[1] = LIGHT_CAVALRY;
	silver->unit_types[2] = PIKEMAN;
	silver->unit_types[3] = SWORDSMAN;
	silver->unit_types[4] = SILVER_ROYAL_COIN;

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

	//from supply to bag
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

int display_player(Player player)
{
	/*int i, j, n, m;*/
	/*List list;*/
	/*Coin coin;*/
	Pos pos;

	if (player->display_labels) {
		display_labels(player->pos);
		player->display_labels = 0;
	}

	pos.x = player->pos.x + labels[0].width + 2;
	pos.y = player->pos.y;
	display_supply(player, pos);
	pos.x = player->pos.x + labels[1].width + 2;
	pos.y += labels[1].height; 
	display_bag(player, pos);
	pos.x = player->pos.x + labels[2].width + 2;
	pos.y += labels[2].height; 
	display_hand(player, pos);
	/*m = 0;*/
	/*[>Display Supply<]*/
	/*draw_bitmap(&labels[0], &win, &pos);*/
	/*m++;*/
	
	/*for (i = 0; i < player->num_types; i++) {*/
		/*list = get_listarray(player->supply, player->unit_types[i]);*/
		/*n = len_list(list);*/
		/*for (j = 0; j < n; j++) {*/
			/*coin = (Coin) peak_list(list, j);*/
			/*set_coin_pos(coin, pos);*/
			/*coin->display(coin);*/
			/*m++;*/
			/*if ((m % 8) == 0) {*/
				/*pos.x = player->pos.x;*/
				/*pos.y = player->pos.y + (m / 8) * (coin->front.height + 2); */
			/*} else*/
				/*pos.x = (pos.x + coin->front.width + 2);*/
		/*}*/
	/*}*/

	/*[>Display Bag<]*/
	/*draw_bitmap(&labels[1], &win, &pos);*/
	/*m++;*/
	/*if ((m % 8) == 0) {*/
		/*pos.x = player->pos.x;*/
		/*pos.y = player->pos.y + (m / 8) * (labels[1].height + 2); */
	/*} else*/
		/*pos.x = (pos.x + labels[1].width + 2);*/

	/*n = len_list(player->bag);*/
	/*for (i = 0; i < n; i++) {*/
		/*coin = (Coin) peak_list(player->bag, i);*/
		/*set_coin_pos(coin, pos);*/
		/*coin->display(coin);*/
		/*m++;*/
		/*if ((m % 8) == 0) {*/
			/*pos.x = player->pos.x;*/
			/*pos.y = player->pos.y + (m / 8) * (coin->front.height + 2); */
		/*} else*/
			/*pos.x = (pos.x + coin->front.width + 2);*/
	/*}*/

	/*[>Display Hand<]*/
	/*draw_bitmap(&labels[2], &win, &pos);*/
	/*m++;*/
	/*if ((m % 8) == 0) {*/
		/*pos.x = player->pos.x;*/
		/*pos.y = player->pos.y + (m / 8) * (labels[2].height + 2); */
	/*} else*/
		/*pos.x = (pos.x + labels[1].width + 2);*/

	/*n = len_list(player->hand);*/
	/*for (i = 0; i < n; i++) {*/
		/*coin = (Coin) peak_list(player->hand, i);*/
		/*set_coin_pos(coin, pos);*/
		/*coin->display(coin);*/
		/*m++;*/
		/*if ((m % 8) == 0) {*/
			/*pos.x = player->pos.x;*/
			/*pos.y = player->pos.y + (m / 8) * (coin->front.height + 2); */
		/*} else*/
			/*pos.x = (pos.x + coin->front.width + 2);*/
	/*}*/

	/*[>Display Discard<]*/
	/*draw_bitmap(&labels[3], &win, &pos);*/
	/*m++;*/
	/*if ((m % 8) == 0) {*/
		/*pos.x = player->pos.x;*/
		/*pos.y = player->pos.y + (m / 8) * (labels[2].height + 2); */
	/*} else*/
		/*pos.x = (pos.x + labels[1].width + 2);*/

	/*n = len_list(player->discard);*/
	/*for (i = 0; i < n; i++) {*/
		/*coin = (Coin) peak_list(player->discard, i);*/
		/*set_coin_pos(coin, pos);*/
		/*coin->display(coin);*/
		/*m++;*/
		/*if ((m % 8) == 0) {*/
			/*pos.x = player->pos.x;*/
			/*pos.y = player->pos.y + (m / 8) * (coin->front.height + 2); */
		/*} else*/
			/*pos.x = (pos.x + coin->front.width + 2);*/
	/*}*/

	return 0;
}

int display_labels(Pos init_pos)
{
	Bitmap *bitmap;

	bitmap = &labels[0];
	draw_bitmap(bitmap, &win, &init_pos); //supply

	init_pos.y += bitmap->height;
	bitmap = &labels[1];
	draw_bitmap(bitmap, &win, &init_pos); //bag

	init_pos.y += bitmap->height;
	bitmap = &labels[2];
	draw_bitmap(bitmap, &win, &init_pos); //hand

	init_pos.y += bitmap->height;
	bitmap = &labels[3];
	draw_bitmap(bitmap, &win, &init_pos); //discard

	init_pos.y += bitmap->height;
	bitmap = &labels[4];
	draw_bitmap(bitmap, &win, &init_pos); //removed

	return 0;
}

int display_supply(Player player, Pos pos)
{
	int i, n;
	List coins;
	Coin coin;
	Pos num_pos;

	for (i = 0; i < MAX_TYPE_UNITS; i++) {
		coins = get_listarray(player->supply, player->unit_types[i]);
		n = len_list(coins);
		if (n == 1) {
			coin = (Coin) peak_list(coins, 0);
			set_coin_pos(coin, pos);
			coin->display(coin);
		} else if (n > 1) {
			coin = (Coin) peak_list(coins, 0);
			set_coin_pos(coin, pos);
			coin->display(coin);
			num_pos.x = pos.x + labels[n + 3].width / 2;
			num_pos.y = pos.y + labels[n + 3].height / 2;
			draw_bitmap(&labels[n + 3], &win, &num_pos);
		}
		pos.x += 38;
	}

	return 0;
}

int display_bag(Player player, Pos pos)
{
	int i, j, type, cnt;
	Coin coin, draw_coin = NULL;
	Pos num_pos;

	if (hide)
		return 0;

	for (i = 0; i < MAX_TYPE_UNITS; i++) {
		type = player->unit_types[i];
		cnt = 0;
		for (j = 0; j < len_list(player->bag); j++) {
			coin = (Coin) peak_list(player->bag, j);
			if (coin->type == type) {
				cnt++;
				draw_coin = coin;
			}
		}

		if (cnt == 1) {
			set_coin_pos(draw_coin, pos);
			draw_coin->display(draw_coin);
		} else if (cnt > 1) {
			set_coin_pos(draw_coin, pos);
			draw_coin->display(draw_coin);
			num_pos.x = pos.x + labels[cnt + 3].width / 2;
			num_pos.y = pos.y + labels[cnt + 3].height / 2;
			draw_bitmap(&labels[cnt + 3], &win, &num_pos);
		}
		pos.x += 38;
	}

	return 0;
}

int display_hand(Player player, Pos pos)
{
	int i, j, type, cnt;
	Coin coin, draw_coin = NULL;
	Pos num_pos;
//TODO Just make this simply print hte hand since only three coins

	for (i = 0; i < MAX_TYPE_UNITS; i++) {
		type = player->unit_types[i];
		cnt = 0;
		for (j = 0; j < len_list(player->hand); j++) {
			coin = (Coin) peak_list(player->hand, j);
			if (coin->type == type) {
				cnt++;
				draw_coin = coin;
			}
		}
	
		if (cnt == 1) {
			set_coin_pos(draw_coin, pos);
			draw_coin->display(draw_coin);
		} else if (cnt > 1) {
			set_coin_pos(draw_coin, pos);
			draw_coin->display(draw_coin);
			num_pos.x = pos.x + labels[cnt + 3].width / 2;
			num_pos.y = pos.y + labels[cnt + 3].height / 2;
			draw_bitmap(&labels[cnt + 3], &win, &num_pos);
		}
		pos.x += 38;
	}

	return 0;
}

int print_color_player(Player player)
{
	if (player->color == GOLD_PLAYER)
		fprintf(out, "GOLD");
	else
		fprintf(out, "SILVER");

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
