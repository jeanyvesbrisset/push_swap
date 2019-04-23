/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:55:05 by jbrisset          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:10 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_operator(char *op)
{
	if (!ft_strcmp("pa", op) || !ft_strcmp("pb", op) ||
		!ft_strcmp("sa", op) || !ft_strcmp("sb", op) ||
		!ft_strcmp("ss", op) || !ft_strcmp("ra", op) ||
		!ft_strcmp("rb", op) || !ft_strcmp("rr", op) ||
		!ft_strcmp("rra", op) || !ft_strcmp("rrb", op) ||
		!ft_strcmp("rr", op))
		return (1);
	else
		return (0);
}

int			checker(t_stack **a, t_stack **b)
{
	char *op;

	op = ft_strdup("");
	while (get_next_line(0, &op))
	{
		if (is_operator(op))
			operate(a, b, op, 0);
		else if (!op[0])
			break ;
		else
		{
			free(op);
			return (write(2, "Error\n", 6));
		}
	}
	free(op);
	if (is_sorted(*a))
		return (ft_printf("OK\n"));
	else
		return (ft_printf("KO\n"));
}

int			main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	long long	arg;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	while (argc > 1)
	{
		arg = ft_atoi(argv[argc - 1]);
		if (!ft_is_nb(argv[argc - 1]) || arg < INT32_MIN || arg > INT32_MAX ||
			find_dup(a, arg))
		{
			free_stacks(&a, &b);
			return (write(2, "Error\n", 6));
		}
		b = new_elem(arg);
		push(&b, &a);
		argc--;
	}
	checker(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
