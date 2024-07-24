/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:29:55 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 14:29:58 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

t_stack *find_last(t_stack *stack)
{
    if (stack == NULL)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}
