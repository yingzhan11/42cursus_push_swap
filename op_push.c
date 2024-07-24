/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:14:36 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 14:14:39 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **src, t_stack **dst)
{
    t_stack *node;

    if (src == NULL)
        return ;
    node = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    node->prev = NULL;
    if (*dst == NULL)
    {
        *dst = node;
        node->next = NULL;
    }
    else
    {
        *dst->prev = node;
        node->next = *dst;
        *dst = node;
    }
}

void pa(t_stack **b, t_stack **a)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}
