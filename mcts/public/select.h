#ifndef SELECT_H
#define SELECT_H

struct move_interface {
    uint16_t    (*select)(void);
    uint16_t    (*set_result)(void);
    struct board *b;
    uint32_t      node_offset;
    uint16_t      move;
    uint16_t     *move_list;
    uint8_t       move_count;
};

uint16_t random_select();
uint16_t mcts_select();

#endif
