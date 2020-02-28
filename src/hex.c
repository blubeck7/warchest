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

struct hex {
	int id;
	int num_adj;
	int adj[NUM_ADJ_HEXES];
	int control_space;
	Coin control_coin;
	Stack unit_coins;
};

int add_unit_coin_hex(Hex hex, Coin coin)
{
	return add_stack(hex->unit_coins, (Item) coin);
}

Coin remove_unit_coin_hex(Hex hex)
{
	return remove_stack(hex->unit_coins);
}

int has_unit_coin_hex(Hex hex, Coin coin)
{
	return same_type_coin((Coin) peak_stack(hex->unit_coins, 0), coin);
}
