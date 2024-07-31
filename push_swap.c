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

t_stack *find_min_steps_node(t_stack *stack)
{
    if (stack == NULL)
        return (NULL);
    while (stack)
    {
        if (stack->is_min_steps)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void rotate_both(t_stack **src, t_stack **dst, t_stack *push_node)
{
    while (push_node->cur_p != 0 && push_node->target_p != 0)
    {
        rr(src, dst);
        push_node->cur_p--;
        push_node->target_p--;
    }
    set_cur_position(*src);
    set_cur_position(*dst);
}

void rev_rotate_both(t_stack **src, t_stack **dst, t_stack *push_node)
{
    int src_len;
    int dst_len;

    src_len = stack_len(*src);
    dst_len = stack_len(*dst);
    while (push_node->cur_p != 0 && push_node->target_p != 0)
    {
        rrr(src, dst);
        push_node->cur_p++;
        push_node->target_p++;
        if (push_node->cur_p == src_len)
            push_node->cur_p = 0;
        if (push_node->target_p == dst_len)
            push_node->target_p = 0;
    }
    set_cur_position(*src);
    set_cur_position(*dst);
}

void pre_rotation_src(t_stack **src, t_stack *push_node, char src_name)
{
    int len;

    len = stack_len(*src);
    if (len <= 1 || push_node->cur_p == 0)
        return ;
    while (push_node->cur_p != 0)
    {
        if (push_node->is_above_med)
        {
            if (src_name == 'a')
                ra(src);
            else if (src_name == 'b')
                rb(src);
            push_node->cur_p--;
        }
        if (!(push_node->is_above_med))
        {
            if (src_name == 'a')
                rra(src);
            else if (src_name == 'b')
                rrb(src);
            push_node->cur_p++;
            if (push_node->cur_p >= len)
                push_node->cur_p = 0;
        }
    }
}

void pre_rotation_dst(t_stack **dst, t_stack *push_node, char dst_name)
{
    int len;

    len = stack_len(*dst);
    if (len <= 1 || push_node->target_p == 0)
        return ;
    while (push_node->target_p != 0)
    {
        if (push_node->target_p <= (len / 2))
        {
            if (dst_name == 'a')
                ra(dst);
            if (dst_name == 'b')
                rb(dst);
            push_node->target_p--;
        }
        else if (push_node->target_p > (len / 2) && push_node->target_p < len)
        {
            if (dst_name == 'a')
                rra(dst);
            if (dst_name == 'b')
                rrb(dst);
            push_node->target_p++;
        }
        if (push_node->target_p >= len)
            push_node->target_p = 0;
    }
}

void move_nodes(t_stack **src, t_stack **dst, char src_name, char dst_name)
{
    t_stack *min_steps_node;
    int dst_len;

    dst_len = stack_len(*dst);
//pre work
//find the node to be pushed
    min_steps_node = find_min_steps_node(*src);
//pre rotate
    //if cur and target all above median, rr
    if (min_steps_node->is_above_med && min_steps_node->target_p <= (dst_len / 2))
        rotate_both(src, dst, min_steps_node);
            //if cur and target all after median, rrr
    else if (!(min_steps_node->is_above_med) && min_steps_node->target_p > (dst_len / 2) && min_steps_node->target_p < dst_len)
        rev_rotate_both(src, dst, min_steps_node);
        //else, r or rr each
    pre_rotation_src(src, min_steps_node, src_name);
    pre_rotation_dst(dst, min_steps_node, dst_name);

//push
    if (dst_name == 'a')
        pa(src, dst);
    else if (dst_name == 'b')
        pb(src, dst);
}

/*void reset_stack(t_stack *b)
{
    set_cur_position(b);
    while (b)
    {
        b->target_p = 0;
        b->move_steps = 0;
        b->is_min_steps = false;
        b = b->next;
    }
}*/

void push_swap(t_stack **a, t_stack **b, t_info *info)
{
    int len_a;
//tiny sort, < 6
    if (info->total_n == 0 || info->total_n == 1)
        return ;
    else if (info->total_n == 2)
        sa(a);
    else if (info->total_n == 3)
        sort_three_a(a, info);
//sort > 6
    else
    {
        len_a = info->total_n;
    //move node from a to b
        while (len_a > 3)
        {
            update_stack(*a, *b, info, 'a');
            move_nodes(a, b, 'a', 'b');
            len_a--;
        }
        
    //sort reminder three nbr in a
        sort_three_a(a, info);
        //reset_stack(*b);
    //move node back from b to a    
        while (*b)
        {
            update_stack(*a, *b, info, 'b');
            move_nodes(b, a, 'b', 'a');
        }
    //final sort a
        update_stack(*a, *b, info, 'f');
        final_sort(a, info);
    }
}
