#ifndef COINQUEUE_H
#define COINQUEUE_H


typedef struct coin Coin;
typedef struct coinqueue CoinQueue;

CoinQueue *create_coinqueue(int size);
int destroy_coinqueue(CoinQueue *coinqueue);
int print_coinqueue(CoinQueue *coinqueue);
int print_coinqueue_all(CoinQueue *coinqueue);
int add_coin_to_coinqueue(CoinQueue *coinqueue, Coin *coin);
Coin *remove_coin_from_coinqueue(CoinQueue *coinqueue);

#endif //CONTAINER_H
