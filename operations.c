/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:55:05 by jbrisset          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:10 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	if (!stack || !(stack->next))
		return ;
	else
		ft_swap(&stack->value, (&stack->next->value));
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack *tmp;

	tmp = NULL;
	if (!*src || *src == *dst)
		return ;
	if ((*src)->next)
	{
		tmp = (*src)->next;
		((*src)->next)->previous = NULL;
	}
	if (*dst)
	{
		(*dst)->previous = *src;
		(*src)->next = *dst;
		*dst = (*dst)->previous;
		(*dst)->previous = NULL;
	}
	else
	{
		(*src)->next = NULL;
		(*dst) = (*src);
	}
	(*src) = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack *first;

	if (!*stack || !(*stack)->next)
		return ;
	first = (*stack);
	((*stack)->next)->previous = NULL;
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	(*stack)->next = first;
	first->previous = *stack;
	first->next = NULL;
	while ((*stack)->previous)
		(*stack) = (*stack)->previous;
}

void	reverse(t_stack **head)
{
	t_stack *last;

	if (!*head || !(*head)->next)
		return ;
	while ((*head)->next)
		(*head) = (*head)->next;
	last = (*head);
	((*head)->previous)->next = NULL;
	while ((*head)->previous)
		(*head) = (*head)->previous;
	(*head)->previous = last;
	last->next = *head;
	last->previous = NULL;
	(*head) = (*head)->previous;
}

void	operate(t_stack **a, t_stack **b, char *code, int print)
{
	if (print)
		ft_printf("%s\n", code);
	if (!ft_strcmp(code, "pb"))
		push(a, b);
	if (!ft_strcmp(code, "pa"))
		push(b, a);
	if (!ft_strcmp(code, "sa") || !ft_strcmp(code, "ss"))
		swap(*a);
	if (!ft_strcmp(code, "sb") || !ft_strcmp(code, "ss"))
		swap(*b);
	if (!ft_strcmp(code, "ra") || !ft_strcmp(code, "rr"))
		rotate(a);
	if (!ft_strcmp(code, "rb") || !ft_strcmp(code, "rr"))
		rotate(b);
	if (!ft_strcmp(code, "rra") || !ft_strcmp(code, "rrr"))
		reverse(a);
	if (!ft_strcmp(code, "rrb") || !ft_strcmp(code, "rrr"))
		reverse(b);
}
