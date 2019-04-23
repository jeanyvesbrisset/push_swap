/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:55:05 by jbrisset          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:10 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*new_elem(int value)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

static void	free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void		free_stacks(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

int			get_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int			is_sorted(t_stack *stack)
{
	t_stack	*next;

	if (!stack || !(stack->next))
		return (1);
	next = stack->next;
	while (next)
	{
		if (stack->value > next->value)
			return (0);
		stack = next;
		next = stack->next;
	}
	return (1);
}
