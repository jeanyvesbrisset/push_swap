/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:55:05 by jbrisset          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:10 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rev_sorted(t_stack *stack)
{
	if (!stack || !(stack->next))
		return (1);
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_rev_sort_size(t_stack *stack, int size)
{
	int i;

	i = 0;
	while (i++ < size - 1)
	{
		if (stack->next->value > stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_below(t_stack *stack, int med)
{
	while (stack)
	{
		if (stack->value < med)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_above(t_stack *stack, int med)
{
	while (stack)
	{
		if (stack->value > med)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	find_dup(t_stack *stack, int arg)
{
	while (stack)
	{
		if (stack->value == arg)
			return (1);
		stack = stack->next;
	}
	return (0);
}
