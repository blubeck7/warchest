#include <stdio.h>
#include <stdlib.h>
#include "../inc/coin.h"
#include "../inc/ds.h"
#include "../inc/game.h"
#include "../inc/hex.h"
#include "../inc/history.h"
#include "../inc/move.h"
#include "../inc/player.h"
#include "../inc/types.h"

struct history {
	Stack moves;
	int id;
	int num_adj;
	int adj[NUM_ADJ_HEXES];
	int control_space;
	int control_marker;
	int num_units;
	Queue units;
};
