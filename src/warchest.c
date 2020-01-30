#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "../inc/graphics.h"
#include "../inc/window.h"
#include "../inc/game_types.h"

#define WIN_W 620
#define WIN_H 360

int run_tests(void);
int do_splash(Win *win);
int get_game_type(Win *win);
int init_game(Player players[NUM_PLAYERS], int type);
int init_first_game(Player players[NUM_PLAYERS]);
int init_random_game(Player players[NUM_PLAYERS]);
int init_snake_game(Player players[NUM_PLAYERS]);


int main(int argc, char *argv[])
{
	Win win;
	Player players[2];
	int do_graphics = 1;
	//int game_type;
	struct termios tp, save;

	if (argc > 1) {
		if (strcmp("-t", argv[1]) == 0) {
			run_tests();
			return 0;
		}
	}

	if (argc > 1) {
		if (strcmp("-e", argv[1]) == 0) {
			do_graphics = 0;
		}
	}

	if (do_graphics) {
		if (tcgetattr(STDIN_FILENO, &tp) == -1)
			exit(-1);
		save = tp;
		tp.c_lflag &= ~(ECHO | ICANON);
		if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp) == -1)
			exit(-1);

		init_win(&win);
		show_scr();
		do_splash(&win);
	}

	//game_type = get_game_type(&win);
	init_game(players, FIRST);

	if (do_graphics) {
		close_scr();
		if (tcsetattr(STDIN_FILENO, TCSANOW, &save) == -1)
			exit(-1);
	}

	return 0;
}

int run_tests(void)
{
	return 0;
}

int do_splash(Win *win)
{
	Bitmap splash;
	Pos ul;

	load_bitmap(&splash, "./res/splash.bmp");
	ul.x = (WIN_W - 294) / 2; 
	ul.y = 0; 
	draw_bitmap(&splash, win, &ul);
	sleep(5);
	clear_scr();
	unload_bitmap(&splash);

	return 0;
}

int get_game_type(Win *win)
{
	Bitmap choice, box;
	Pos ul, cur;
	char buf;
	Pix ind;
	int game_type = 0;

	load_bitmap(&choice, "./res/opp_choice.bmp");
	load_bitmap(&box, "./res/choice_box.bmp");
	ind.r = 0;
	ind.g = 255;
	ind.b = 0;
	set_ind(&box, &ind);

	ul.x = (WIN_W - 294) / 2; 
	ul.y = 0; 
	draw_bitmap(&choice, win, &ul);
	cur.x = cur.y = 0;
	move(win, &cur);
	read(STDIN_FILENO, &buf, 1);
	if (buf == '1') {
		game_type = 1; 
		ul.x = (WIN_W - 294) / 2 + 35; 
		ul.y = 173; 
		draw_bitmap(&box, win, &ul);
	} else if (buf == '2') {
		game_type = 2; 
		ul.x = (WIN_W - 294) / 2 + 35; 
		ul.y = 253; 
		draw_bitmap(&box, win, &ul);
	}
	read(STDIN_FILENO, &buf, 1);
	clear_scr();
	unload_bitmap(&choice);
	unload_bitmap(&box);

	return game_type;
}

int init_game(Player players[NUM_PLAYERS], int type)
{
	if (type == FIRST)
		init_first_game(players);
	else if (type == RANDOM)
		init_random_game(players);
	else if (type == SNAKE)
		init_snake_game(players);
	else
		return -1;

	return 0;
}
	
