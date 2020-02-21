#ifndef COIN_H
#define COIN_H

#define COIN_DOWN 0
#define COIN_UP 1

typedef struct move Move;
typedef struct hex Hex;
typedef struct game Game;
typedef struct coin Coin;
typedef Move **(*MoveFunc)(Coin *coin, Game *game);

Coin *create_coin(int type, MoveFunc movefuncs[9]);
int *destroy_coin(Coin *coin);
int print_coin(Coin *coin);
int print_coin_all(Coin *coin);

#endif //COIN_H
