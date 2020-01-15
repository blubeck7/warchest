#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "../src/graphics.c"

#define PI 3.14159265358979323846

int main(int argc, char *argv[])
{
	//Bm bm;
	//Pix pix;
	char s;//, str[40];
	Win win;

	//load_bm("./res/gold_control_marker.bmp", &bm);
	init_scr();
	init_win(&win);
	//print_win(&win);
	get_win_pos(&win);
	get_win_title(&win);
	print_win(&win);
	//set_win_pos(&win, 100, 100);
	//print_win(&win);
	//set_win_tit("Warchest");
	//get_win_tit(str);
	//printf("%s", str);

	scanf("%1s", &s);
	exit_scr();

	return 0;
}
