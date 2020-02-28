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
#include "../inc/warchest.h"

/*Game game;*/

/*int init_game(int type, char *names[NUM_PLAYERS], GetMoveFunc move_funcs[2]);*/
/*int print_game(void);*/
/*int init_start_player(void);*/
/*int init_board(void);*/
/*int print_board(void);*/
/*int init_players_first(char *names[2], GetMoveFunc move_funcs[2]);*/
/*int init_players_random(void);*/
/*int init_players_snake(void);*/
/*int print_players(void);*/
/*int init_history(void);*/
/*int print_history(void);*/
/*int init_bags(void);*/
/*int print_units(Unit units[MAX_TYPE_UNITS], int num_types);*/
/*int print_discarded(Discard discarded[MAX_NUM_UNITS], int num_discarded);*/
/*int print_unit(int type);*/
/*int play_game(void);*/
/*int draw_coins(void);*/
/*int use_coins(void);*/
/*int fill_bag(int player);*/
/*int shuffle_bag(int player);*/
/*int have_coins(void);*/
/*int update_game(Move move);*/
/*int gen_moves(Game *game_ptr, Move moves[MOVE_SPACE], int *num_moves, int n);*/
/*int gen_deploy_moves(Game *game_ptr, Move moves[MOVE_SPACE], int *num_moves, 					int coin, int n);*/

//History *run_game(MoveFunc move_funcs[NUM_PLAYERS], int game_type);

/*Move random_move(Game *game_ptr, int n);*/
/*Move keyboard_move(Game *game_ptr, int n);*/

int main(int argc, char *argv[])
{
	QueueArray gamebox, Game game;

	gamebox = create_gamebox();
	load_gamebox(gamebox);
	/*History history;*/
	/*MoveFunc move_funcs[2] = {NULL, NULL};*/

	/*history = run_game(move_funcs, FIRST);*/

	/*char *names[2];*/
	/*GetMoveFunc move_funcs[2];*/

	/*names[0] = "HUMAN";*/
	/*names[1] = "COMPUTER";*/
	/*move_funcs[0] = keyboard_move;*/
	/*move_funcs[1] = random_move;*/

	/*init_game(FIRST, names, move_funcs);*/
	/*print_game();*/
	/*//play_game();*/
	/*draw_coins();*/
	/*print_game();*/

	return 0;
}

QueueArray create_gamebox(void)
{
	return NULL;
}

int load_gamebox(QueueArray gamebox)
{
	return 0;
}

/*History run_game(MoveFunc move_funcs[], int game_type)*/
/*{*/
	/*[>History history;<]*/

	/*[>history = malloc(sizeof(History));<]*/

	/*return NULL; //history;*/
/*}*/

/*int init_game(int type, char *names[NUM_PLAYERS], GetMoveFunc move_funcs[2])*/
/*{*/
	/*srand(time(NULL));*/

	/*init_start_player();*/
	/*init_board();*/
	/*switch (type) {*/
	/*case FIRST:*/
		/*init_players_first(names, move_funcs);*/
		/*break;*/
	/*case RANDOM:*/
		/*init_players_random();*/
		/*break;*/
	/*case SNAKE:*/
		/*init_players_snake();*/
		/*break;*/
	/*}*/
	/*init_history();*/
	/*init_bags();*/

	/*return 0;*/
/*}*/

/*int print_game(void)*/
/*{*/
	/*printf("Game:\n");*/
	/*switch (game.cur_player) {*/
	/*case GOLD:*/
		/*printf("cur_player=GOLD");*/
		/*break;*/
	/*case SILVER:*/
		/*printf("cur_player=SILVER");*/
		/*break;*/
	/*}*/
	/*printf(", resolve=%d\n", game.resolve);*/
	/*print_board();*/
	/*print_players();*/
	/*print_history();*/
	/*printf("\n");*/

	/*return 0;*/
/*}*/

/*int init_start_player(void)*/
/*{*/
	/*srand(time(NULL));*/

	/*game.cur_player = GOLD;*/
	/*if (rand() % 2)*/
		/*game.cur_player = SILVER;*/
	
	/*game.resolve = 0;*/

	/*return 0;*/
/*}*/

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
	
