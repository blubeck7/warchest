#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include "../inc/graphics.h"
#include "../inc/window.h"

int main(int argc, char *argv[])
{
	Bitmap bitmap;
	char s;
	Win win;
	Pos pos;
	Pix ind;

	load_bitmap(&bitmap, "./res/gold_control_marker.bmp");
	ind.r = 0;
	ind.g = 255;
	ind.b = 0;
	set_ind(&bitmap, &ind);
	init_win(&win);
	show_scr();
	pos.x = 10;
	pos.y = 10;
	draw_bitmap(&bitmap, &win, &pos);
	scanf("%1s", &s);
	close_scr();

	return 0;
}
