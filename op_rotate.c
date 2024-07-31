/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:51:47 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 14:23:26 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	int		len;
	t_stack	*newlast;
	t_stack	*oldlast;

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

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
