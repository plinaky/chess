#ifndef GAME_H
#define GAME_H


void play(struct board *bo, uint16_t (*move_select) (struct board *b, uint16_t *ml, uint8_t mc));

#endif
