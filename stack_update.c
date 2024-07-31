/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:48:24 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 16:57:22 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target_in_b(t_stack *a, t_stack *b, t_info *info)
{
	t_stack	*cur;

	while (a)
	{
		cur = b;
		while (cur)
		{
			if (a->nbr > info->b_max)
			{
				while (cur->nbr != info->b_max)
					cur = cur->next;
				a->target_p = cur->cur_p;
			}
			else if (a->nbr < info->b_min)
			{
				while (cur->nbr != info->b_min)
					cur = cur->next;
				a->target_p = cur->cur_p + 1;
			}
			else
			{
				while (a->nbr > cur->nbr)
					cur = cur->next;
				while (a->nbr < cur->nbr && cur->next && a->nbr < cur->next->nbr)
					cur = cur->next;
				if (!cur->next)
					a->target_p = 0;
				else
					a->target_p = cur->cur_p + 1;
			}
			if (a->target_p == info->b_n)
				a->target_p = 0;
			if (a->target_p >= 0)
				break ;
		}
		a = a->next;
	}
}

static void	find_target_in_a(t_stack *b, t_stack *a, t_info *info)
{
	t_stack	*cur;

	while (b)
	{
		cur = a;
		while (cur)
		{
			if (b->nbr > info->a_max)
			{
				while (cur->nbr != info->a_max)
					cur = cur->next;
				b->target_p = cur->cur_p + 1;
			}
			else if (b->nbr < info->a_min)
			{
				while (cur->nbr != info->a_min)
					cur = cur->next;
				b->target_p = cur->cur_p;
			}
			else
			{
				while (b->nbr < cur->nbr)
					cur = cur->next;
				while (b->nbr > cur->nbr && cur->next && b->nbr > cur->next->nbr)
					cur = cur->next;
				if (!cur->next)
					b->target_p = 0;
				else
					b->target_p = cur->cur_p + 1;
			}
			if (b->target_p == info->a_n)
				b->target_p = 0;
			if (b->target_p >= 0)
				break ;
		}
		b = b->next;
	}
}
/*
static void	calculate_move_steps(t_stack *src, int src_len, int dst_len)
{
	if (src == NULL)
		return ;
	while (src)
	{
		if (src->is_above_med)
		{
			if (src->target_p <= (dst_len / 2))
			{
				if (src->cur_p > src->target_p)
					src->move_steps = src->cur_p;
				else
					src->move_steps = src->target_p;
			}
			else
				src->move_steps = src->cur_p + (dst_len - src->target_p);
		}
		else
		{
			if (src->target_p <= (dst_len / 2))
				src->move_steps = (src_len - src->cur_p) + src->target_p;
			else
			{
				if ((src_len - src->cur_p) > (dst_len - src->target_p))
					src->move_steps = src_len - src->cur_p;
				else
					src->move_steps = dst_len - src->target_p;
			}
		}
		src = src->next;
	}
}*/

static void	calculate_move_steps(t_stack *src, int src_len, int dst_len)
{
	if (src == NULL)
		return ;
	while (src)
	{
		if (src->is_above_med && src->target_p <= (dst_len / 2))
		{
			if (src->cur_p > src->target_p)
				src->move_steps = src->cur_p;
			else
				src->move_steps = src->target_p;
		}
		else if (src->is_above_med && src->target_p > (dst_len / 2))
			src->move_steps = src->cur_p + (dst_len - src->target_p);
		else if (!(src->is_above_med) && src->target_p <= (dst_len / 2))
			src->move_steps = (src_len - src->cur_p) + src->target_p;
		else if (!(src->is_above_med) && src->target_p > (dst_len / 2))
		{
			if ((src_len - src->cur_p) > (dst_len - src->target_p))
				src->move_steps = src_len - src->cur_p;
			else
				src->move_steps = dst_len - src->target_p;
		}
		src = src->next;
	}
}

static void	find_min_steps(t_stack *stack)
{
	long	min_steps;
	t_stack	*min_steps_node;

	if (stack == NULL)
		return ;
	min_steps = LONG_MAX;
	while (stack)
	{
		stack->is_min_steps = false;
		if (stack->move_steps < min_steps)
		{
			min_steps = stack->move_steps;
			min_steps_node = stack;
		}
		stack = stack->next;
	}
	min_steps_node->is_min_steps = true;
}

void	update_stack(t_stack *a, t_stack *b, t_info *info, char src_name)
{
	set_cur_position(a);
	set_cur_position(b);
	info->a_n = stack_len(a);
	info->b_n = stack_len(b);
	if (src_name == 'a')
	{
		info->b_max = find_max(b);
		info->b_min = find_min(b);
		find_target_in_b(a, b, info);
		calculate_move_steps(a, info->a_n, info->b_n);
		find_min_steps(a);
	}
	else if (src_name == 'b')
	{
		info->a_max = find_max(a);
		info->a_min = find_min(a);
		find_target_in_a(b, a, info);
		calculate_move_steps(b, info->b_n, info->a_n);
		find_min_steps(b);
	}
	else if (src_name == 'f')
	{
		info->a_max = find_max(a);
		info->a_min = find_min(a);
	}
}
