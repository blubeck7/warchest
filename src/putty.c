/* TODO: Functions to handle reading bitmaps and plaing them into structures
 * TODO: Layers data structure for drawing
 * TODO: Logical grid/screen to actual rows and columns and pixels
 * TODO: Change file to be just xterm primitives
 */
#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "../inc/window.h"

#define BUF_SZ 33

/* ansi escape sequences */
/* ESC = \x1b
 * CSI = \x1b\x5b ESC[
 * OSC = \x1b\x5d ESC]
 * ST = \x1b\x5c ESC\
 * BEL = \x07
 */
#define ENT_ALT_SCR "\x1b[?1049h"
#define EXIT_ALT_SCR "\x1b[?1049l"
#define CLR_SCR "\x1b[2J"
#define SHOW_CUR "\x1b[?25h"
#define HIDE_CUR "\x1b[?25l"
#define MOVE_CUR "\x1b[%d;%dH"
#define RGB "\x1b[48;2;%d;%d;%dm \x1b[0m"
//#define GET_WIN_FONTSZ OSC"50;?"BEL
/*#define COLOR "\x1b[48;5;%dm \x1b[0m"*/
/*#define SET_WIN_TITLE "\x1b]0;%s\x07"*/

static int hide_cur(void);
static int show_cur(void);
static int move_cur(int x, int y);

int init_win(Win *win)
{
	/* TODO: change this so it gets the actual state of the terminal window at
	 * the time the application starts up.
	 */
	win->wx = 0;
	win->wy = 0;
	win->wwth = 0;
	win->whth = 0;
	win->tx = 0;
	win->ty = 0;
	win->twth = 0;
	win->thth = 0;
	win->cols = 0;
	win->rows = 0;
	win->pprow = 3;
	win->ppcol = 1;
	win->fontsz = 1;
	win->scol = 3;
	win->srow = 1;
	win->xoff = 1;
	win->yoff = 1;
	//char *title = NULL;

	return 0;
};

int print_win(Win *win)
{
	/* TODO */
	return 0;
}
int show_scr(void)
{
	write(STDOUT_FILENO, ENT_ALT_SCR, sizeof(ENT_ALT_SCR));
	hide_cur();

	return 0;
}

int close_scr(void)
{
	show_cur();
	write(STDOUT_FILENO, EXIT_ALT_SCR, sizeof(EXIT_ALT_SCR));

	return 0;
}

int clear_scr(void)
{
	write(STDOUT_FILENO, CLR_SCR, sizeof(CLR_SCR));

	return 0;
}

int move(Win *win, Pos *pos)
{
	int row, col;

	col = pos->x * win->scol + win->yoff;
	row = pos->y * win->srow + win->xoff;
	move_cur(col, row);

	return 0;
}

int draw(Win *win, Pix *pix)
{
	char cmd[BUF_SZ];
	int i, j, n;

	n = sprintf(cmd, RGB, pix->r, pix->g, pix->b);
	for (i = 0; i < win->srow; i++) {
		for (j = 0; j < win->scol; j++) {
			write(STDOUT_FILENO, cmd, n);
		}
	}

	return 0;
}

static int hide_cur(void)
{
	write(STDOUT_FILENO, HIDE_CUR, sizeof(HIDE_CUR));

	return 0;
}

static int show_cur(void)
{
	write(STDOUT_FILENO, SHOW_CUR, sizeof(SHOW_CUR));

	return 0;
}

static int move_cur(int col, int row)
{
	char cmd[20];
	int n;

	n = sprintf(cmd, MOVE_CUR, row, col); //xterm move sequence
	write(STDOUT_FILENO, cmd, n);

	return 0;
}
