#include "standards.h"
#include "board.h"
#include "mapper.h"
#include "tree.h"
#include "move.h"
#include "compare.h"

struct node *node_map = NULL;

static const char node_map_file[]  = "./data/nodes";

int open_game_map(void)
{
	static bool init_done = false;

	if (init_done)
		return EXIT_SUCCESS;

	node_map = (struct node *)open_map(node_map_file, MAX_NODE * sizeof(struct node));
	node_map->cnum  = 1;
	node_map->child = 1;
	(node_map + 1)->cnum  = 0;
	(node_map + 1)->child = 2;

	if (NULL == node_map) {
		printf("failed to open game map\n");
		exit(1);
	}

	init_done = true; 

	return EXIT_SUCCESS;
}

int flush_game_map(void)
{
	return flush_map(node_map, MAX_NODE * sizeof(struct node));
}

void add_moves(uint32_t father_offset, uint16_t *ml, uint16_t mc)
{
	uint32_t start;
	uint32_t i;

	open_game_map();
	start = node_map->child;

	for (i = 0; (i < mc) && ((start + i) < (MAX_NODE - 1)); i++) {
		struct node *n = node_map + start + i;
		n->white = 0;
		n->draws = 0;
		n->visit = 0;
		n->child = 0;
		n->move  = ml[i];
		n->child = 0;
	}
	node_map->child += i;
	(node_map + father_offset)->child = start;

	if ((MAX_NODE - 1) <= node_map->child) {
		flush_game_map();
		printf("map full\n");
		exit(1);
	}
}
