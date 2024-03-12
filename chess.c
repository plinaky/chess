#include "standards.h"
#include "board.h"
#include "game.h"
#include "select.h"
#include "tree.h"

int main(void)
{
	struct board b1, b2;

	printf("board %lu \n", sizeof(struct board));
	printf("node %lu \n", sizeof(struct node));

	srand(time(NULL));   // Initialization, should only be called once.
	init_board(&b2, pref);

	for (uint32_t i = 1; i <= 100000; i++) {
		memcpy(&b1, &b2, sizeof(struct board));
		printf("\n\ngame %3d : ", i);
		play(&b1, mcts_select);
		printf("move usage : %d%% \n", (100 * node_map->child) / MAX_NODE);
	}

	printf("\n");

	return 0;
}