/*int print_board(void)*/
/*{*/
	/*int i, j;*/

	/*printf("Board:\n");*/
	/*for (i = 0; i < NUM_HEXES; i++) {*/
		/*printf("Hex %d: id=%d, control_space=%d, ", i, game.board.hexes[i].id,*/
		/*game.board.hexes[i].control_space);*/
		/*switch (game.board.hexes[i].control_marker) {*/
		/*case GOLD:*/
			/*printf("control_marker=GOLD");*/
			/*break;*/
		/*case SILVER:*/
			/*printf("control_marker=SILVER");*/
			/*break;*/
		/*default:*/
			/*printf("control_marker=%d", game.board.hexes[i].control_marker);*/
		/*}*/
		/*printf(", ");*/
		/*printf("num_units=%d, unit=%d, num_adj=%d, ",*/
		/*game.board.hexes[i].num_units, game.board.hexes[i].unit,*/
		/*game.board.hexes[i].num_adj);*/
		/*printf("adj=");*/
		/*for (j = 0; j < game.board.hexes[i].num_adj; j++)*/
			/*printf(" %d", game.board.hexes[i].adj[j]);*/
		/*printf("\n");*/
	/*}*/

	/*return 0;*/
/*}	*/
		
/*int init_players_first(char *names[2], GetMoveFunc move_funcs[2])*/
/*{*/
	/*[> gold player <]*/
	/*game.players[0].name = names[0];*/
	/*game.players[0].color = GOLD;*/
	/*game.players[0].control_coin = 0;*/
	/*if (game.cur_player == GOLD)*/
		/*game.players[0].control_coin = 1;*/
	/*game.players[0].control_markers = NUM_CONTROL_MARKERS - 2;*/
	/*game.players[0].get_move = move_funcs[0];*/

	/*game.players[0].num_types = GOLD_PLAYER_FIRST_TYPES;*/
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
	/*game.players[1].control_markers = NUM_CONTROL_MARKERS - 2;*/
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

/*int init_players_random(void)*/
/*{*/
	/*return 0;*/
/*}*/

/*int init_players_snake(void)*/
/*{*/
	/*return 0;*/
/*}*/

/*int print_players(void)*/
/*{*/
	/*int i, j;*/
	/*Player player;*/

	/*printf("Players:\n");*/
	/*for (i = 0; i < NUM_PLAYERS; i++) {*/
		/*player = game.players[i];*/
		/*printf("name=%s, ", player.name);*/
		/*if (player.color == GOLD)*/
			/*printf("color=GOLD");*/
		/*else if (player.color == SILVER)*/
			/*printf("color=SILVER");*/
		/*printf(", control_coin=%d", player.control_coin);*/
		/*printf(", control_markers=%d", player.control_markers);*/
		/*printf(", num_types=%d", player.num_types);*/
		/*printf(", ");*/
		/*print_units(player.units, player.num_types);*/
		/*printf("\n");*/
		/*printf("num_supply=%d,", player.num_supply);*/
		/*printf(" ");*/
		/*for (j = 0; j < player.num_supply; j++) {*/
			/*print_unit(player.supply[j]);*/
			/*if (j < player.num_supply - 1)*/
				/*printf(", ");*/
		/*}*/
		/*printf("\n");*/
		/*printf("num_bag=%d,", player.num_bag);*/
		/*printf(" ");*/
		/*for (j = 0; j < player.num_bag; j++) {*/
			/*print_unit(player.bag[j]);*/
			/*if (j < player.num_bag - 1)*/
				/*printf(", ");*/
		/*}*/
		/*printf("\n");*/
		/*printf("num_hand=%d", player.num_hand);*/
		/*for (j = 0; j < player.num_hand; j++) {*/
			/*printf(", ");*/
			/*print_unit(player.hand[j]);*/
		/*}*/
		/*printf("\n");*/
		/*print_discarded(player.discarded, player.num_discarded);*/
		/*printf("num_removed=%d\n", player.num_removed);*/
		/*for (j = 0; j < player.num_removed; j++)*/
			/*print_unit(player.removed[j]);*/
	/*}*/

	/*return 0;*/
/*}*/

/*int init_bags(void)*/
/*{*/
	/*int i;*/

	/*for (i = 0; i < NUM_PLAYERS; i++)*/
		/*shuffle_bag(i);*/
		
	/*return 0;*/
/*}*/

