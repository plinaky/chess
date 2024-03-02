#ifndef COMPARE_H
#define COMPARE_H

void flip(struct board *b);
bool mirror(struct board *b);
bool rotate(struct board *b, bool clock);
uint32_t hash_pos(struct board *bo);

#endif
