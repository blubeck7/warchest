/* TODO: pixel object consists of a position on screen and rgb triple. create
 * pixel functions like copy, compare, etc. Add a property for transperency
 */
/* This header file is the interface for handling with the terminal window. The
 * get functions read the current properties of the window, and the set
 * functions change the current properties of the window. The terminal window
 * serves as the screen for an application.
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

typedef struct pos {
	int x;
	int y;
} Pos;

typedef struct pix {
	uint8_t r; //red value between 0 and 255
	uint8_t g; //green value between 0 and 255
	uint8_t b; //blue value between 0 and 255
} Pix;

typedef struct win {
	int wx; //x coordinate of the terminal window
	int wy; //y coordinate of the terminal window
	int wwth; //the width in pixels of the terminal window
	int whth; //the height in pixels of the terminal window
	int tx; //x coordinate of the text area of the terminal window
	int ty; //y coordinate of the text area of the terminal window
	int twth; //the width in pixels of the text area of the terminal window
	int thth; //the height in pixels of the text area of the terminal window
	int cols; //the number of columns of the text area of the terminal window
	int rows; //the number of rows of the text area of the terminal window
	int pprow; //the number of physical pixels per row
	int ppcol; //the number of physical pixels per column
	int fontsz; //the size of the terminal font
	int scol; //the scalar to mulitply the xcoord by to get the column
	int srow; //the scalar to mulitply the ycoord by to get the row
	char *title; //the title of the window
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
int clear_scr(void);

int draw(Win *win, Pos *pos, Pix *pix);


#endif //WINDOW_H
