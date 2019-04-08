/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 08:36:59 by emeha             #+#    #+#             */
/*   Updated: 2019/04/08 08:48:37 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validation_stack_1(t_swap *w, int *posit)
{
	int i;

	i = 0;
	while (i < w->a->size)
	{
		if ((w->a->num[i] == posit[0] &&
			w->a->num[i + 1] == posit[w->a->size]) ||
			(w->a->num[i] == posit[w->a->size] &&
			w->a->num[i + 1] == posit[0]))
			i++;
		else if (w->a->num[i] > w->a->num[i + 1])
			i++;
		else
		{
			free(posit);
			return (1);
		}
	}
	return (0);
}

int			validation_stack(t_swap *w)
{
	int *posit;

	posit = position(w->a);
	serc_num(w, posit[0]);
	if (w->a->num[0] > w->a->num[w->a->size])
	{
		if (!((w->a->num[0] == posit[0] &&
			w->a->num[w->a->size] == posit[w->a->size]) ||
			(w->a->num[0] == posit[w->a->size] &&
			w->a->num[w->a->size] == posit[0])))
		{
			free(posit);
			return (1);
		}
	}
	if (validation_stack_1(w, posit) == 1)
		return (1);
	free(posit);
	return (0);
}

void		push_b(t_swap *w)
{
	int *posit;
	int i;

	i = w->a->size;
	posit = position(w->a);
	while (i >= 0)
	{
		if (w->a->size <= 2 || validation_stack(w) == 0)
		{
			free(posit);
			return ;
		}
		if (posit[0] != w->a->num[w->a->size] &&
			posit[w->a->max] != w->a->num[w->a->size])
			com_pb(w, 1);
		else
			com_ra(w, 1);
		i--;
	}
	free(posit);
}

void		check_three(t_swap *w)
{
	if (w->a->size == 2)
	{
		if (w->a->num[w->a->size] > w->a->num[w->a->size - 1] &&
			w->a->num[w->a->size] < w->a->num[0] &&
			w->a->num[w->a->size - 1] < w->a->num[0])
			com_sa(w, 1);
		else if (w->a->num[w->a->size] > w->a->num[w->a->size - 1] &&
				w->a->num[w->a->size] > w->a->num[0] &&
				w->a->num[w->a->size - 1] > w->a->num[0])
			com_sa(w, 1);
		else if (w->a->num[w->a->size] < w->a->num[w->a->size - 1] &&
				w->a->num[w->a->size] < w->a->num[0] &&
				w->a->num[w->a->size - 1] > w->a->num[0])
			com_sa(w, 1);
	}
}

int			comparison(t_best *best, t_best *tmp)
{
	int be;
	int tm;

	be = 0;
	tm = 0;
	if (best->wh_b == best->wh_a)
	{
		if (best->a > best->b)
			be = best->a;
		else
			be = best->b;
	}
	else
		be = best->a + best->b;
	if (tmp->wh_b == tmp->wh_a)
	{
		if (tmp->a > tmp->b)
			tm = tmp->a;
		else
			tm = tmp->b;
	}
	else
		tm = tmp->a + tmp->b;
	return ((tm <= be) ? 1 : 0);
}
