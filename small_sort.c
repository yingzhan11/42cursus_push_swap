/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:41:01 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 14:43:35 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stack **a, t_info *info)
{
	info->a_max = find_max(*a);
	if ((*a)->nbr == info->a_max)
		ra(a);
	else if ((*a)->next->nbr == info->a_max)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	small_sort(t_stack **a, t_info *info)
{
	if (info->total_n == 0 || info->total_n == 1)
		return ;
	else if (info->total_n <= 2)
		sa(a);
	else if (info->total_n == 3)
		sort_three_a(a, info);
}

void	sort_three_b(t_stack **b, t_info *info)
{
	info->b_min = find_min(*b);
	if ((*b)->nbr == info->b_min)
		rb(b);
	else if ((*b)->next->nbr == info->b_min)
		rrb(b);
	if ((*b)->nbr < (*b)->next->nbr)
		sb(b);
}

void	final_sort(t_stack **a, t_info *info)
{
	int		min_p;
	t_stack	*min_node;
	int		len_a;

	if (check_sort(*a))
		return ;
	min_node = *a;
	while (min_node->nbr > info->a_min)
		min_node = min_node->next;
	min_p = min_node->cur_p;
	len_a = stack_len(*a);
	if (min_p <= (len_a / 2))
	{
		while (min_p-- > 0)
			ra(a);
	}
	else if ((len_a / 2) < min_p && min_p < len_a)
	{
		while (min_p++ < len_a)
			rra(a);
	}
}
