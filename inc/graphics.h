#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include "window.h"

typedef struct bitmap {
	int width; //the width in pixels of the bitmap
	int height; //the height in pixels of the bitmap 
	Pix *pix_arr; //the pixel array
	uint8_t *ind; //indicator array 0 = don't display the pixel
} Bitmap;

int load_bitmap(Bitmap *bitmap, char *path);
int draw_bitmap(Bitmap *bitmap, Win *win, Pos *pos);
int set_ind(Bitmap *bitmap, Pix *ind);

#endif //GRAPHICS_H
