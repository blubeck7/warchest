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
	int game_type;
	struct termios tp, save;

	if (tcgetattr(STDIN_FILENO, &tp) == -1)
		exit(-1);
	save = tp;
	tp.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp) == -1)
		exit(-1);

	if (argc > 1) {
		if (strcmp("-t", argv[1]) == 0) {
			run_tests();
			return 0;
		}
	}

	init_win(&win);
	show_scr();
	do_splash(&win);
	game_type = get_game_type(&win);
	init_game(players, FIRST);
	close_scr();

	if (tcsetattr(STDIN_FILENO, TCSANOW, &save) == -1)
		exit(-1);

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
	players[HUMAN].num_units = FIRST_PLAYER_1_UNITS;

	players[HUMAN].units[0].type = ARCHER;
	players[HUMAN].units[0].name = "Archer";
	load_bitmap(players[HUMAN].units[0].card, "./res/archer_card.bmp");
	load_bitmap(players[HUMAN].units[0].coin, "./res/archer_coin.bmp");

	players[HUMAN].units[0].type = CAVALRY;
	players[HUMAN].units[0].name = "Cavalry";
	load_bitmap(players[HUMAN].units[0].card, "./res/cavalry_card.bmp");
	load_bitmap(players[HUMAN].units[0].coin, "./res/cavalry_coin.bmp");

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
