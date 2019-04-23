/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:55:05 by jbrisset          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:10 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if ((*tab)[i] > (*tab)[i + 1])
		{
			ft_swap(&(*tab)[i], &(*tab)[i + 1]);
			i = -1;
		}
		i++;
	}
}

int			get_median(t_stack *h, int size, int diviser)
{
	int	*tab;
	int	i;
	int	med;

	if (!h || size <= 0)
		return (0);
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		return (0);
	i = 0;
	while (i < size)
		tab[i++] = 0;
	i = 0;
	med = 0;
	while (i < size && h)
	{
		tab[i] = h->value;
		h = h->next;
		i++;
	}
	sort_tab(&tab, size);
	med = tab[size / diviser];
	free(tab);
	return (med);
}
