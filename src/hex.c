#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/coin.h"
#include "../inc/ds.h"
#include "../inc/game.h"
#include "../inc/graphics.h"
#include "../inc/hex.h"
#include "../inc/history.h"
#include "../inc/player.h"
#include "../inc/types.h"
#include "../inc/window.h"

struct hex {
	int id;
	int num_adj;
	int adj[NUM_ADJ_HEXES];
	int control_hex;
	int init_control_coin;
	Coin control_coin;
	Stack unit_coins;
	Bitmap bitmap;
	Pos pos;
	int display;
};

struct board {
	Bitmap bitmap;
	Pos pos;
	Hex hexes[NUM_HEXES];
	int display;
};

Board create_board(void)
{
	Board board;
	FILE *hex_data;
	int i;
	char *err, line[128];

	if ((board = malloc(sizeof(struct board))) < 0)
		return NULL;
	
	load_bitmap(&board->bitmap, BOARD2_BITMAP);
	board->pos.x = 0;
	board->pos.y = 0;

	hex_data = fopen(BOARD2_DATA, "r");
	if ((err = fgets(line, sizeof(line), hex_data)) == NULL) //header
		return NULL;
	for (i = 0; i < NUM_HEXES; i++) {
		if ((board->hexes[i] = create_hex(hex_data, i)) == NULL) {
			fclose(hex_data);
			return NULL;
		}
	}
	fclose(hex_data);

	return board;
}

int init_board(Board board, ListArray gamebox)
{
	int i, j, k;
	List list;
	
	board->display = 1;

	j = k = 0;
	for (i = 0; i < NUM_HEXES; i++) {
		if (board->hexes[i]->init_control_coin == GOLD_CONTROL_COIN) {
			list = get_listarray(gamebox, GOLD_CONTROL_COIN);
			board->hexes[i]->control_coin = (Coin) peak_list(list, j++);
		} else if (board->hexes[i]->init_control_coin == SILVER_CONTROL_COIN) {
			list = get_listarray(gamebox, SILVER_CONTROL_COIN);
			board->hexes[i]->control_coin = (Coin) peak_list(list, k++);
		}
	}

	return 0;
}

int destroy_board(Board board)
{
	return 0;
}

int display_board(Board board)
{
	int i;

	if (board->display)
		draw_bitmap(&board->bitmap, &win, &board->pos);
	toggle_display_board(board);

	for (i = 0; i < NUM_HEXES; i++)
		display_hex(board->hexes[i]);

	return 0;
}

int toggle_display_board(Board board)
{
	board->display = (board->display + 1) % 2;

	return 0;
}

Hex create_hex(FILE *hex_data, int n)
{
	Hex hex;
	Pix pix;
	char line[128], *token, *adj, *err;
	int i;

	if ((hex = malloc(sizeof(struct hex))) == NULL)
		return NULL;

	if ((err = fgets(line, sizeof(line), hex_data)) == NULL)
		return NULL;

	strtok(line, ","); //line number
	hex->id = atoi(strtok(NULL, ",")); //id
	hex->num_adj = atoi(strtok(NULL, ",")); //num adj
	adj = strtok(NULL, ","); //adjacency list
	hex->control_hex = atoi(strtok(NULL, ",")); //control hex
	hex->init_control_coin = atoi(strtok(NULL, ",")); //init control coin
	hex->pos.x = atoi(strtok(NULL, ","));
	hex->pos.y = atoi(strtok(NULL, ","));
	token = strtok(adj, ":"); //parse adjaceny list
	i = 0;
	while (i < hex->num_adj) {
		hex->adj[i++] = atoi(token);
		token = strtok(NULL, ":");
	}

	hex->control_coin = NULL;
	hex->unit_coins = NULL;

	if (!hex->control_hex)
		load_bitmap(&hex->bitmap, HEX_BITMAP);
	else 
		load_bitmap(&hex->bitmap, CONTROL_HEX_BITMAP);

	pix.r = 0;
	pix.g = 255;
	pix.b = 0;
	set_ind(&hex->bitmap, &pix); 

	hex->display = 1;

	return hex;
}

int display_hex(Hex hex)
{
	if (hex->display)
		draw_bitmap(&hex->bitmap, &win, &hex->pos);
	toggle_display_hex(hex);

	return 0;
}

int toggle_display_hex(Hex hex)
{
	hex->display = (hex->display + 1) % 2;

	return 0;
}

int add_unit_coin_hex(Hex hex, Coin coin)
{
	return add_stack(hex->unit_coins, (Item) coin);
}

Coin remove_unit_coin_hex(Hex hex)
{
	return remove_stack(hex->unit_coins);
}

int has_unit_coin_hex(Hex hex, Coin coin)
{
	return same_type_coin((Coin) peak_stack(hex->unit_coins, 0), coin);
}
