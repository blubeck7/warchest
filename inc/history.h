#ifndef HISTORY_H
#define HISTORY_H

#include "types.h"

History create_history(void);
int destroy_history(History history);
int add_move_history(History history, Move move);
Move remove_move_history(History history);

#endif //HISTORY_H

