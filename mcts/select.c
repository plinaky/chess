#include "standards.h"
#include "board.h"
#include "compare.h"
#include "tree.h"

uint16_t random_select(struct board *b, uint16_t *ml, uint8_t mc)
{
	return ml[rand() % mc];
}

uint16_t mcts_select(struct board *b, uint16_t *ml, uint8_t mc)
{
	static uint32_t father = 1;
	uint32_t has = hash_pos(b);
	uint16_t move = rand() % mc;
	add_moves(father, ml, mc);
	father = node_map[father].child + move;
	return move;
}
