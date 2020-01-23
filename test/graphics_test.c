#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include "../inc/graphics.h"
#include "../inc/window.h"

int main(int argc, char *argv[])
{
	Bitmap board, bag_bird;
	Bitmap gcm;
	char s;
	Win win;
	Pos pos;
	Pix ind;
	int x, y;

	load_bitmap(&gcm, "./res/gold_control_marker.bmp");
	load_bitmap(&board, "./res/board.bmp");
	load_bitmap(&bag_bird, "./res/bag_bird.bmp");
	ind.r = 0;
	ind.g = 255;
	ind.b = 0;
	set_ind(&gcm, &ind);
	init_win(&win);
	show_scr();
	x = 306;
	y = 0;
	pos.x = x;
	pos.y = y;
	draw_bitmap(&board, &win, &pos);
	pos.x = x + 161;
	pos.y = y + 277;
	draw_bitmap(&gcm, &win, &pos);
	pos.x = x + 50;
	pos.y = y + 253;
	draw_bitmap(&gcm, &win, &pos);
	pos.x = 2;
	pos.y = 246;
	draw_bitmap(&bag_bird, &win, &pos);
	scanf("%1s", &s);
	close_scr();

	return 0;
}
