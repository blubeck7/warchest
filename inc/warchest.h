#ifndef WARCHEST_H
#define WARCHEST_H

#include "types.h"

ListArray create_gamebox(void);
int init_gamebox(ListArray gamebox);
History run_game(GetMoveFunc movefuncs[NUM_PLAYERS], char *names[NUM_PLAYERS],
	int game_type);
int destroy_gamebox(ListArray gamebox);

#endif //WARCHEST_H

