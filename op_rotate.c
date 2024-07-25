/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:51:47 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 13:51:48 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
{
    int len;
    t_stack *newlast;
    t_stack *oldlast;

    if (*stack == NULL || stack == NULL)
        return ;
    len = stack_len(*stack);
    if (len == 1)
        return ;
    
    oldlast = find_last_node(*stack);
    newlast = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    oldlast->next = newlast;
    newlast->prev = oldlast;
    newlast->next = NULL;
}

void ra(t_stack **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void rb(t_stack **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}