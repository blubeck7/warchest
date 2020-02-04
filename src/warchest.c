#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "../inc/game_types.h"

Game game;

int init_game(int type);
int print_game(void);
int init_start_player(void);
int init_board(void);
int print_board(void);
int init_players_first(void);
int init_random_game(void);
int init_snake_game(void);
int print_players(void);
int init_history(void);
int print_history(void);


int main(int argc, char *argv[])
{
	init_game(FIRST);

	return 0;
}

int init_game(int type)
{
	init_start_player();
	init_board();
	if (type == FIRST)
		init_players_first();
	init_history();

	return 0;
}

int print_game(void)
{
	printf("Game:\n");
	printf("cur_player=%d\n", game.cur_player);
	print_board();
	print_players();
	print_history();

	return 0;
}

int init_start_player(void)
{
	srand(time(NULL));

	game.cur_player = GOLD;
	if (rand() % 2)
		game.cur_player = SILVER;

	return 0;
}

int init_board(void)
{
	FILE *file;
	char line[128], *token, *adj;
	int i, j;

	file = fopen("res/board.csv", "r");
	//header
	fgets(line, sizeof(line), file);
	while (fgets(line, sizeof(line), file)) {
		//hex reference number
		token = strtok(line, ",");
		i = atoi(token);

		//hex id
		token = strtok(NULL, ",");
		game.board.hexes[i].id = atoi(token);

		//number of adjacent hexes
		token = strtok(NULL, ",");
		game.board.hexes[i].num_adj = atoi(token);

		//adjacency list
		adj = strtok(NULL, ",");

		//control space
		token = strtok(NULL, ",");
		game.board.hexes[i].control_space = atoi(token);

		//control maker
		token = strtok(NULL, ",");
		game.board.hexes[i].control_marker = atoi(token);

		//number of units
		token = strtok(NULL, ",");
		game.board.hexes[i].num_units = atoi(token);

		//unit type
		token = strtok(NULL, ",");
		game.board.hexes[i].unit = atoi(token);

		//parse adjaceny list
		token = strtok(adj, ":");
		j = 0;
		while (j < game.board.hexes[i].num_adj) {
			game.board.hexes[i].adj[j] = atoi(token);
			token = strtok(NULL, ":");
			j++;
		}
	}
	
	fclose(file);

	return 0;
}
	
int print_board(void)
{
	int i, j;

	printf("Board:\n");
	for (i = 0; i < NUM_HEXES; i++) {
		printf(
			"Hex %d: id=%d, control_space=%d, control_marker=%d, "
			"num_units=%d, unit=%d, num_adj=%d, ",
			i, game.board.hexes[i].id,
			game.board.hexes[i].control_space,  
			game.board.hexes[i].control_marker,
			game.board.hexes[i].num_units,
			game.board.hexes[i].unit,
			game.board.hexes[i].num_adj);
		printf("adj=");
		for (j = 0; j < game.board.hexes[i].num_adj; j++)
			printf(" %d", game.board.hexes[i].adj[j]);
		printf("\n");
	}

	return 0;
}	
		
