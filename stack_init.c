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

static void	add_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
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
		if (!str)
		{
			free_stack(a);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (str[j])
		{
			nbr = ft_atol(str[j]);
			add_node(a, (int)nbr);
			j++;
		}
		free_nstr(str);
		i++;
	}
}

void	init_node(t_stack *a)
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
}
