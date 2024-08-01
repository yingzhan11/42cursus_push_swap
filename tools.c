/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:29:55 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 15:14:00 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nbr(char **str)
{
	char	**tmp;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 1;
	while (str[i])
	{
		tmp = ft_split(str[i], ' ');
		if (!tmp || !*tmp)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (tmp[j])
		{
			count++;
			j++;
		}
		free_nstr(tmp);
		i++;
	}
	return (count);
}

long	ft_atol(const char *str)
{
	long	nbr;
	int		is_neg;
	int		i;

	nbr = 0;
	is_neg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * is_neg);
}

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	int		i;

	chr = c;
	i = 0;
	while (s[i] != 0 && s[i] != chr)
		i++;
	if (s[i] == chr)
		return ((char *)(s + i));
	return (NULL);
}

int	find_max(t_stack *stack)
{
	int	max;

	if (stack == NULL)
		return (0);
	max = INT_MIN;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;

	if (stack == NULL)
		return (0);
	min = INT_MAX;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}
