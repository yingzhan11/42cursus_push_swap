

#include "push_swap.h"

void update_node(t_stack **a, t_stack **b)
{
    //set current position
    set_cur_position(a);
    set_cur_posirion(b);
    find_max(b);
    find_min();
}