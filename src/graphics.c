/* TODO: Functions to handle reading bitmaps and plaing them into structures
 * TODO: Layers data structure for drawing
 * TODO: Logical grid/screen to actual rows and columns and pixels
 */
#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "../inc/graphics.h"

/* ansi escape sequences */
#define ENT_ALT_SCR "\x1b[?1049h"
#define EXIT_ALT_SCR "\x1b[?1049l"
#define CLR_SCR "\x1b[2J"
#define MOVE "\x1b[%d;%dH"
#define HIDE_CUR "\x1b[?25l"
#define SHOW_CUR "\x1b[?25h"
#define COLOR "\x1b[48;5;%dm \x1b[0m"
#define RGB "\x1b[48;2;%d;%d;%dm \x1b[0m"

Scr scr;

int load_bm(char *path, Bm *bm)
{
	/* See wikipedia for bitmap file format */
	FILE *fp;
	int pxa, size;

	fp = fopen(path, "r");
	fseek(fp, 0x0A, SEEK_SET); //Starting address of pixels
	fread(&pxa, 4, 1, fp);
	fseek(fp, 0x12, SEEK_SET); //Bitmap width and height
	fread(&bm->px_w, 4, 1, fp);
	fread(&bm->px_h, 4, 1, fp);
	bm->row_sz = 4 * (int) ceil((24.0 * (double) bm->px_w) / 32.0);
	fseek(fp, 0x22, SEEK_SET); //Size of pixel array in bytes
	fread(&size, 4, 1, fp);
	bm->px = malloc(size);
	fseek(fp, pxa, SEEK_SET); //Pixel array
	fread(bm->px, 1, size, fp);
	fclose(fp);

	return 0;
}

int init_scr(void)
{
	struct winsize ws;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) < 0)
		return -1;

	scr.rows = ws.ws_row;
	scr.cols = ws.ws_col;

	if (write(STDOUT_FILENO, ENT_ALT_SCR, sizeof(ENT_ALT_SCR)) < 0)
		return -1;	

	hide_cur();

	return 0;
}

int exit_scr(void)
{
	show_cur();

	if (write(STDOUT_FILENO, EXIT_ALT_SCR, sizeof(EXIT_ALT_SCR)) < 0)
		return -1;	

	return 0;
}

int clr_scr(void)
{
	if (write(STDOUT_FILENO, CLR_SCR, sizeof(CLR_SCR)) < 0)
		return -1;

	return 0;
}

int move(int x, int y)
{
	char cmd[20];
	int n;

	n = sprintf(cmd, MOVE, y, x);
	write(STDOUT_FILENO, cmd, n);

	return 0;
}

int hide_cur(void)
{
	write(STDOUT_FILENO, HIDE_CUR, sizeof(HIDE_CUR));

	return 0;
}

int show_cur(void)
{
	write(STDOUT_FILENO, SHOW_CUR, sizeof(SHOW_CUR));

	return 0;
}

int color(int color)
{
	char cmd[20];
	int n;

	n = sprintf(cmd, COLOR, color);
	write(STDOUT_FILENO, cmd, n);

	return 0;
}

int draw(int x, int y, int col)
{
	move(x, y);
	color(col);
	move(x, y);

	return 0;
}

int draw_px(int x, int y, Pix *pix)
{
	char cmd[30];
	int n;

	move(x, y);
	n = sprintf(cmd, RGB, pix->red, pix->green, pix->blue);
	write(STDOUT_FILENO, cmd, n);

	return 0;
}

int draw_sq(int x, int y, int color)
{
	draw(x, y, color);
	draw(x, y + 1, color);

	return 0;
}
