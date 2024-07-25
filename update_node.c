

#include "push_swap.h"


int find_max(t_stack *stack)
{
    int max;

    if (stack == NULL)
        return (0);
    max = INT_MIN;
    while (stack)
    {
        if (stack->nbr > max)
            max = stack->nbr;
        stack = stack->next;
    }
    return (max);
}

int find_min(t_stack *stack)
{
    int min;

    if (stack == NULL)
        return (0);
    min = INT_MAX;
    while (stack)
    {
        if (stack->nbr < min)
            min = stack->nbr;
        stack = stack->next;
    }
    return (min);
}

static void set_cur_position(t_stack *stack)
{
    int i;

    if (stack == NULL)
        return ;
    i = 0;
    while (stack)
    {
        stack->cur_p = i;
        stack = stack->next;
        i++;
    }
}

void update_node(t_stack *a, t_stack *b, t_info *info)
{
    //set current position
    set_cur_position(a);
    set_cur_position(b);
    //check n
    info->a_n = stack_len(a);
    info->b_n = stack_len(b);
    //find max & min
    info->b_max = find_max(b);
    info->b_min = find_min(b);
    info->a_max = find_max(a);
    info->a_min = find_min(a);
}