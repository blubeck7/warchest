#ifndef WARCHEST_H
#define WARCHEST_H

#include "types.h"

QueueArray create_gamebox(void);
int init_gamebox(QueueArray gamebox);
History run_game(GetMoveFunc movefuncs[NUM_PLAYERS], char *names[NUM_PLAYERS],
	int game_type);

#endif //WARCHEST_H

