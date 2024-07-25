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

t_stack *find_last_node(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next != NULL)
        stack = stack->next;
    return (stack);
}

long ft_atol (const char *str)
{
    long nbr;
    int is_neg;
    int i;

    nbr = 0;
    is_neg = 1;
    i = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
                        || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        is_neg *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = (nbr * 10) + (str[i] - '0');
        i++;
    }
    return (nbr * is_neg);
}