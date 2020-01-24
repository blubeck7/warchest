#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include "../inc/graphics.h"
#include "../inc/window.h"

int main(int argc, char *argv[])
{
	Win win;
	Layers layers;
	Layer base, layer1;
	Bitmap board, gcm, scm, acd, acn, four;
	Pos ul;
	Pix ind;
	char s;

	init_win(&win);
	init_layers(&layers);
	init_layer(&base);
	init_layer(&layer1);

	load_bitmap(&board, "./res/board.bmp");
	load_bitmap(&gcm, "./res/gold_control_marker.bmp");
	load_bitmap(&scm, "./res/silver_control_marker.bmp");
	load_bitmap(&acd, "./res/archer_card.bmp");
	load_bitmap(&acn, "./res/archer_coin.bmp");
	load_bitmap(&four, "./res/four.bmp");
	ind.r = 0;
	ind.g = 255;
	ind.b = 0;
	set_ind(&gcm, &ind);
	set_ind(&scm, &ind);
	set_ind(&acn, &ind);
	set_ind(&four, &ind);

	ul.x = 0;
	ul.y = 0;
	add_bitmap(&base, &board, &ul);
	ul.x = 294 + 24;
	ul.y = 360 - 2 - 36 - 2 - 100;
	add_bitmap(&base, &acd, &ul);
	add_layer(&layers, &base, 0);
	ul.x = 0;
	ul.y = 0;
	set_layer_pos(&layers, 0, &ul);

	ul.x = 161;
	ul.y = 277;
	add_bitmap(&layer1, &gcm, &ul);
	ul.x = 50;
	ul.y = 253;
	add_bitmap(&layer1, &gcm, &ul);
	add_layer(&layers, &layer1, 1);
	ul.x = 0;
	ul.y = 0;
	set_layer_pos(&layers, 1, &ul);

	ul.x = 198;
	ul.y = 61;
	add_bitmap(&layer1, &scm, &ul);
	ul.x = 87;
	ul.y = 37;
	add_bitmap(&layer1, &scm, &ul);
	ul.x = 294 + 24;
	ul.y = 360 - 2 - 36;
	add_bitmap(&layer1, &acn, &ul);
	ul.x = 294 + 24;
	ul.y = 360 - 2 - 36 - 2 - 100;
	add_bitmap(&layer1, &acn, &ul);
	ul.x = 294 + 24 + 75 - 36;
	ul.y = 360 - 2 - 36 - 2 - 100;
	add_bitmap(&layer1, &four, &ul);

	show_scr();
	ul.x = 0;
	ul.y = 0;
	draw_layers(&layers, &win, &ul);
	scanf("%1s", &s);
	close_scr();

	/*Bitmap board, gcm, ac, bc;*/
	/*char s;*/
	/*Win win;*/
	/*Pos pos;*/
	/*Pix ind;*/
	/*int x, y, maxx, maxy;*/

	/*maxx = 600;*/
	/*maxy = 360;*/
	/*x = 600 - 78 - 294;*/
	/*y = 0;*/

	/*ind.r = 0;*/
	/*ind.g = 255;*/
	/*ind.b = 0;*/

	/*load_bitmap(&board, "./res/board.bmp");*/
	/*load_bitmap(&gcm, "./res/gold_control_marker.bmp");*/
	/*load_bitmap(&ac, "./res/archer_coin.bmp");*/
	/*load_bitmap(&bc, "./res/beserker_coin.bmp");*/
	/*set_ind(&gcm, &ind);*/
	/*set_ind(&ac, &ind);*/
	/*set_ind(&bc, &ind);*/
	/*init_win(&win);*/
	/*show_scr();*/
	/*pos.x = x;*/
	/*pos.y = y;*/
	/*draw_bitmap(&board, &win, &pos);*/
	/*pos.x = x + 161;*/
	/*pos.y = y + 277;*/
	/*draw_bitmap(&gcm, &win, &pos);*/
	/*pos.x = x + 50;*/
	/*pos.y = y + 253;*/
	/*draw_bitmap(&gcm, &win, &pos);*/
	/*pos.x = maxx - 2 - 36;*/
	/*pos.y = maxy - 2 - 36 ;*/
	/*draw_bitmap(&ac, &win, &pos);*/
	/*pos.x = maxx - 2 - 36 - 2 - 36;*/
	/*pos.y = maxy - 2 - 36;*/
	/*draw_bitmap(&bc, &win, &pos);*/
	/*scanf("%1s", &s);*/
	/*close_scr();*/

	return 0;
}
