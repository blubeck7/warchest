#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "../src/graphics.c"

#define PI 3.14159265358979323846

int main(int argc, char *argv[])
{
	Bm bm;
	Pix pix;

	load_bm("./res/gold_control_marker.bmp", &bm);

	int i, x, y, h, k, r;
	double ang;
	char s;

	init_scr();

	/*
	r = 6;
	h = 40;
	k = 20;
	for (i = 0; i < 360; i++) {
		ang = i * (2 * PI / 360);
		x = (int) r * cos(ang) + h;
		y = (int) r * sin(ang) + k;
		draw_sq(x, y, 40);
	}
	*/
	for (i = 0; i < 100; i++) {
		pix.red = i + 100; 
		pix.green = 155;
		pix.blue = 155;
		draw_px(i, 20, &pix);
	}
	scanf("%1s", &s);
	exit_scr();

	return 0;
}
