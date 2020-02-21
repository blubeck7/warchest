#include <stdio.h>
#include "../inc/coin.h"
#include "../inc/coinqueue.h"

int main(int argc, char *argv[])
{
	//CoinQueue *coinqueue;
	Coin *coins[4];
	MoveFunc movefuncs[9];
	int i;

	for (i = 0; i < 9; i++)
		movefuncs[i] = NULL;

	for (i = 0; i < 4; i++)
		coins[i] = create_coin(i, movefuncs);

	print_coin(coins[0]);

	/*coinqueue = create_coinqueue(20);*/
	/*print_coinqueue(coinqueue);*/
	/*add_coin_to_coinqueue(coinqueue, coin1);*/
	/*add_coin_to_coinqueue(coinqueue, coin2);*/
	/*add_coin_to_coinqueue(coinqueue, coin3);*/
	/*add_coin_to_coinqueue(coinqueue, coin4);*/
	/*print_coinqueue(coinqueue);*/
	/*remove_coin_from_coinqueue(coinqueue);*/
	/*print_coinqueue_all(coinqueue);*/
	/*destroy_coinqueue(coinqueue);*/

	return 0;
}
