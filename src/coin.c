#include <stdio.h>
#include <stdlib.h>
#include "../inc/coin.h"
#include "../inc/graphics.h"
#include "../inc/window.h"

int set_face_up_coin(Coin coin)
{
	coin->data.face = COIN_UP;

	return 0;
}

int set_face_down_coin(Coin coin)
{
	coin->data.face = COIN_DOWN;

	return 0;
}

int set_front_coin(Coin coin, Bitmap *front)
{
	coin->data.front = front;

	return 0;
}

int set_back_coin(Coin coin, Bitmap *back)
{
	coin->data.back = back;

	return 0;
}

int set_win_coin(Coin coin, Win *win)
{
	coin->data.win = win;

	return 0;
}

int set_pos_coin(Coin coin, Pos *pos)
{
	coin->data.pos = *pos;

	return 0;
}

int set_txt_coin(Coin coin, char *txt)
{
	coin->data.txt = txt;

	return 0;
}

int set_term_coin(Coin coin, FILE *term)
{
	coin->data.term = term;

	return 0;
}

int display_coin(Coin coin)
{
	if (coin->data.face)
		draw_bitmap(coin->data.front, coin->data.win, &coin->data.pos);
	else
		draw_bitmap(coin->data.back, coin->data.win, &coin->data.pos);

	return 0;
}

int print_coin(Coin coin)
{
	if (coin->data.face)
		fprintf(coin->data.term, "%s", coin->data.txt);
	else
		fprintf(coin->data.term, "x");
	fflush(coin->data.term);

	return 0;
}

int init_coin(Coin coin, int face, Bitmap *front, Bitmap *back, Win *win,
	Pos *pos, char *txt, FILE *term)
{
	coin->data.face = face;
	coin->data.front = front;
	coin->data.back = back;
	coin->data.win = win;
	coin->data.pos = *pos;
	coin->data.txt = txt;
	coin->data.term = term;

	return 0;
}

Coin create_archer_coin(void)
{
	Coin coin;

	coin = malloc(sizeof(struct coin));
	coin->data.type = ARCHER;

	return coin;
}

Coin create_cavalry_coin(void)
{
	Coin coin;

	coin = malloc(sizeof(struct coin));
	coin->data.type = CAVALRY;

	return coin;
}

Coin create_crossbowman_coin(void)
{
	Coin coin;

	coin = malloc(sizeof(struct coin));
	coin->data.type = CROSSBOWMAN;

	return coin;
}

Coin create_lancer_coin(void)
{
	Coin coin;

	coin = malloc(sizeof(struct coin));
	coin->data.type = LANCER;
	
	return coin;
}

Coin create_light_cavalry_coin(void)
{
	Coin coin;

	coin = malloc(sizeof(struct coin));
	coin->data.type = LIGHT_CAVALRY;		

	return coin;
}

Coin create_pikeman_coin(void)
{
	Coin coin;

	coin = malloc(sizeof(struct coin));
	coin->data.type = PIKEMAN;		

	return coin;
}

Coin create_scout_coin(void)
{
	Coin coin;

	coin = malloc(sizeof(struct coin));
	coin->data.type = SCOUT;	

	return coin;
}

Coin create_swordsman_coin(void)
{
	Coin coin;

	coin = malloc(sizeof(struct coin));
	coin->data.type = SWORDSMAN;

	return coin;
}

CoinStack create_coin_stack(void)
{
	CoinStack coin_stack;

	coin_stack = malloc(sizeof(struct coin_stack));

	return coin_stack;
}

int init_coin_stack(CoinStack coin_stack, Bitmap *nums, Win *win, Pos *pos)
{
	coin_stack->num_coins = 0;
	coin_stack->nums = nums;
	coin_stack->win = win;
	coin_stack->pos = *pos;

	return 0;
}

//int add_coin_stack

// // 	coin->type = ARCHER;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_beserker_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = BESERKER;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_cavalry_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = CAVALRY;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_crossbowman_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = CROSSBOWMAN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_ensign_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = ENSIGN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_footman_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = FOOTMAN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_knight_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = KNIGHT;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_lancer_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = LANCER;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_light_cavalry_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = LIGHT_CAVALRY;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_marshall_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = MARSHALL;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_mercenary_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = MERCENARY;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_pikeman_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = PIKEMAN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_royal_guard_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = ROYAL_GUARD;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_scout_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = SCOUT;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_swordsman_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = SWORDSMAN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_warrior_priest_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = WARRIOR_PRIEST;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_gold_royal_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = GOLD_ROYAL_COIN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_silver_royal_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = SILVER_ROYAL_COIN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_gold_control_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = GOLD_CONTROL_COIN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_silver_control_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = SILVER_CONTROL_COIN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// Coin create_initiative_coin(void)
// {
// 	Coin coin;

