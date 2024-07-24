
#include "push_swap.h"

void sort_three_a(t_stack **a, t_info info)
{
    //find max
    info->max = find_max(*a);
    // if 0p is max, r
    if ((*a)->nbr == info->max)
        ra(a);
    // if 1p is max, rr
    else if ((*a)->next->nbr == info->max)
        rra(a);
    // compare top 2
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a);
}

void sort_three_b(t_stack **b)
{
    info->b_min = find_min(*b);
    // if 0p is min, r
    if ((*b)->nbr == info->b_min)
        rb(b);
    // if 1p is min, rr
    else if ((*b)->next->nbr == info->b_min)
        rrb(b);
    // compare top 2
    if ((*b)->nbr < (*b)->next->nbr)
        sb(b);
}