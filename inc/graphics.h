#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef struct bm {
	int px_w;
	int px_h;
	int row_sz;
	unsigned char *px;
} Bm;

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

int init_scr(void);
int exit_scr(void);
int clr_scr(void);
int move(int x, int y);
int color(int color);
int draw(int x, int y, int color);
int draw_px(int x, int y, Pix *pix);
int draw_sq(int x, int y, int color);
int hide_cur(void);
int show_cur(void);
int load_bm(char *path, Bm *bm);
int draw_bm(Bm *bm);


#endif //GRAPHICS_H