// 	coin = malloc(sizeof(struct coin));
// 	coin->type = INITIATIVE_COIN;
// 	coin->face = COIN_UP;
// 	coin->hex = NULL;
// 	coin->owner = NULL;

// 	coin->deploy = NULL;
// 	coin->bolster = NULL;
// 	coin->claim = NULL;
// 	coin->recruit = NULL;
// 	coin->pass = NULL;
// 	coin->move = NULL;
// 	coin->control = NULL;
// 	coin->attack = NULL;
// 	coin->tactic = NULL;

// 	coin->pos.x = coin->pos.y = 0;
// 	coin->display_ind = 1;
// 	coin->display = display_coin;

// 	return coin;
// }

// int destroy_coin(Coin coin)
// {
// 	free(coin);

// 	return 0;
// }

// int display_coin(Coin coin)
// {
// 	if (coin->display_ind) {
// 		if (coin->face == COIN_UP)
// 			draw_bitmap(&bitmaps[coin->type], &win, &coin->pos);
// 		else
// 			draw_bitmap(&bitmaps[BACK_COIN], &win, &coin->pos);
// 	}

// 	coin->display_ind = (coin->display_ind + 1) % 2;

// 	return 0;
// }

// int toggle_display_coin(Coin coin)
// {
// 	coin->display_ind = (coin->display_ind + 1) % 2;

// 	return 0;
// }

// int print_coin(Coin coin)
// {
// 	printf("coin=%p:\n", coin);
// 	printf("type=%d, hex=%p, face=%d, (x,y)=(%d,%d)\n",
// 		coin->type, coin->hex, coin->face, coin->pos.x, coin->pos.y);

// 	return 0;
// }

// int set_face_down_coin(Coin coin)
// {
// 	coin->face = COIN_DOWN;

// 	return 0;
// }

// int set_face_up_coin(Coin coin)
// {
// 	coin->face = COIN_UP;

// 	return 0;
// }

// int set_coin_pos(Coin coin, Pos pos)
// {
// 	coin->pos = pos;

// 	return 0;
// }

// int gen_moves_coin(Coin coin, Game game, List move_space)
// {
// 	coin->deploy(coin, game, move_space);
// 	coin->bolster(coin, game, move_space);
// 	coin->claim(coin, game, move_space);
// 	coin->recruit(coin, game, move_space);
// 	coin->pass(coin, game, move_space);
// 	coin->move(coin, game, move_space);
// 	coin->control(coin, game, move_space);
// 	coin->attack(coin, game, move_space);
// 	coin->tactic(coin, game, move_space);

// 	return 0;
// }


// int gen_deploy_moves_coin(Coin coin, Game game, List move_space)
// {
	/*List hexes;*/
	/*Hex rhexes[MAX_COINS] = {NULL};*/
	/*Move move;*/
	/*int i;*/

	/*[> deploy function for all coins except the scout and footman<]*/
	/*if (num_coin_stacks_player(coin->owner, coin))*/
		/*return -1;*/

	/*if (!has_unoccupied_control_hexes_game(game, coin->owner))*/
		/*return -1;*/

	/*hexes = get_unoccupied_control_hexes_game(game, coin->owner);*/
	/*for (i = 0; i < len_list(hexes); i++) {*/
		/*move = create_move();*/
		/*set_player_move(move, coin->owner);*/
		/*set_played_coin_move(move, coin);*/
		/*set_num_types_move(move, 1);*/
		/*rhexes[0] = peak_list(hexes, i);*/
		/*set_receiver_hexes(move, rhexes);*/
		/*add_list(move_space, move);*/
	/*}*/

	// return 0;
// }

// int same_type_coin(Coin coin1, Coin coin2)
// {
// 	if (coin1->type == coin2->type)
// 		return 1;

// 	return 0;
// }

/*	
	remove_coin_hand_player(move->player, move->played_coin);
	add_coin_hex(move->receiver_hexes[0], move->played_coin);

	return 0;


int set_player_move(Move move, Player player);
int set_played_coin_move(Move move, Coin played_coin);
int set_num_types_move(Move move, int num_types);
int set_types_move(Move move, int types[MAX_COINS]);
int set_num_doers(Move move, int num_doers);
int set_doers_move(Move move, Coin doers[MAX_COINS]);
int set_triggered_doers(Move move, Coin triggered_doers[MAX_COINS]);
int set_num_receivers(Move move, int num_receivers);
int set_receivers(Move move, Coin receivers[MAX_COINS]);
int set_triggered_receivers(Move move, Coin triggered_receivers[MAX_COINS]);
int set_triggered_types(Move move, int triggered_types[MAX_COINS]);
int set_doer_hexes(Move move, Hex doer_hexes[MAX_COINS]);
int set_receiver_hexes(Move move, Hex receiver_hexes[MAX_COINS]);
int set_do_move(Move move, int (*do_move)(Move move, Game game));
*/
