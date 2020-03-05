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

struct hex {
	int id;
	int num_adj;
	int adj[NUM_ADJ_HEXES];
	int control_hex;
	int init_control_coin;
	Coin control_coin;
	Stack unit_coins;
	Bitmap *bitmap;
};

struct board {
	Bitmap *bitmap;
	Hex hexes[NUM_HEXES];
};

Board create_board(void)
{
	Board board;
	FILE *hex_data;
	int i;
	char *err, line[128];

	if ((board = malloc(sizeof(struct board))) < 0)
		return NULL;
	
	board->bitmap = malloc(sizeof(struct bitmap));
	load_bitmap(board->bitmap, BOARD_BITMAP);

	hex_data = fopen(BOARD_DATA, "r");
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


int destroy_board(Board board)
{
	return 0;
}

Hex create_hex(FILE *hex_data, int n)
{
	Hex hex;
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
	token = strtok(adj, ":"); //parse adjaceny list
	i = 0;
	while (i < hex->num_adj) {
		hex->adj[i++] = atoi(token);
		token = strtok(NULL, ":");
	}

	if ((hex->bitmap = malloc(sizeof(struct bitmap))) == NULL)
		return NULL;
	if (!hex->control_hex)
		load_bitmap(hex->bitmap, HEX_BITMAP);
	else 
		load_bitmap(hex->bitmap, CONTROL_HEX_BITMAP);

	hex->control_coin = NULL;
	hex->unit_coins = NULL;

	return hex;
}

/*int init_board(void)*/
/*{*/
	/*FILE *file;*/
	/*char line[128], *token, *adj;*/
	/*int i, j;*/
	/*char *err;*/

	/*file = fopen("res/board.csv", "r");*/
	/*//header*/
	/*if ((err = fgets(line, sizeof(line), file)) == NULL)*/
		/*return -1;*/
	/*while (fgets(line, sizeof(line), file)) {*/
		/*//hex reference number*/
		/*token = strtok(line, ",");*/
		/*i = atoi(token);*/

		/*//hex id*/
		/*token = strtok(NULL, ",");*/
		/*game.board.hexes[i].id = atoi(token);*/

		/*//number of adjacent hexes*/
		/*token = strtok(NULL, ",");*/
		/*game.board.hexes[i].num_adj = atoi(token);*/

		/*//adjacency list*/
		/*adj = strtok(NULL, ",");*/

		/*//control space*/
		/*token = strtok(NULL, ",");*/
		/*game.board.hexes[i].control_space = atoi(token);*/

		/*//control maker*/
		/*token = strtok(NULL, ",");*/
		/*game.board.hexes[i].control_marker = atoi(token);*/

		/*//number of units*/
		/*token = strtok(NULL, ",");*/
		/*game.board.hexes[i].num_units = atoi(token);*/

		/*//unit type*/
		/*token = strtok(NULL, ",");*/
		/*game.board.hexes[i].unit = atoi(token);*/

		/*//parse adjaceny list*/
		/*token = strtok(adj, ":");*/
		/*j = 0;*/
		/*while (j < game.board.hexes[i].num_adj) {*/
			/*game.board.hexes[i].adj[j] = atoi(token);*/
			/*token = strtok(NULL, ":");*/
			/*j++;*/
		/*}*/
	/*}*/
	
	/*fclose(file);*/

	/*return 0;*/
/*}*/

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
