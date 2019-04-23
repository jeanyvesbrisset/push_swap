/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:55:05 by jbrisset          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:10 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, int size)
{
	int	count_a;
	int	count_b;

	if (size == 1 || size == 0 || is_sorted(*a))
		return ;
	if (size == 2)
	{
		if (*b && (*b)->next && (*b)->value < (*b)->next->value)
			return (operate(a, b, "ss", 1));
		return (operate(a, b, "sa", 1));
	}
	if (size == 3)
		return (sort_a(a, b));
	count_a = handle_a(a, b, size);
	push_swap(a, b, count_a);
	count_b = size - count_a;
	handle_b(a, b, count_b);
}

int		main(int argc, char **argv)
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
	push_swap(&a, &b, get_stack_size(a));
	free_stacks(&a, &b);
	return (0);
}
