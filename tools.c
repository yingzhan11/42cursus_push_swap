/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:29:55 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 14:29:58 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"



long ft_atol (const char *str)
{
    long nbr;
    int is_neg;
    int i;

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