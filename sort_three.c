
#include "push_swap.h"

void sort_three_a(t_stack **a, t_info *info)
{
    //find max
    info->a_max = find_max(*a);
    // if 0p is max, r
    if ((*a)->nbr == info->a_max)
        ra(a);
    // if 1p is max, rr
    else if ((*a)->next->nbr == info->a_max)
        rra(a);
    // compare top 2
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a);
}

void sort_three_b(t_stack **b, t_info *info)
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

void final_sort(t_stack **a, t_info *info)
{
    int min_p;
    t_stack *min_node;
    int len_a;


    min_node = *a;
    while (min_node->nbr > info->a_min)
        min_node = min_node->next;
    min_p = min_node->cur_p;
    len_a = stack_len(*a);
    if (min_p == 0)
        return ;
    else if (min_p < (len_a / 2))
    {
        while (min_p-- > 0)
            ra(a);
    }
    else if ((len_a / 2) < min_p && min_p < len_a)
    {
        while (min_p++ < len_a)
            rra(a);
    }
}
