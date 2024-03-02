#include "standards.h"
#include "board.h"
#include "compare.h"

uint16_t random_select(struct board *b, uint16_t *ml, uint8_t mc)
{
	return (*ml + rand()) % mc;
}

uint16_t mcts_select(struct board *b, uint16_t *ml, uint8_t mc)
{
	uint32_t has = hash_pos(b);
}