int init_players_first(void)
{
	/* gold player */
	game.players[0].color = GOLD;
	game.players[0].control_coin = 0;

	game.players[0].num_units = GOLD_PLAYER_FIRST_UNITS;
	game.players[0].units[0].type = ARCHER;
	game.players[0].units[0].num = 4;
	game.players[0].units[1].type = CAVALRY;
	game.players[0].units[1].num = 4;
	game.players[0].units[2].type = LANCER;
	game.players[0].units[2].num = 4;
	game.players[0].units[3].type = SCOUT;
	game.players[0].units[3].num = 5;
	game.players[0].units[4].type = GOLD;
	game.players[0].units[4].num = 1;

	game.players[0].num_supply = GOLD_PLAYER_FIRST_UNITS - 9;
	game.players[0].supply[0] = ARCHER;
	game.players[0].supply[1] = ARCHER;
	game.players[0].supply[2] = CAVALRY;
	game.players[0].supply[3] = CAVALRY;
	game.players[0].supply[4] = LANCER;
	game.players[0].supply[5] = LANCER;
	game.players[0].supply[6] = SCOUT;
	game.players[0].supply[7] = SCOUT;
	game.players[0].supply[8] = SCOUT;

	game.players[0].num_bag = 9;
	game.players[0].bag[0] = ARCHER;
	game.players[0].bag[1] = ARCHER;
	game.players[0].bag[2] = CAVALRY;
	game.players[0].bag[3] = CAVALRY;
	game.players[0].bag[4] = LANCER;
	game.players[0].bag[5] = LANCER;
	game.players[0].bag[6] = SCOUT;
	game.players[0].bag[7] = SCOUT;
	game.players[0].bag[8] = GOLD;

	game.players[0].num_hand = 0;
	game.players[0].num_discarded = 0;
	game.players[0].num_removed = 0;

	/* silver player */

	game.players[1].color = SILVER;
	game.players[1].control_coin = 0;

	game.players[1].num_units = SILVER_PLAYER_FIRST_UNITS;
	game.players[1].units[0].type = CROSSBOWMAN;
	game.players[1].units[0].num = 5;
	game.players[1].units[1].type = LIGHT_CAVALRY;
	game.players[1].units[1].num = 5;
	game.players[1].units[2].type = PIKEMAN;
	game.players[1].units[2].num = 4;
	game.players[1].units[3].type = SWORDSMAN;
	game.players[1].units[3].num = 5;
	game.players[1].units[4].type = SILVER;
	game.players[1].units[4].num = 1;

	game.players[1].num_supply = SILVER_PLAYER_FIRST_UNITS - 9;
	game.players[1].supply[0] = CROSSBOWMAN;
	game.players[1].supply[1] = CROSSBOWMAN;
	game.players[1].supply[2] = CROSSBOWMAN;
	game.players[1].supply[3] = LIGHT_CAVALRY;
	game.players[1].supply[4] = LIGHT_CAVALRY;
	game.players[1].supply[5] = LIGHT_CAVALRY;
	game.players[1].supply[6] = PIKEMAN;
	game.players[1].supply[7] = PIKEMAN;
	game.players[1].supply[8] = SWORDSMAN;
	game.players[1].supply[9] = SWORDSMAN;
	game.players[1].supply[10] = SWORDSMAN;

	game.players[1].num_bag = 9;
	game.players[1].bag[0] = CROSSBOWMAN;
	game.players[1].bag[1] = CROSSBOWMAN;
	game.players[1].bag[2] = LIGHT_CAVALRY;
	game.players[1].bag[3] = LIGHT_CAVALRY;
	game.players[1].bag[4] = PIKEMAN;
	game.players[1].bag[5] = PIKEMAN;
	game.players[1].bag[6] = SWORDSMAN;
	game.players[1].bag[7] = SWORDSMAN;
	game.players[1].bag[8] = SILVER;

	game.players[1].num_hand = 0;
	game.players[1].num_discarded = 0;
	game.players[1].num_removed = 0;

	return 0;
}

int init_random_game(void)
{
	return 0;
}

int init_snake_game(void)
{
	return 0;
}

int print_players(void)
{
	int i;
	Player player;

	printf("Players:\n");
	for (i = 0; i < NUM_PLAYERS; i++) {
		player = game.players[i];
		printf("color=%d, control_coin=%d\n", player.color, player.control_coin);
		printf("num_units=%d ", player.num_units);
		print_units(player.units, player.num_units);
		printf("\n");
		printf("num_supply=%d ", player.num_supply);
		print_units(player.supply, player.num_units);

int print_units(Unit units[MAX_TYPE_UNITS], int num_units)
{
	int i;

	for (i = 0; i < num_units; i++)
		switch (units[i].type) {
		case ARCHER:
			printf("archer");
			break;
		case BESERKER:
			printf("beserker");
			break;
		case CAVALRY:
			printf("cavalry");
			break;
		case CROSSBOWMAN:
			printf("crossbowman");
			break;
		case ENSIGN:
			printf("ensign");
			break;
		case FOOTMAN:
			printf("footman");
			break;
		case KNIGHT:
			printf("knight");
			break;
		case LANCER:
			printf("lancer");
			break;
		case LIGHT_CAVALRY:
			printf("light_cavalry");
			break;
		case MARSHALL:
			printf("marshall");
			break;
		case MERCENARY:
			printf("mercenary");
			break;
		case PIKEMAN:
			printf("pikeman");
			break;
		case ROYAL_GUARD:
			printf("royal_guard");
			break;
		case SCOUT:
			printf("scout");
			break;
		case SWORDSMAN:
			printf("swordsman");
			break;
		case WARRIOR_PRIEST:
			printf("warrior_priest");
			break;
		default;
			break;
		}
		printf("=%d, ", units[i].num);
	}

	return 0;
}

int init_history(void)
{
	game.history.num_moves = 0;

	return 0;
}
