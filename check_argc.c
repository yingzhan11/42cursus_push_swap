/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:06:17 by yzhan             #+#    #+#             */
/*   Updated: 2024/08/14 10:02:02 by yzhan            ###   ########.fr       */
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
			free_nstr(tmp);
			exit(EXIT_FAILURE);
		}
		j = -1;
		while (tmp[++j])
			count++;
		free_nstr(tmp);
		i++;
	}
	return (count);
}

int	check_elements(char **str)
{
	int	i;
	int	j;
	int	has_nbr;
	int	signs;

	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			has_nbr = 0;
			signs = 0;
			if (!ft_strchr(ELEMENTS, str[i][j]))
				return (0);
			if (ft_strchr(NUMBERS, str[i][j]))
				has_nbr = 1;
			if (ft_strchr(SIGNS, str[i][j]))
				signs += 1;
			j++;
		}
		if (has_nbr == 0 || signs > 1)
			return (0);
	}
	return (1);
}

int	check_order(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (ft_strchr(SIGNS, str[i][j]))
			j++;
		while (str[i][j] && ft_strchr(NUMBERS, str[i][j]))
			j++;
		if (str[i][j] && ft_strchr(SIGNS, str[i][j]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_repeat(long *nbr, int j)
{
	int	i;
	int	check_nbr;

	check_nbr = nbr[j];
	i = 0;
	while (i < j)
	{
		if (nbr[i] == check_nbr)
			return (0);
		i++;
	}
	return (1);
}

void	check_nbr(long *nbr, char **str, int *j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		nbr[*j] = ft_atol(str[i]);
		if (nbr[*j] < INT_MIN || nbr[*j] > INT_MAX)
			free_error(nbr, str);
		if (check_repeat(nbr, (*j)) == 0)
			free_error(nbr, str);
		(*j)++;
		i++;
	}
}
