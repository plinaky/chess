#ifndef SELECT_H
#define SELECT_H

uint16_t random_select(struct board *b, uint16_t *ml, uint8_t mc);
uint16_t mcts_select(struct board *b, uint16_t *ml, uint8_t mc);

#endif
