#ifndef GRAPHICS_H
#define GRAPHICS_H


int init_scr(void);
int exit_scr(void);
int clr_scr(void);
int move(int x, int y);
int color(int color);
int draw(int x, int y, int color);
int draw_sq(int x, int y, int color);
int hide_cur(void);
int show_cur(void);


#endif //GRAPHICS_H
