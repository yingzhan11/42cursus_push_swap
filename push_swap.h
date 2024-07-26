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

# include "libft.h"
# include "ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>


# define ELEMENTS "+-0123456789"

typedef struct s_stack
{
    int nbr;
    int cur_p;
    int target_p;
    int move_steps;
    bool is_above_med;
    bool is_min_steps;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

typedef struct s_info
{
    int total_n;
    int a_n;
    int a_max;
    int a_min;
    int b_n;
    int b_max;
    int b_min;
} t_info;

//main.c
bool check_sort(t_stack *stack);

//check_argv.c
void check_argv(int argc, char **argv);

//op_push.c
void pa(t_stack **b, t_stack **a);
void pb(t_stack **a, t_stack **b);

//op_rev_rotate.c
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

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
void sort_three_a(t_stack **a, t_info *info);
void sort_three_b(t_stack **b, t_info *info);
void final_sort(t_stack **a, t_info *info);

//stack_update.c
void update_stack(t_stack *a, t_stack *b, t_info *info, char src_name);
void find_target_in_b(t_stack *a, t_stack *b, t_info *info);
void find_target_in_a(t_stack *b, t_stack *a, t_info *info);
void calculate_move_steps(t_stack *src, int src_len, int dst_len);
void find_min_steps(t_stack *stack);

//stack_tools.c
int find_max(t_stack *stack);
int find_min(t_stack *stack);
int stack_len(t_stack *stack);
t_stack *find_last_node(t_stack *stack);
void set_cur_position(t_stack *stack);

//tools.c
long ft_atol (const char *str);

//free.c
void free_nstr(char **str);
void free_error(long *nbr, char **str);
void free_stack(t_stack **stack);




#endif