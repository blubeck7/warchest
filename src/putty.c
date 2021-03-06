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

/*int clr_scr(void)*/
/*{*/
	/*if (write(STDOUT_FILENO, CLR_SCR, sizeof(CLR_SCR)) < 0)*/
		/*return -1;*/

	/*return 0;*/
/*}*/


/*int print_win(Win *win)*/
/*{*/
	/*printf("Window Properties\n");*/
	/*printf("pos=%d, %d\n", win->pos.x, win->pos.y);*/
	/*printf("title=%s\n", win->title);*/

	/*return 0;*/
/*}*/

/*int get_win_pos(Win *win)*/
/*{*/
	/*FILE *pipe;*/
	/*char buf[33];*/

	/*if ((pipe = popen("printf \"\x1b[13;2t\"", "r")) == NULL)*/
		/*return -1;*/

	/*if (fgets(buf, 33, pipe) == NULL)*/
		/*return -1;*/
	
	/*pclose(pipe);*/

	/*printf("%s\n", buf);*/
	/***/
	/*strtok(buf, ";:"); //CSI13*/
	/*win->pos.x = atoi(strtok(NULL, ";:")); //x*/
	/*win->pos.y = atoi(strtok(NULL, "t")); //y*/
	/**/

	/*return 0;*/
/*}*/

/*int set_win_pos(Win *win, int x, int y)*/
/*{*/
	/*char cmd[33];*/
	/*int n;*/

	/*if ((n = snprintf(cmd, 33, "\x1b[3;%d;%dt", x, y)) == 33)*/
		/*return -1;*/

	/*win->pos.x = x;*/
	/*win->pos.y = y;*/
	/*write(STDOUT_FILENO, cmd, n);*/

	/*return 0;*/
/*}*/

/*int get_win_title(Win *win)*/
/*{*/
	/*FILE *pipe;*/
	/*char buf[33];*/

	/*if ((pipe = popen("printf \"\x1b[21t\"", "r")) == NULL)*/
		/*return -1;*/

	/*if (fgets(buf, 33, pipe) == NULL)*/
		/*return -1;*/
	
	/*pclose(pipe);*/

	/*printf("%s\n", buf);*/
	/***/
	/*strtok(buf, ";:"); //CSI13*/
	/*win->pos.x = atoi(strtok(NULL, ";:")); //x*/
	/*win->pos.y = atoi(strtok(NULL, "t")); //y*/
	/***/

	/*return 0;*/
/*}*/

/***/
/*int set_win_title(char *title)*/

/*{*/
	/*char cmd[30];*/
	/*int n;*/

	/*n = sprintf(cmd, SET_WIN_TITLE, title);*/
	/*write(STDOUT_FILENO, cmd, n);*/

	/*return 0;*/
/*}*/
/***/


/*int load_bm(char *path, Bm *bm)*/
/*{*/
	/*[> See wikipedia for bitmap file format <]*/
	/*FILE *fp;*/
	/*int pxa, size;*/

	/*fp = fopen(path, "r");*/
	/*fseek(fp, 0x0A, SEEK_SET); //Starting address of pixels*/
	/*fread(&pxa, 4, 1, fp);*/
	/*fseek(fp, 0x12, SEEK_SET); //Bitmap width and height*/
	/*fread(&bm->px_w, 4, 1, fp);*/
	/*fread(&bm->px_h, 4, 1, fp);*/
	/*bm->row_sz = 4 * (int) ceil((24.0 * (double) bm->px_w) / 32.0);*/
	/*fseek(fp, 0x22, SEEK_SET); //Size of pixel array in bytes*/
	/*fread(&size, 4, 1, fp);*/
	/*bm->px = malloc(size);*/
	/*fseek(fp, pxa, SEEK_SET); //Pixel array*/
	/*fread(bm->px, 1, size, fp);*/
	/*fclose(fp);*/

	/*return 0;*/
/*}*/

/*int init_scr(void)*/
/*{*/
	/*struct winsize ws;*/

	/*if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) < 0)*/
		/*return -1;*/

	/*scr.rows = ws.ws_row;*/
	/*scr.cols = ws.ws_col;*/

	/*if (write(STDOUT_FILENO, ENT_ALT_SCR, sizeof(ENT_ALT_SCR)) < 0)*/
		/*return -1;	*/

	/*hide_cur();*/

	/*return 0;*/
/*}*/

/*int exit_scr(void)*/
/*{*/
	/*show_cur();*/

	/*if (write(STDOUT_FILENO, EXIT_ALT_SCR, sizeof(EXIT_ALT_SCR)) < 0)*/
		/*return -1;	*/

	/*return 0;*/
/*}*/

/*int clr_scr(void)*/
/*{*/
	/*if (write(STDOUT_FILENO, CLR_SCR, sizeof(CLR_SCR)) < 0)*/
		/*return -1;*/

	/*return 0;*/
/*}*/

/*int get_win_sz(int *cols, int *rows);*/
/*int set_win_sz(int cols, int rows);*/
/*int get_win_font(int *font);*/
/*int set_win_font(int font);*/

/*int move(int x, int y)*/
/*{*/
	/*char cmd[20];*/
	/*int n;*/

	/*n = sprintf(cmd, MOVE, y, x);*/
	/*write(STDOUT_FILENO, cmd, n);*/

	/*return 0;*/
/*}*/

/*int color(int color)*/
/*{*/
	/*char cmd[20];*/
	/*int n;*/

	/*n = sprintf(cmd, COLOR, color);*/
	/*write(STDOUT_FILENO, cmd, n);*/

	/*return 0;*/
/*}*/

/*int draw(int x, int y, int col)*/
/*{*/
	/*move(x, y);*/
	/*color(col);*/
	/*move(x, y);*/

	/*return 0;*/
/*}*/

/*int draw_px(int x, int y, Pix *pix)*/
/*{*/
	/*char cmd[30];*/
	/*int n;*/

	/*move(x, y);*/
	/*n = sprintf(cmd, RGB, pix->red, pix->green, pix->blue);*/
	/*write(STDOUT_FILENO, cmd, n);*/

	/*return 0;*/
/*}*/

/*int draw_sq(int x, int y, int color)*/
/*{*/
	/*draw(x, y, color);*/
	/*draw(x, y + 1, color);*/

	/*return 0;*/
/*}*/
