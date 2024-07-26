#include "push_swap.h"

int stack_len(t_stack *stack)
{
    int count;

    if (stack == NULL)
        return (0);
    count = 0;
    while(stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

t_stack *find_last_node(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next != NULL)
        stack = stack->next;
    return (stack);
}

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

void set_cur_position(t_stack *stack)
{
    int i;
    int median;

    if (stack == NULL)
        return ;
    i = 0;
    median = stack_len(stack) / 2;
    while (stack)
    {
        stack->cur_p = i;
        if (i <= median)
            stack->is_above_med = true;
        else
            stack->is_above_med = false;
        stack = stack->next;
        i++;
    }
}