/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:44:12 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/02 11:30:27 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
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

t_stack	*find_target_node_in_b(t_stack *src, t_stack *cur, t_info *info)
{
	if (src->nbr > info->b_max)
		while (cur->nbr != info->b_max)
			cur = cur->next;
	else if (src->nbr < info->b_min)
		while (cur->nbr != info->b_min)
			cur = cur->next;
	else
	{
		while (src->nbr > cur->nbr)
			cur = cur->next;
		while (src->nbr < cur->nbr && cur->next && src->nbr < cur->next->nbr)
			cur = cur->next;
	}
	return (cur);
}

t_stack	*find_target_node_in_a(t_stack *src, t_stack *cur, t_info *info)
{
	if (src->nbr > info->a_max)
		while (cur->nbr != info->a_max)
			cur = cur->next;
	else if (src->nbr < info->a_min)
		while (cur->nbr != info->a_min)
			cur = cur->next;
	else
	{
		while (src->nbr < cur->nbr)
			cur = cur->next;
		while (src->nbr > cur->nbr && cur->next && src->nbr > cur->next->nbr)
			cur = cur->next;
	}
	return (cur);
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
