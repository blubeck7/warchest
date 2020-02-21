#include <stdio.h>
#include <stdlib.h>
#include "../inc/container.h"


struct coinqueue {
	int num;
	int size;
	int front;
	int back;
	Coin **coins; //array of pointers to the coins
};

struct gamebox {
	int size;
	CoinQueue **coinqueues;
};
	

CoinQueue *create_coinqueue(int size)
{
	CoinQueue *coinqueue;

	coinqueue = malloc(sizeof(CoinQueue));
	coinqueue->num = 0;
	coinqueue->size = size;
	coinqueue->front = 0;
	coinqueue->back = 0;
	coinqueue->coins = malloc(size * sizeof(Coin *));

	return coinqueue;
}

int destroy_coinqueue(CoinQueue *coinqueue)
{
	free(coinqueue->coins);
	free(coinqueue);

	return 0;
}

int print_coinqueue(CoinQueue *coinqueue)
{
	int i, cur;

	printf("coinqueue=%p:\n", coinqueue);
	printf("num=%d, size=%d, front=%d, back=%d\n", coinqueue->num,
			coinqueue->size, coinqueue->front, coinqueue->back);
	for (i = 0; i < coinqueue->num; i++) {
		cur = (coinqueue->front + i) % coinqueue->size;
		if (i == 0)
			printf("%p", *(coinqueue->coins + cur));
		else
			printf(",%p", *(coinqueue->coins + cur));
	}
	//TODO: change print statements to print_coin

	return 0;
}

int add_coin_to_coinqueue(CoinQueue *coinqueue, Coin *coin)
{
	if (coinqueue->num >= coinqueue->size)
		return -1;

	*(coinqueue->coins + coinqueue->back) = coin;
	coinqueue->back = (coinqueue->back + 1) % coinqueue->size;
	coinqueue->num++;

	return 0;
}

Coin *remove_coin_from_coinqueue(CoinQueue *coinqueue)
{
	Coin *coin;

	if (coinqueue->num <= 0)
		return NULL;

	coin = *(coinqueue->coins + coinqueue->front);
	coinqueue->front = (coinqueue->front + 1) % coinqueue->size;
	coinqueue->num--;

	return coin;
}

GameBox *create_gamebox(int size)
{
	GameBox *gamebox;

	gamebox = malloc(sizeof(GameBox));
	gamebox->size = size;
	gamebox->coinqueues = malloc(sizeof(CoinQueue) * size);

	return gamebox;
}


