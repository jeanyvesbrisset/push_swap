/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_handler                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:55:05 by jbrisset          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:10 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_b(t_stack **a, t_stack **b, int size, t_data *data)
{
	int	i;

	i = 0;
	while (i++ < size && (*b))
	{
		if ((*b)->value >= data->med)
		{
			operate(a, b, "pa", 1);
			data->count_a++;
		}
		else if ((*b)->value < data->med && check_above(*b, data->med))
		{
			operate(a, b, "rb", 1);
			data->count_b++;
		}
	}
}

void		handle_b(t_stack **a, t_stack **b, int size)
{
	int		i;
	t_data	data;

	data.med = get_median(*b, size, 2);
	data.count_b = 0;
	data.count_a = 0;
	i = 0;
	if (size == 1 || size == 2 || is_rev_sort_size(*b, size))
	{
		while (i++ < size)
			operate(a, b, "pa", 1);
		push_swap(a, b, size);
		return ;
	}
	else if (size == 3)
		return (sort_b(a, b));
	divide_b(a, b, size, &data);
	i = 0;
	while (i++ < data.count_b && get_stack_size(*b) != size - data.count_a &&
		!is_rev_sorted(*b))
		operate(a, b, "rrb", 1);
	push_swap(a, b, data.count_a);
	handle_b(a, b, size - data.count_a);
}

void		sort_b(t_stack **sta, t_stack **stb)
{
	int a;
	int b;
	int c;

	a = (*stb)->value;
	b = (*stb)->next->value;
	c = (*stb)->next->next->value;
	if (a > b)
		operate(sta, stb, "pa", 1);
	operate(sta, stb, "sb", 1);
	operate(sta, stb, "pa", 1);
	if (b < c && c < a)
		return (operate(sta, stb, "pa", 1));
	else if ((c < a && a < b) || (b < a && a < c))
	{
		(b > c) ? operate(sta, stb, "pa", 1) : operate(sta, stb, "sa", 1);
		return (operate(sta, stb, "pa", 1));
	}
	operate(sta, stb, "sb", 1);
	operate(sta, stb, "pa", 1);
	if (b < c)
		operate(sta, stb, "sa", 1);
	operate(sta, stb, "pa", 1);
}
