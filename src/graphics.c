/* TODO: Functions to handle reading bitmaps and plaing them into structures
 * TODO: Layers data structure for drawing
 * TODO: Logical grid/screen to actual rows and columns and pixels
 * TODO: Change file to be just xterm primitives
 */
#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/graphics.h"
#include "../inc/window.h"

int load_bitmap(Bitmap *bitmap, char *path)
{
	/* See wikipedia for bitmap file format. This is hardcoded for to parse a
	 * bitmap with a header name of BITMAPINFOHEADER.
	 */
	FILE *file;
	int pix_addr, size, row_size, i, j, width, height, n;
	uint8_t b, g, r;
	Pix *pix;
	uint8_t *ind;


	file = fopen(path, "r");

	fseek(file, 0x12, SEEK_SET); //bitmap width and height
	fread(&width, 4, 1, file);
	fread(&height, 4, 1, file);
	bitmap->width = width;
	bitmap->height = height;
	printf("bitmap: width=%d, height=%d\n", width, height);

	bitmap->pix_arr = malloc(width * height * sizeof(Pix));
	bitmap->ind = malloc(width * height * sizeof(uint8_t));

	/*load the bitmap pixel array into the bitmap data structure */
	row_size = 4 * (int) ceil((24.0 * (double) bitmap->width) / 32.0);
	printf("row size=%d\n", row_size);

	fseek(file, 0x22, SEEK_SET); //the size of the pixel array in bytes
	fread(&size, 4, 1, file);
	printf("size=%d\n", size);

	fseek(file, 0x0A, SEEK_SET); //the starting address of the pixels
	fread(&pix_addr, 4, 1, file);
	fseek(file, pix_addr, SEEK_SET); //goto the pixel array
	printf("pix address=%d\n", pix_addr);

	n = 0;
	for (i = height - 1; i >= 0; i--) {
		for (j = 0; j <= width - 1; j++) {
			/* read in a pixel blue, green, red */
			fread(&b, 1, 1, file);
			fread(&g, 1, 1, file);
			fread(&r, 1, 1, file);
			pix = bitmap->pix_arr + i * width + j;
			pix->r = r;
			pix->g = g;
			pix->b = b;
			ind = bitmap->ind + i * bitmap->width + j;
			*ind = 1;
		}
		fseek(file, pix_addr + row_size * ++n, SEEK_SET); //goto the next row
	}

	fclose(file);

	return 0;
}

int draw_bitmap(Bitmap *bitmap, Win *win, Pos *pos)
{
	int i, j; 
	Pos px_pos;
	Pix *pix;
	uint8_t *ind;

	for (i = 0; i < bitmap->height; i++) {
		for (j = 0; j < bitmap->width; j++) {
			pix = bitmap->pix_arr + i * bitmap->width + j;
			ind = bitmap->ind + i * bitmap->width + j;
			px_pos.x = pos->x + j;
			px_pos.y = pos->y + i;
			if (*ind)
				draw(win, &px_pos, pix);
		}
	}

	return 0;
}

int set_ind(Bitmap *bitmap, Pix *ind)
{
	int i, j; 
	Pix *pix;
	uint8_t *temp;

	for (i = 0; i < bitmap->height; i++) {
		for (j = 0; j < bitmap->width; j++) {
			pix = bitmap->pix_arr + i * bitmap->width + j;
			temp = bitmap->ind + i * bitmap->width + j;
			if (pix->r == ind->r && pix->g == ind->g && pix->b == ind->b)
				*temp = 0;
		}
	}

	return 0;
}
