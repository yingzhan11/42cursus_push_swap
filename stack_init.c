/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:03:22 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 16:03:25 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last;

	if (stack == NULL)
		return (-1);
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (-1);
	node->next = NULL;
	node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last_node(*stack);
		last->next = node;
		node->prev = last;
	}
	return (0);
}

void	stack_init(t_stack **a, int argc, char **argv)
{
	long	nbr;
	char	**str;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str || !*str)
			stack_error(a, str);
		j = -1;
		while (str[++j])
		{
			nbr = ft_atol(str[j]);
			if (add_node(a, (int)nbr) == -1)
				stack_error(a, str);
		}
		free_nstr(str);
		i++;
	}
}

void	init_node(t_stack *a, t_info *info)
{
	t_stack	*cur;

	cur = a;
	while (cur)
	{
		cur->cur_p = -1;
		cur->target_p = -1;
		cur->move_steps = -1;
		cur->is_above_med = false;
		cur->is_min_steps = false;
		cur = cur->next;
	}
	info->total_n = stack_len(a);
	info->max = find_max(a);
	info->min = find_min(a);
}
