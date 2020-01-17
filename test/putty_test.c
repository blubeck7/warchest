#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include "../inc/window.h"

int main(int argc, char *argv[])
{
	Win win;
	Pix pix;
	Pos pos;
	char s;

	init_win(&win);
	pos.x = 250;
	pos.y = 10;
	pix.r = 255;
	pix.g = 0;
	pix.b = 0;
	show_scr();

	draw(&win, &pos, &pix);

	pos.x = 20;
	pos.y = 100;
	pix.r = 55;
	pix.g = 120;
	pix.b = 50;
	draw(&win, &pos, &pix);
	scanf("%1s", &s);
	close_scr();

	return 0;
}
