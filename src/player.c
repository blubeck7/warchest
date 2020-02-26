#include <stdio.h>
#include <stdlib.h>
#include "../inc/ds.h"
#include "../inc/player.h"
#include "../inc/types.h"

struct player {
	//char *name;
	//int color;
	//int control_coin;
	//int control_markers;
	//int num_types;
	//Unit units[MAX_TYPE_UNITS];
	//int num_supply;
	//int supply[MAX_NUM_UNITS];
	//int num_bag;
	//int bag[MAX_NUM_UNITS];
	//int num_hand;
	List hand;
	//int num_deployed;
	//Deployed deployed[MAX_NUM_UNITS]; 
	//int num_discarded;
	//Discard discarded[MAX_NUM_UNITS];
	//int num_removed;
	//int removed[MAX_NUM_UNITS];
	//GetMoveFunc get_move;
};

int remove_coin_hand_player(Player player, Coin coin)
{
	if (remove_list(player->hand, (Item) coin) == NULL)
		return -1;

	return 0;
}

