/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:29:49 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 14:29:52 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_target_p()
{

}

void move_to_b(t_stack **a, t_stack **b)
{
    int len_b;
    int i;

    len_b = stack_len(b);
    if (len_b <= 1) //0, 1, 2
    {
        pb(b, a);
        if (len_b == 2)
            sort_three_b(b, info);
    }
    else
    {
        find_target_p(a); //TODO
        //move a to b
        i = a->target_p;
        if (0 < a->target_p && a->target_p < (len_b / 2))
        {
            while (i-- > 0)
                rb(b);
        }
        else if ((len_b / 2) < a->target_p && a->target_p < len_b)
        {
            while (i++ < len_b)
                rrb(b);
        }
        pb(a, b);
        if (a->target_p == len_b)
            rb(b);
    }
}

void push_swap(t_stack **a, t_stack **b, t_info *info)
{
    int len_a;

    if (info->total_n == 0 || info->total_n == 1)
        return ;
    else if (info->total_n == 2)
        sa(a);
    else if (info->total_n == 3)
        sort_three_a(a, info);
    else
    {
        len_a = info->total_n;
        find_max_three(a, info);
        while (len_a > 3)
        {
            if (*b)
                update_node(a, b); //TODO
            move_to_b(a, b);
            len_a--;
        }
        //len_a == 3
        sort_three(a);
        while (*b)
        {
            update_node(a, b);
            move_to_a(a, b); //TODO
        }
    }
}
