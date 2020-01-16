#ifndef WINDOW_H
#define WINDOW_H

/* This header file is the interface for dealing with the terminal window. The
 * get functions read the current properties of the window, and the set
 * functions change the current properties of the window.
 */

typedef struct scr {
	int rows;
	int cols;
} Scr;

typedef struct pix {
	int red;
	int green;
	int blue;
	int trans;
} Pix;

typedef struct win {
	int cols;
	int fontsz;
	int rows;
	char *title;
	int x;
	int y;
} Win;

int init_win(Win *win);
int print_win(Win *win);
int get_win_fontsz(Win *win);
int set_win_fontsz(int font);
int get_win_pos(Win *win);
int set_win_pos(Win *win, int x, int y);
int get_win_sz(Win *win);
int set_win_sz(Win *win, int cols, int rows);
int get_win_title(Win *win);
int set_win_title(Win *win, char *title);

int show_scr(void);
int close_scr(void);
int clr_win(void);

int draw(int x, int y, int color);


#endif //WINDOW_H
