#include <stdio.h>
#include <stdlib.h>
#include "../inc/ds.h"
#include "../inc/history.h"
#include "../inc/types.h"

struct history {
	int num_moves;
	Stack moves;
};

History create_history(void)
{
	History history;

	history = malloc(sizeof(struct history));
	history->num_moves = 0;
	history->moves = create_stack(MAX_MOVES);

	return history;
}

int destroy_history(History history)
{
	destroy_stack(history->moves);
	free(history);

	return 0;
}

int add_move_history(History history, Move move)
{
	add_stack(history->moves, (Item) move);
	history->num_moves++;

	return 0;
}

Move remove_move_history(History history)
{
	Move move;

	move = (Move) remove_stack(history->moves);
	history->num_moves--;

	return move;
}
