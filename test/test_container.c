#include <stdio.h>
#include "../inc/coinqueue.h"

int main(int argc, char *argv[])
{
	CoinQueue *coinqueue;
	Coin *coin1, *coin2, *coin3, *coin4;

	coinqueue = create_coinqueue(20);
	print_coinqueue(coinqueue);
	add_coin_to_coinqueue(coinqueue, coin1);
	add_coin_to_coinqueue(coinqueue, coin2);
	add_coin_to_coinqueue(coinqueue, coin3);
	add_coin_to_coinqueue(coinqueue, coin4);
	print_coinqueue(coinqueue);
	remove_coin_from_coinqueue(coinqueue);
	print_coinqueue_all(coinqueue);
	destroy_coinqueue(coinqueue);

	return 0;
}

