#ifndef GAMEBOX_H
#define GAMEBOX_H

typedef struct gamebox *Gamebox;

//#include "types.h"

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

/* run_game
 *
 * This function plays an entire game. It firsts creates a new 2 player game
 * using the game objects from the game box to setup the board and players. It
 * then plays a game. Finally it destroys the game.
 */
History run_game(GetMoveFunc movefuncs[NUM_PLAYERS], char *names[NUM_PLAYERS],
	int game_type, ListArray gamebox);

int destroy_gamebox(ListArray gamebox);

#endif //WARCHEST_H
