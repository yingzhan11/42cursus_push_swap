/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:12:54 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 14:15:43 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argv(int argc, char **argv)
{
	char	**str;
	int		i;
	long	*nbr;
	int		j;

	nbr = (long *)malloc((count_nbr(argv) + 1) * sizeof(long));
	if (!nbr)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	i = 1;
	j = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str || !*str)
			free_error(nbr, str);
		if (check_elements(str) == 0 || check_order(str) == 0)
			free_error(nbr, str);
		check_nbr(nbr, str, &j);
		free_nstr(str);
		i++;
	}
	free(nbr);
}

bool	check_sort(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	push_swap(t_stack **a, t_stack **b, t_info *info)
{
	if (info->total_n == 0 || info->total_n == 1)
		return ;
	else if (info->total_n <= 2)
		sa(a);
	else if (info->total_n == 3)
		sort_three_a(a, info);
	else
	{
		info->a_n = info->total_n;
		while (info->a_n > 3)
		{
			update_stack(*a, *b, info, 'a');
			move_nodes(a, b, 'a', 'b');
			info->a_n--;
		}
		sort_three_a(a, info);
		while (*b)
		{
			update_stack(*a, *b, info, 'b');
			move_nodes(b, a, 'b', 'a');
		}
		update_stack(*a, *b, info, 'f');
		if (!check_sort(*a))
			final_sort(a, info);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_info	info;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	check_argv(argc, argv);
	a = NULL;
	b = NULL;
	stack_init(&a, argc, argv);
	init_node(a);
	info.total_n = stack_len(a);
	if (!check_sort(a))
		push_swap(&a, &b, &info);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
