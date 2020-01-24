#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include "window.h"

#define MAX_NUM_BITMAPS 50
#define MAX_NUM_LAYERS 10

typedef struct bitmap {
	int width; //the width in pixels of the bitmap
	int height; //the height in pixels of the bitmap 
	Pix *pix_arr; //the pixel array
	uint8_t *ind; //indicator array 0 = don't display the pixel
} Bitmap;

typedef struct layer {
	Bitmap *bitmaps[MAX_NUM_BITMAPS];
	Pos rpos[MAX_NUM_BITMAPS];
} Layer;

typedef struct layers {
	Layer *layers[MAX_NUM_LAYERS];
	Pos rpos[MAX_NUM_LAYERS];
} Layers;

int load_bitmap(Bitmap *bitmap, char *path);
int draw_bitmap(Bitmap *bitmap, Win *win, Pos *pos);
int set_ind(Bitmap *bitmap, Pix *ind);

int init_layer(Layer *layer);
int add_bitmap(Layer *layer, Bitmap *bitmap, Pos *pos);
int remove_bitmap(Layer *layer, Bitmap *bitmap);
int draw_layer(Layer *layer, Win *win, Pos *off);

int init_layers(Layers *layers);
int add_layer(Layers *layers, Layer *layer, int n);
int set_layer_pos(Layers *layers, int n, Pos *pos);
Layer *get_layer(Layers *layers, int n);
int remove_layer(Layers *layers, int n); 
int draw_layers(Layers *layers, Win *win, Pos *off);

#endif //GRAPHICS_H
