/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:55:05 by jbrisset          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:10 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*previous;
	int				value;
}				t_stack;

typedef struct	s_data
{
	int	med;
	int med_low;
	int count_a;
	int count_b;
	int	first;
}				t_data;

/*
**	push_swap.c
*/

void			push_swap(t_stack **a, t_stack **b, int size);

/*
**	checker.c
*/

int				checker(t_stack **a, t_stack **b);

/*
**	stack_manager.c
*/

t_stack			*new_elem(int value);
void			free_stacks(t_stack **a, t_stack **b);
int				get_stack_size(t_stack *stack);
int				is_sorted(t_stack *nb);

/*
**	stack_a_manager.c
*/

int				handle_a(t_stack **a, t_stack **b, int size);
void			sort_a(t_stack **sta, t_stack **stb);
void			sort_three_a(t_stack **st);

/*
**	stack_b_manager.c
*/

void			handle_b(t_stack **a, t_stack **b, int size);
void			sort_b(t_stack **sta, t_stack **stb);

/*
**	operations.c
*/

void			push(t_stack **src, t_stack **dst);
void			swap(t_stack *stack);
void			rotate(t_stack **stack);
void			reverse(t_stack **stack);
void			operate(t_stack **a, t_stack **b, char *code, int print);

/*
**	verifications.c
*/

int				is_rev_sorted(t_stack *nb);
int				is_rev_sort_size(t_stack *stack, int size);
int				check_below(t_stack *stack, int med);
int				check_above(t_stack *stack, int med);
int				find_dup(t_stack *stack, int arg);

/*
**	aux_functions.c
*/

int				get_median(t_stack *h, int size, int diviser);

#endif
