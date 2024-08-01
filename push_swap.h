/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:12:04 by yzhan             #+#    #+#             */
/*   Updated: 2024/07/31 15:19:41 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# define NUMBERS "0123456789"
# define ELEMENTS "+-0123456789"
# define SIGNS "+-"

typedef struct s_stack
{
	int				nbr;
	int				cur_p;
	int				target_p;
	int				move_steps;
	bool			is_above_med;
	bool			is_min_steps;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_info
{
	int		total_n;
	int		a_n;
	int		a_max;
	int		a_min;
	int		b_n;
	int		b_max;
	int		b_min;
}	t_info;

//main.c
bool	check_sort(t_stack *stack);

//check_argv.c
void	check_argv(int argc, char **argv);

//stack_init.c
void	stack_init(t_stack **a, int argc, char **argv);
void	init_node(t_stack *a);

//stack_update.c
void	update_stack(t_stack *a, t_stack *b, t_info *info, char src_name);

//statck_move.c
void	move_nodes(t_stack **src, t_stack **dst, char src_name, char dst_name);

//stack_tools.c
int		stack_len(t_stack *stack);
void	set_cur_position(t_stack *stack);
t_stack	*find_last_node(t_stack *stack);
t_stack	*find_min_steps_node(t_stack *stack);

//small_sort.c
void	sort_three_a(t_stack **a, t_info *info);
void	sort_three_b(t_stack **b, t_info *info);
void	final_sort(t_stack **a, t_info *info);

//tools.c
int	count_nbr(char **str);
long	ft_atol(const char *str);
char	*ft_strchr(const char *s, int c);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);

//ft_split.c
char	**ft_split(char const *s, char c);

//free.c
void	free_nstr(char **str);
void	free_error(long *nbr, char **str);
void	free_stack(t_stack **stack);

//op_push.c
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);

//op_rev_rotate.c
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//op_rotate.c
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//op_swap.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif
