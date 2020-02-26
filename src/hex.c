#include <stdio.h>
#include <stdlib.h>
#include "../inc/ds.h"
#include "../inc/hex.h"
#include "../inc/types.h"

#define NUM_ADJ_HEXES 6

struct hex {
	int id;
	int num_adj;
	int adj[NUM_ADJ_HEXES];
	int control_space;
	int control_marker;
	int num_units;
	Queue units;
};

int add_coin_hex(Hex hex, Coin coin)
{
	return add_queue(hex->units, (Item) coin);
}
