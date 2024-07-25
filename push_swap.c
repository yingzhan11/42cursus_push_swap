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

static void find_target_b(t_stack *a, t_stack *b, t_info *info)
{
    int cur;

    cur = a->nbr;
//cur > b_max
    //go to max, target_p before max
    if (cur > info->b_max)
    {
        while (b->nbr < info->b_max)
            b = b->next;
        a->target_p = b->cur_p;
    }
//cur < b_min
    //go to min, target_p after min
    else if (cur < info->b_min)
    {
        while (b->nbr > info->b_min)
            b = b->next;
        a->target_p = b->cur_p + 1;
    }
// b_min < cur < b_max
    //if sorted, find up tp down, same with last step
    //not sorted, 
        //if >, go to max, then same with next step
        //if <, find > or end, get target_p
    else
    {
        while (cur > b->nbr)
            b = b->next;
        while (cur < b->nbr && b->next && cur < b->next->nbr)
            b = b->next;
        if (!b->next)
            a->target_p = 0;
        else
            a->target_p = b->cur_p + 1;
    }
}

static void move_to_b(t_stack **a, t_stack **b, t_info *info)
{
    int len_b;
    int target_p;
    int i;

    len_b = stack_len(*b);
    if (len_b <= 1) //0, 1, 2
        pb(a, b);
    else
    {
        find_target_b(*a, *b, info);
        target_p = (*a)->target_p;
        i = target_p;
        if (0 < target_p && target_p <= (len_b / 2))
        {
            while (i-- > 0)
                rb(b);
        }
        else if ((len_b / 2) < target_p && target_p < len_b)
        {
            while (i++ < len_b)
                rrb(b);
        }
        pb(a, b);
        if (target_p == len_b)
            rb(b);
    }
}

static void find_target_a(t_stack *a, t_stack *b, t_info *info)
{
    int cur;

    cur = b->nbr;
//cur > a_max
    //go to max, target_p after max
    if (cur > info->a_max)
    {
        while (a->nbr < info->a_max)
            a = a->next;
        b->target_p = a->cur_p + 1;
    }
//cur < a_min
    //go to min, target_p befoew min
    else if (cur < info->a_min)
    {
        while (a->nbr > info->a_min)
            a = a->next;
        b->target_p = a->cur_p;
    }
// a_min < cur < a_max
    //if sorted, find up tp down, same with last step
    //not sorted, 
        //if <, go to min, then same with next step
        //if >, find < or end, get target_p
    else
    {
        while (cur < a->nbr)
            a = a->next;
        while (cur > a->nbr && a->next && cur > a->next->nbr)
            a = a->next;
        if (!a->next)
            b->target_p = 0;
        else
            b->target_p = a->cur_p + 1;
    }
}

static void move_to_a(t_stack **a, t_stack **b, t_info *info)
{
    int len_a;
    int target_p;
    int i;

    len_a = stack_len(*a);
    find_target_a(*a, *b, info);
    target_p = (*b)->target_p;
    i = target_p;
    if (0 < target_p && target_p <= (len_a / 2))
    {
        while (i-- > 0)
            ra(a);
    }
    else if ((len_a / 2) < target_p && target_p < len_a)
    {
        while (i++ < len_a)
            rra(a);
    }
    pa(b, a);
    if (target_p == len_a)
        ra(a);
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
        //info->max = find_max(*a);
        //info->min = find_min(*a);
        while (len_a > 3)
        {
            update_node(*a, *b, info);
            move_to_b(a, b, info);
            len_a--;
        }
        sort_three_a(a, info);
        while (*b)
        {
            update_node(*a, *b, info);
            move_to_a(a, b, info);
        }
        update_node(*a, *b, info);
        final_sort(a, info);
        /*
        ft_printf("%d\n", (*a)->nbr);
        ft_printf("%d\n", (*a)->next->nbr);
        ft_printf("%d\n", (*a)->next->next->nbr);
        ft_printf("%d\n", (*a)->next->next->next->nbr);
        */
    }
}
