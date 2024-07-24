/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:12:04 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/24 09:12:08 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define ELEMENTS "+-0123456789"

typedef struct s_stack
{
    int nbr;
    int cur_p;
    int target_p;
    struct s_node *next;
    struct s_node *prev;
} t_stack;

typedef struct s_info
{
    int total_n;
    int max;
    int min;
    int a_n;
    int a_max;
    int a_min;
    int b_n;
    int b_max;
    int b_min;
} t_info;

//check_argv.c
void check_argv(int argc, char **argv);

//op_push.c
void pa(t_stack **b, t_stack **a);
void pb(t_stack **a, t_stack **b);

//op_rev_rotate.c
void rra(t_stack **a);
void rrb(t_stack **b);
void rr(t_stack **a, t_stack **b);

//op_rotate.c
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);

//op_swap.c
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);

//push_swap.c
void push_swap(t_stack **a, t_stack **b, t_info *info);

//sort_three.c
void sort_three_a(t_stack **a, t_info info);
void sort_three_b(t_stack **b);

//tools.c
int stack_len(t_stack *stack);
t_stack *find_last(t_stack *stack);

//free.c
void free_nstr(char **str);
void free_error(int *nbr, char **str);




#endif