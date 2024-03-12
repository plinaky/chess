#ifndef TREE_H
#define TREE_H

#define MAX_NODE (1 << 26)

struct node {
    uint32_t white, draws, visit, child;
    uint16_t move;
    uint16_t cnum;
};

extern struct node *node_map;

int open_game_map(void);
int flush_game_map(void);
void add_moves(uint32_t father, uint16_t *ml, uint16_t mc);

#endif



