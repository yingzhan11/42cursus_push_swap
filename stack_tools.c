/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:44:12 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 14:48:12 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	set_cur_position(t_stack *stack)
{
	int	i;
	int	median;

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

t_stack	*find_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*find_min_steps_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->is_min_steps)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/*void reset_stack(t_stack *b)
{
    set_cur_position(b);
    while (b)
    {
        b->target_p = 0;
        b->move_steps = 0;
        b->is_min_steps = false;
        b = b->next;
    }
}*/
