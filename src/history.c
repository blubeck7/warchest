#include <stdio.h>
#include <stdlib.h>
#include "../inc/ds.h"
#include "../inc/history.h"
#include "../inc/types.h"

struct history {
	int cur_move;
	Stack moves;
};

History create_history(void)
{
	History history;

	history = malloc(sizeof(struct history));
	history->cur_move = 0;
	history->moves = create_stack(MAX_MOVES);

	return history;
}

