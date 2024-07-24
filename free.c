/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:53:21 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 10:53:23 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_nstr(char **str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void free_error(int *nbr, char **str)
{
    if (nbr)
        free(nbr);
    if (str)
        free_nstr(str);
    write(2, "ERROR\n", 6);
    exit(EXIT_FAILURE);
}
