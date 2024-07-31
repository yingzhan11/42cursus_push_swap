

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

    len_a = info->a_n;
    //find_target_a(*a, *b, info);
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
    if (min_steps_node->is_above_med && min_steps_node->target_p <= dst_len / 2)
        rotate_both(src, dst, min_steps_node);
            //if cur and target all after median, rrr
    else if (!(min_steps_node->is_above_med) && min_steps_node->target_p > dst_len / 2)
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

5492
4694
5111

5517
4701
5109

5570