int init_first_game(Player players[NUM_PLAYERS])
{
	/* player 1 */
	players[0].num_units = FIRST_PLAYER_1_UNITS;

	players[0].units[0].type = ARCHER;
	players[0].units[0].num = 4;
	players[0].units[0].name = "Archer";
	load_bitmap(players[0].units[0].card, "./res/archer_card.bmp");
	load_bitmap(players[0].units[0].coin, "./res/archer_coin.bmp");

	players[0].units[1].type = CAVALRY;
	players[0].units[1].num = 4;
	players[0].units[1].name = "Cavalry";
	load_bitmap(players[0].units[1].card, "./res/cavalry_card.bmp");
	load_bitmap(players[0].units[1].coin, "./res/cavalry_coin.bmp");

	players[0].units[2].type = LANCER;
	players[0].units[2].num = 4;
	players[0].units[2].name = "Lancer";
	load_bitmap(players[0].units[2].card, "./res/lancer_card.bmp");
	load_bitmap(players[0].units[2].coin, "./res/lancer_coin.bmp");

	players[0].units[3].type = SCOUT;
	players[0].units[3].num = 5;
	players[0].units[3].name = "Scout";
	load_bitmap(players[0].units[3].card, "./res/scout_card.bmp");
	load_bitmap(players[0].units[3].coin, "./res/scout_coin.bmp");

	players[0].units[4].type = GOLD_COIN;
	players[0].units[4].num = 1;
	players[0].units[4].name = "Gold Coin";
	players[0].units[4].card = NULL;
	load_bitmap(players[0].units[4].coin, "./res/gold_coin.bmp");

	players[0].num_bag = 9;
	players[0].bag[0] = players[0].bag[1] = &(players[0].units[0]);
	players[0].bag[2] = players[0].bag[3] = &(players[0].units[1]);
	players[0].bag[4] = players[0].bag[5] = &(players[0].units[2]);
	players[0].bag[6] = players[0].bag[7] = &(players[0].units[3]);
	players[0].bag[8] = &(players[0].units[4]);

	players[0].num_hand = 0;

	players[0].num_supply = FIRST_PLAYER_1_UNITS - 9;
	players[0].supply[0] = &(players[0].units[0]);
	players[0].supply[1] = &(players[0].units[0]);
	players[0].supply[2] = &(players[0].units[1]);
	players[0].supply[3] = &(players[0].units[1]);
	players[0].supply[4] = &(players[0].units[2]);
	players[0].supply[5] = &(players[0].units[2]);
	players[0].supply[6] = &(players[0].units[3]);
	players[0].supply[7] = &(players[0].units[3]);
	players[0].supply[8] = &(players[0].units[3]);

	players[0].num_removed = 0;

	/* player 2 */

	players[1].num_units = FIRST_PLAYER_2_UNITS;

	players[1].units[0].type = CROSSBOW;
	players[1].units[0].num = 5;
	players[1].units[0].name = "Crossbowman";
	load_bitmap(players[1].units[0].card, "./res/crossbow_card.bmp");
	load_bitmap(players[1].units[0].coin, "./res/crossbow_coin.bmp");

	players[1].units[1].type = LIGHT_CAVALRY;
	players[1].units[1].num = 5;
	players[1].units[1].name = "Light Cavalry";
	load_bitmap(players[1].units[1].card, "./res/light_card.bmp");
	load_bitmap(players[1].units[1].coin, "./res/light_coin.bmp");

	players[1].units[2].type = PIKEMAN;
	players[1].units[2].num = 4;
	players[1].units[2].name = "Pikeman";
	load_bitmap(players[1].units[2].card, "./res/pikeman_card.bmp");
	load_bitmap(players[1].units[2].coin, "./res/pikeman_coin.bmp");

	players[1].units[3].type = SWORDSMAN;
	players[1].units[3].num = 5;
	players[1].units[3].name = "Swordsman";
	load_bitmap(players[1].units[3].card, "./res/swordsman_card.bmp");
	load_bitmap(players[1].units[3].coin, "./res/swordsman_coin.bmp");

	players[1].units[4].type = SILVER_COIN;
	players[1].units[4].num = 1;
	players[1].units[4].name = "Silver Coin";
	players[1].units[4].card = NULL;
	load_bitmap(players[1].units[4].coin, "./res/silver_coin.bmp");

	players[1].num_bag = 9;
	players[1].bag[0] = players[1].bag[1] = &(players[1].units[0]);
	players[1].bag[2] = players[1].bag[3] = &(players[1].units[1]);
	players[1].bag[4] = players[1].bag[5] = &(players[1].units[2]);
	players[1].bag[6] = players[1].bag[7] = &(players[1].units[3]);
	players[1].bag[8] = &(players[1].units[4]);

	players[1].num_hand = 0;

	players[1].num_supply = FIRST_PLAYER_1_UNITS - 9;
	players[1].supply[0] = &(players[1].units[0]);
	players[1].supply[1] = &(players[1].units[0]);
	players[1].supply[2] = &(players[1].units[0]);
	players[1].supply[3] = &(players[1].units[1]);
	players[1].supply[4] = &(players[1].units[1]);
	players[1].supply[5] = &(players[1].units[1]);
	players[1].supply[6] = &(players[1].units[2]);
	players[1].supply[7] = &(players[1].units[2]);
	players[1].supply[8] = &(players[1].units[3]);
	players[1].supply[9] = &(players[1].units[3]);
	players[1].supply[10] = &(players[1].units[3]);

	players[1].num_removed = 0;

	return 0;
}

int init_random_game(Player players[NUM_PLAYERS])
{
	return 0;
}

int init_snake_game(Player players[NUM_PLAYERS])
{
	return 0;
}
