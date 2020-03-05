#ifndef WARCHEST_H
#define WARCHEST_H

#include "types.h"

/* create_gamebox
 * 
 * This function allocates the space for the gamebox, which is the entity that
 * contains all of the original references to the various game objects.
 */
ListArray create_gamebox(void);

/* init_gamebox
 *
 * This function creates the game objects and fills the gamebox with the game
 * objects.
 */
int init_gamebox(ListArray gamebox);

History run_game(GetMoveFunc movefuncs[NUM_PLAYERS], char *names[NUM_PLAYERS],
	int game_type);
int destroy_gamebox(ListArray gamebox);

#endif //WARCHEST_H
