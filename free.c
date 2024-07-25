/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:53:21 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 10:53:23 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_nstr(char **str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void free_error(long *nbr, char **str)
{
    if (nbr)
        free(nbr);
    if (str)
        free_nstr(str);
    write(2, "ERROR\n", 6);
    exit(EXIT_FAILURE);
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (stack == NULL)
        return ;
    while (*stack)
    {
        tmp = (*stack)->next;
        (*stack)->nbr = 0;
        (*stack)->cur_p = 0;
        (*stack)->target_p = 0;
        free(*stack);
        (*stack) = tmp;
    }
    *stack = NULL;
}