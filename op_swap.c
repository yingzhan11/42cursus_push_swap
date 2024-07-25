/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:31:13 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 12:31:15 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **stack)
{
    int len;
    t_stack *oldhead;

    if (*stack == NULL || stack == NULL)
        return ;
    len = stack_len(*stack);
    if (len == 1)
        return ;
    oldhead = *stack;
    *stack = (*stack)->next;
    oldhead->prev = *stack;
    oldhead->next = (*stack)->next;
    if ((*stack)->next)
        (*stack)->next->prev = oldhead;
    (*stack)->next = oldhead;
    (*stack)->prev = NULL;
}

void sa(t_stack **a)
{
    swap(a);
    ft_printf("sa\n");
}

void sb(t_stack **b)
{
    swap(b);
    ft_printf("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}
