#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include "../inc/graphics.h"
#include "../inc/window.h"

int main(int argc, char *argv[])
{
	Bitmap board, gcm, ac, bc;
	char s;
	Win win;
	Pos pos;
	Pix ind;
	int x, y, maxx, maxy;

	x = 600 - 78 - 294;
	y = 0;
	maxx = 600;
	maxy = 360;

	ind.r = 0;
	ind.g = 255;
	ind.b = 0;

	load_bitmap(&gcm, "./res/gold_control_marker.bmp");
	load_bitmap(&board, "./res/board.bmp");
	load_bitmap(&ac, "./res/archer_coin.bmp");
	load_bitmap(&bc, "./res/beserker_coin.bmp");
	set_ind(&gcm, &ind);
	set_ind(&ac, &ind);
	set_ind(&bc, &ind);
	init_win(&win);
	show_scr();
	pos.x = x;
	pos.y = y;
	draw_bitmap(&board, &win, &pos);
	pos.x = x + 161;
	pos.y = y + 277;
	draw_bitmap(&gcm, &win, &pos);
	pos.x = x + 50;
	pos.y = y + 253;
	draw_bitmap(&gcm, &win, &pos);
	pos.x = maxx - 2 - 36;
	pos.y = maxy - 2 - 36 ;
	draw_bitmap(&ac, &win, &pos);
	pos.x = maxx - 2 - 36 - 2 - 36;
	pos.y = maxy - 2 - 36;
	draw_bitmap(&bc, &win, &pos);
	scanf("%1s", &s);
	close_scr();

	return 0;
}
