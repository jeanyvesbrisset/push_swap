/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:55:05 by jbrisset          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:10 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_a(t_stack **a, t_stack **b, int size, t_data *d)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if ((*a)->value < d->med)
		{
			operate(a, b, "pb", 1);
			d->count_b++;
		}
		else if ((*a)->value >= d->med && check_below(*a, d->med))
		{
			if ((*b) && (*b)->next && d->first && ((*b)->value < d->med_low))
				operate(a, b, "rr", 1);
			else
				operate(a, b, "ra", 1);
			d->count_a++;
		}
	}
}

int			handle_a(t_stack **a, t_stack **b, int size)
{
	int		i;
	t_data	data;

	data.med = get_median(*a, size, 2);
	data.med_low = get_median(*a, size, 4);
	data.count_b = 0;
	data.count_a = 0;
	data.first = ((*b) ? 0 : 1);
	i = 0;
	divide_a(a, b, size, &data);
	while (data.count_a-- > 0 && !is_sorted(*a) &&
		get_stack_size(*a) != size - data.count_b)
		operate(a, b, "rra", 1);
	return (size - data.count_b);
}

void		sort_a(t_stack **sta, t_stack **stb)
{
	int a;
	int b;
	int c;

	if (get_stack_size(*sta) == 3)
		return (sort_three_a(sta));
	a = (*sta)->value;
	b = (*sta)->next->value;
	c = (*sta)->next->next->value;
	if (a > b && (*stb) && (*stb)->next)
		(*stb)->value < (*stb)->next->value ?
		operate(sta, stb, "ss", 1) : operate(sta, stb, "sa", 1);
	if (c > a && a > b)
		return ;
	operate(sta, stb, "ra", 1);
	if ((*stb) && (*stb)->next)
		(*stb)->value < (*stb)->next->value ?
		operate(sta, stb, "ss", 1) : operate(sta, stb, "sa", 1);
	operate(sta, stb, "rra", 1);
	if (b > c && a > c)
		operate(sta, stb, "sa", 1);
}

void		sort_three_a(t_stack **st)
{
	int	a;
	int	b;
	int c;

	a = (*st)->value;
	b = (*st)->next->value;
	c = (*st)->next->next->value;
	if (a < b && b > c && a < c)
	{
		operate(st, NULL, "sa", 1);
		operate(st, NULL, "ra", 1);
	}
	else if (a > b && a < c)
		operate(st, NULL, "sa", 1);
	else if (a < b && c < a)
		operate(st, NULL, "rra", 1);
	else if (a > b && b > c && a > c)
	{
		operate(st, NULL, "ra", 1);
		operate(st, NULL, "sa", 1);
	}
	else if (a > b && a > c && b < c)
		operate(st, NULL, "ra", 1);
}
