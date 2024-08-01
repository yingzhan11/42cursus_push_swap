/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:06:17 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 14:06:39 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	check_elements(char **str)
{
	int	i;
	int	j;
	int	has_nbr;
	int signs;

	i = -1;
	has_nbr = 0;
	signs = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
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

static int check_order(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (ft_strchr(SIGNS, str[i][j]))
			j++;
		while (ft_strchr(NUMBERS, str[i][j]))
			j++;
		if (ft_strchr(SIGNS, str[i][j]))
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

static void	check_nbr(long *nbr, char **str, int *j)
{
	int	i;

	while (nbr[*j])
		(*j)++;
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

void	check_argv(int argc, char **argv)
{
	char	**str;
	int		i;
	long	*nbr;
	int j;

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