/*int print_units(Unit units[MAX_TYPE_UNITS], int num_types)*/
/*{*/
	/*int i;*/

	/*for (i = 0; i < num_types; i++) {*/
		/*print_unit(units[i].type);*/
		/*printf("=%d", units[i].num);*/
		/*if (i < num_types - 1)*/
			/*printf(", ");*/
	/*}*/

	/*return 0;*/
/*}*/
	/*char *name;*/

/*int print_discarded(Discard discarded[MAX_NUM_UNITS], int num_discarded)*/
/*{*/
	/*int i;*/

	/*for (i = 0; i < num_discarded; i++) {*/
		/*print_unit(discarded[i].type);*/
		/*printf("=%d, ", discarded[i].face);*/
		/*printf("\n");*/
	/*}*/

	/*return 0;*/
/*}*/

/*int init_history(void)*/
/*{*/
	/*game.history.num_moves = 0;*/

	/*return 0;*/
/*}*/

/*int print_unit(int type)*/
/*{*/
		/*switch (type) {*/
		/*case ARCHER:*/
			/*printf("archer");*/
			/*break;*/
		/*case BESERKER:*/
			/*printf("beserker");*/
			/*break;*/
		/*case CAVALRY:*/
			/*printf("cavalry");*/
			/*break;*/
		/*case CROSSBOWMAN:*/
			/*printf("crossbowman");*/
			/*break;*/
		/*case ENSIGN:*/
			/*printf("ensign");*/
			/*break;*/
		/*case FOOTMAN:*/
			/*printf("footman");*/
			/*break;*/
		/*case KNIGHT:*/
			/*printf("knight");*/
			/*break;*/
		/*case LANCER:*/
			/*printf("lancer");*/
			/*break;*/
		/*case LIGHT_CAVALRY:*/
			/*printf("light_cavalry");*/
			/*break;*/
		/*case MARSHALL:*/
			/*printf("marshall");*/
			/*break;*/
		/*case MERCENARY:*/
			/*printf("mercenary");*/
			/*break;*/
		/*case PIKEMAN:*/
			/*printf("pikeman");*/
			/*break;*/
		/*case ROYAL_GUARD:*/
			/*printf("royal_guard");*/
			/*break;*/
		/*case SCOUT:*/
			/*printf("scout");*/
			/*break;*/
		/*case SWORDSMAN:*/
			/*printf("swordsman");*/
			/*break;*/
		/*case WARRIOR_PRIEST:*/
			/*printf("warrior_priest");*/
			/*break;*/
		/*case GOLD: case SILVER:*/
			/*printf("royal_coin");*/
			/*break;*/
		/*}*/

	/*return 0;*/
/*}*/

/*int print_history(void)*/
/*{*/
	/*int i;*/

	/*printf("History:\n");*/
	/*for (i = 0; i < game.history.num_moves; i++) {*/
		/*printf("Move: %d", i);*/
		/*printf("player=%d, type=%d, type2=%d, unit=%d, unit2=%d, "*/
				/*"from_hex=%d, to_hex=%d\n",*/
				/*game.history.moves[i].player, game.history.moves[i].type,*/
				/*game.history.moves[i].type2,*/
				/*game.history.moves[i].unit, game.history.moves[i].unit2,*/
				/*game.history.moves[i].from_hex, game.history.moves[i].to_hex);*/
	/*}*/

	/*return 0;*/
/*}*/

/*int play_game(void)*/
/*{*/
	/*int done;*/

	/*done = 0;*/
	/*while (!done) {*/
		/*draw_coins();*/
		/*done = use_coins();*/
	/*}*/

	/*return 0;*/
/*}*/

/*int draw_coins(void)*/
/*{*/
	/*int i, j, n;*/

	/*for (i = 0; i < NUM_PLAYERS; i++) {*/
		/*game.players[i].num_hand = 0;*/

		/*if (game.players[i].num_bag < MAX_HAND)*/
			/*n = game.players[i].num_bag;*/
		/*else*/
			/*n = MAX_HAND;*/

		/*for (j = 0; j < n; j++)*/
			/*game.players[i].hand[game.players[i].num_hand++] =*/
			/*game.players[i].bag[--game.players[i].num_bag];*/

		/*if (game.players[i].num_hand < MAX_HAND) {*/
			/*fill_bag(i);	*/
			/*shuffle_bag(i);*/
		/*}*/

		/*n = MAX_HAND - game.players[i].num_hand;*/
		/*for (j = 0; j < n; j++)*/
			/*game.players[i].hand[game.players[i].num_hand++] =*/
			/*game.players[i].bag[--game.players[i].num_bag];*/
	/*}*/

	/*return 0;*/
