/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:02:50 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 16:04:23 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **src, t_stack **dst, t_stack *push_node)
{
	while (push_node->cur_p != 0 && push_node->target_p != 0)
	{
		rr(src, dst);
		push_node->cur_p--;
		push_node->target_p--;
	}
	set_cur_position(*src);
	set_cur_position(*dst);
}

static void	rev_rotate_both(t_stack **src, t_stack **dst, t_stack *push_node)
{
	int	src_len;
	int	dst_len;

	src_len = stack_len(*src);
	dst_len = stack_len(*dst);
	while (push_node->cur_p != 0 && push_node->target_p != 0)
	{
		rrr(src, dst);
		push_node->cur_p++;
		push_node->target_p++;
		if (push_node->cur_p == src_len)
			push_node->cur_p = 0;
		if (push_node->target_p == dst_len)
			push_node->target_p = 0;
	}
	set_cur_position(*src);
	set_cur_position(*dst);
}

static void	r_src(t_stack **src, t_stack *push_node, char src_name)
{
	int	src_len;

	src_len = stack_len(*src);
	if (src_len <= 1 || push_node->cur_p == 0)
		return ;
	while (push_node->cur_p != 0)
	{
		if (push_node->is_above_med)
		{
			if (src_name == 'a')
				ra(src);
			else if (src_name == 'b')
				rb(src);
			push_node->cur_p--;
		}
		if (!(push_node->is_above_med))
		{
			if (src_name == 'a')
				rra(src);
			else if (src_name == 'b')
				rrb(src);
			if (++push_node->cur_p >= src_len)
				push_node->cur_p = 0;
		}
	}
}

static void	r_dst(t_stack **dst, t_stack *push_node, char dst_name, int dst_len)
{
	if (dst_len <= 1 || push_node->target_p == 0)
		return ;
	while (push_node->target_p != 0)
	{
		if (push_node->target_p <= (dst_len / 2))
		{
			if (dst_name == 'a')
				ra(dst);
			if (dst_name == 'b')
				rb(dst);
			push_node->target_p--;
		}
		else if (push_node->target_p > (dst_len / 2)
			&& push_node->target_p < dst_len)
		{
			if (dst_name == 'a')
				rra(dst);
			if (dst_name == 'b')
				rrb(dst);
			push_node->target_p++;
		}
		if (push_node->target_p >= dst_len)
			push_node->target_p = 0;
	}
}

void	move_nodes(t_stack **src, t_stack **dst, char src_name, char dst_name)
{
	t_stack	*min_steps_node;
	int		dst_len;

	dst_len = stack_len(*dst);
	min_steps_node = find_min_steps_node(*src);
	if (min_steps_node->is_above_med
		&& min_steps_node->target_p <= (dst_len / 2))
		rotate_both(src, dst, min_steps_node);
	else if (!(min_steps_node->is_above_med)
		&& min_steps_node->target_p > (dst_len / 2)
		&& min_steps_node->target_p < dst_len)
		rev_rotate_both(src, dst, min_steps_node);
	r_src(src, min_steps_node, src_name);
	r_dst(dst, min_steps_node, dst_name, dst_len);
	if (dst_name == 'a')
		pa(src, dst);
	else if (dst_name == 'b')
		pb(src, dst);
}
