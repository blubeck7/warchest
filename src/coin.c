#include <stdio.h>
#include <stdlib.h>
#include "../inc/coin.h"


struct coin {
	int type;
	Hex *hex;
	int side; //up or down
	MoveFunc deploy;
	MoveFunc bolster;
	MoveFunc claim;
	MoveFunc recruit;
	MoveFunc pass;
	MoveFunc move;
	MoveFunc control;
	MoveFunc attack;
	MoveFunc tactic;
};


Coin *create_coin(int type, MoveFunc movefuncs[9])
{
	Coin *coin;

	coin = malloc(sizeof(Coin));
	coin->type = type;
	coin->hex = NULL;
	coin->side = COIN_DOWN;
	coin->deploy = movefuncs[0];
	coin->bolster = movefuncs[1];
	coin->claim = movefuncs[2];
	coin->recruit = movefuncs[3];
	coin->pass = movefuncs[4];
	coin->move = movefuncs[5];
	coin->control = movefuncs[6];
	coin->attack = movefuncs[7];
	coin->tactic = movefuncs[8];

	return coin;
}

int *destroy_coin(Coin *coin)
{
	free(coin);

	return 0;
}

int print_coin(Coin *coin)
{
	printf("coin=%p:\n", coin);
	printf("type=%d, hex=%p, side=%d\n", coin->type, coin->hex, coin->side);

	return 0;
}
