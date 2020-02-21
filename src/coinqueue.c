#include <stdio.h>
#include <stdlib.h>
#include "../inc/coin.h"
#include "../inc/coinqueue.h"


struct coinqueue {
	int num;
	int size;
	int front;
	int back;
	Coin **coins; //array of pointers to the coins
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
	printf("coinqueue=%p:\n", coinqueue);
	printf("num=%d, size=%d, front=%d, back=%d\n", coinqueue->num,
			coinqueue->size, coinqueue->front, coinqueue->back);

	return 0;
}

int print_coinqueue_all(CoinQueue *coinqueue)
{
	int i, cur;

	print_coinqueue(coinqueue);
	for (i = 0; i < coinqueue->num; i++) {
		cur = (coinqueue->front + i) % coinqueue->size;
		print_coin(*(coinqueue->coins + cur));
	}

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
