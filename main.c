/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:12:54 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 09:12:57 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void add_node(t_stack **stack, int nbr)
{
    t_stack *node;
    t_stack *last;

    if (stack == NULL)
        return ;
    node = malloc(sizeof(t_stack));
    if (node == NULL)
        return ;
    node->next = NULL;
    node->nbr = nbr;
    if (*stack == NULL)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last = find_last_node(*stack);
        last->next = node;
        node->prev = last;
    }
}

static void stack_init(t_stack **a, int argc, char **argv)
{
    long nbr;
    char **str;
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        str = ft_split(argv[i], ' ');
        if (!str)
        {
            free_stack(a);
            write(2, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        j = 0;
        while (str[j])
        {
            nbr = ft_atol(str[j]); //TODO
            add_node(a, (int)nbr);
            j++;
        }
        free_nstr(str);
        i++;
    }
}

bool check_sort(t_stack *stack)
{
    if (stack == NULL)
        return (1);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_info info;

//0-check param, argc & argv
    if (argc <= 1)
        exit(EXIT_FAILURE);
    //else if (argc > 1205) ?
    check_argv(argc, argv);
//1-initailize stacks
    a = NULL;
    stack_init(&a, argc, argv);
    b = NULL;
    info.total_n = stack_len(a);
//2-sort
//check stack is sorted or not
    if (!check_sort(a))
        push_swap(&a, &b, &info);
//3-clean and return
    free_stack(&a);
    free_stack(&b);
    return (0);
}
