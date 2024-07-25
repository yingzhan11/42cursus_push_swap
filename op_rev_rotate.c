/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:14:24 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 14:14:26 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate(t_stack **stack)
{
    int len;
    t_stack *newhead;

    if (*stack == NULL || stack == NULL)
        return ;
    len = stack_len(*stack);
    if (len == 1)
        return ;
    newhead = find_last_node(*stack);
    newhead->prev->next = NULL;
    newhead->next = *stack;
    newhead->prev = NULL;
    (*stack)->prev = newhead;
    *stack = newhead;
}

void rra(t_stack **a)
{
    rev_rotate(a);
    ft_printf("rra\n");
}

void rrb(t_stack **b)
{
    rev_rotate(b);
    ft_printf("rrb\n");
}

void rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
    ft_printf("rrr\n");
}
