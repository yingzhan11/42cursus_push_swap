#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_stack
{
    int num;
    int cur_p;
    int target_p;
    bool is_max;
    bool is_min;
    struct s_node *next;
    struct s_node *prev;
} t_stack;