/*}*/

/*int use_coins(void)*/
/*{*/
	/*int i, done;*/
	/*Move move;*/

	/*while (have_coins() && !done) {*/
		/*for (i = 0; i < NUM_PLAYERS; i++)*/
			/*if (game.players[i].color == game.cur_player)*/
				/*break;*/
		/*move = game.players[i].get_move(&game, i);*/
		/*done = update_game(move);*/
	/*}*/

	/*return done;*/
/*}*/

/*int fill_bag(int player)*/
/*{*/
	/*int i;*/

	/*for (i = 0; i < game.players[player].num_discarded; i++)*/
		/*game.players[player].bag[game.players[player].num_bag++] = */
		/*game.players[player].discarded[i].type;*/

	/*game.players[player].num_discarded = 0;*/

	/*return 0;*/
/*}*/


/*int shuffle_bag(int player)*/
/*{*/
	/*int i, j, temp;*/

	/*for (i = game.players[player].num_bag; i > 0; i--) {*/
		/*j = rand() % i;*/
		/*temp = game.players[player].bag[i - 1];*/
		/*game.players[player].bag[i - 1] = game.players[player].bag[j];*/
		/*game.players[player].bag[j] = temp;*/
	/*}*/

	/*return 0;*/
/*}*/

/*int have_coins(void)*/
/*{*/
	/*int i;*/

	/*for (i = 0; i < NUM_PLAYERS; i++)*/
		/*if (game.players[i].num_hand)*/
			/*return 1;*/

	/*return 0;*/
/*}*/

/*int gen_moves(Game *game_ptr, Move moves[MOVE_SPACE], int *num_moves, int n)*/
/*{*/
	/*int i, coin;*/

	/*if (game_ptr->resolve)*/
		/*;*/
	/*else {*/
		/*[> playing a new coin <]*/
		/*for (i = 0; i < game.players[n].num_hand; i++) {*/
			/*[> deploy <]*/
			/*coin = game.players[n].hand[i];*/
			/*gen_deploy_moves(game_ptr, moves, num_moves, coin, n);*/
		/*}*/
	/*}*/
	/*//Deploy*/
	/*return 0;*/
/*}*/

/*int gen_deploy_moves(Game *game_ptr, Move moves[MOVE_SPACE], int *num_moves,*/
	/*int coin, int n)*/
/*{*/
	/*int i;*/

	/*for (i = 0; i < NUM_HEXES; i++) {*/
		/*if (game.board.hexes[i].control_marker == game.cur_player &&*/
			/*game.board.hexes[i].num_units == 0 && coin != (GOLD || SILVER)) {*/
			/*;*/
			/*}*/
	/*}*/

	/*return 0;*/
/*}*/


/*int update_game(Move move)*/
/*{*/
	/*return 0;*/
/*}*/

/*Move random_move(Game *game_ptr, int n)*/
/*{*/
	/*int num_moves = 0;*/
	/*Move moves[MOVE_SPACE];*/

	/*gen_moves(game_ptr, moves, &num_moves, n);*/

	/*return moves[rand() % num_moves];*/
/*}*/

/*Move keyboard_move(Game *game_ptr, int n)*/
/*{*/
	/*Move move;*/

	/*move.player = game_ptr->cur_player;*/
	/*printf("Enter the move.\n");*/
	/*printf("type: ");*/
	/*while ((n = scanf("%d", &move.type)) < 1);*/
	/*printf("\n");*/
	/*printf("type2: ");*/
	/*while ((n = scanf("%d", &move.type2)) < 1);*/
	/*printf("\n");*/
	/*printf("unit: ");*/
	/*while ((n = scanf("%d", &move.unit)) < 1);*/
	/*printf("\n");*/
	/*printf("unit2: ");*/
	/*while ((n = scanf("%d", &move.unit2)) < 1);*/
	/*printf("\n");*/
	/*printf("from_hex: ");*/
	/*while ((n = scanf("%d", &move.from_hex)) < 1);*/
	/*printf("\n");*/
	/*printf("to_hex: ");*/
	/*while ((n = scanf("%d", &move.to_hex)) < 1);*/
	/*printf("\n");*/

	/*return move;*/
/*}*/

