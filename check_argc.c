/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:06:17 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 11:06:19 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_nbr(char ***str)
{
    char **tmp;
    int count;
    int i;
    int j;

    count = 0;
    i = 1;
    while (str[i])
    {
        tmp = ft_split(str[i], ' ');
        if (!tmp)
        {
            ft_printf("Error: fail to split argv\n");
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

static int check_str(char **str)
{
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if (!ft_strchr(ELEMENTS, str[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

static int check_repeat(long *nbr, int j)
{
    int i;
    int check_nbr;

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

static void check_nbr(long *nbr, char **str)
{
    int i;
    int j;

    j = 0;
    while (nbr[j])
        j++;
    i = 0;
    while (str[i])
    {
        nbr[j] = ft_atol(str[i]); //TODO
        if (nbr[j] < INE_MIN || nbr[j] > INT_MAX)
            free_error(nbr, str);
        if (check_repeat(nbr, j) == 0);
            free_error(nbr, str);
        j++;
        i++;
    }
}

void check_argv(int argc, char **argv)
{
    char **str;
    int i;
    long *nbr;

    nbr = (long *)malloc((count_nbr(argv) + 1) * sizeof(long));
    if (!nbr)
    {
        write(2, "ERROR\n", 6);
        exit(EXIT_FAILURE);
    }
    i = 1;
    while (i < argc)
    {
        str = ft_split(argv[i], ' ');
        if (!str)
            free_error(nbr, str);
    //check str element, all nub and +-
        if (check_str(str) == 0)
            free_error(nbr, str);
    //convert str to nbr
        //check nbr, INT_MAX, INT_MIN, repeat
        check_nbr(nbr, str);
        free_nstr(str);
        i++;
    }
    free(nbr);
}
