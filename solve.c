/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:16:55 by emeha             #+#    #+#             */
/*   Updated: 2019/04/08 10:35:18 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		best_item_1(t_swap *w, t_best *tmp, int sr_i, int i)
{
	if (sr_i <= w->a->size - sr_i - 1)
	{
		tmp->a = sr_i + 1;
		tmp->wh_a = 1;
	}
	else
	{
		tmp->a = w->a->size - sr_i;
		tmp->wh_a = 0;
	}
	if (i <= w->b->size - i - 1)
	{
		tmp->b = i + 1;
		tmp->wh_b = 1;
	}
	else
	{
		tmp->b = w->b->size - i;
		tmp->wh_b = 0;
	}
}

static t_best	*best_item(t_swap *w)
{
	int		*posit;
	int		sr_i;
	int		i;
	t_best	*best;
	t_best	*tmp;

	i = 0;
	best = (t_best*)malloc(sizeof(t_best));
	tmp = (t_best*)malloc(sizeof(t_best));
	posit = position(w->a);
	while (i <= w->b->size)
	{
		sr_i = serc_num_more_2(w, posit, w->b->num[i]);
		best_item_1(w, tmp, sr_i, i);
		if (i++ == 0 || comparison(best, tmp))
		{
			best->a = tmp->a;
			best->b = tmp->b;
			best->wh_a = tmp->wh_a;
			best->wh_b = tmp->wh_b;
		}
	}
	free(posit);
	free(tmp);
	return (best);
}

static void		solve_2(t_swap *w, t_best *best)
{
	if (best->a > 0)
	{
		if (best->wh_a == 0)
			com_ra(w, 1);
		else
			com_rra(w, 1);
		best->a--;
	}
	else if (best->b > 0)
	{
		if (best->wh_b == 0)
			com_rb(w, 1);
		else
			com_rrb(w, 1);
		best->b--;
	}
}

static void		solve_1(t_swap *w, t_best *best)
{
	while (best->wh_a == best->wh_b && (best->a > 0 && best->b > 0))
	{
		if (best->wh_a == 0 && best->wh_b == 0)
		{
			com_rr(w, 1);
			best->a--;
			best->b--;
		}
		else if (best->wh_a == 1 && best->wh_b == 1)
		{
			com_rrr(w, 1);
			best->a--;
			best->b--;
		}
	}
	solve_2(w, best);
}

void			solve(t_swap *w)
{
	int		*posit;
	int		sr_i;
	t_best	*best;

	push_b(w);
	check_three(w);
	while (w->b->size != -1)
	{
		best = best_item(w);
		while (best->a > 0 || best->b > 0)
			solve_1(w, best);
		free(best);
		com_pa(w, 1);
	}
	posit = position(w->a);
	sr_i = serc_num(w, posit[0]);
	while (w->a->num[w->a->size] != posit[0])
		if ((w->a->size / 2) <= sr_i)
			com_ra(w, 1);
		else
			com_rra(w, 1);
	reverse_arr_num(w->a->num, w->a->size);
	free(posit);
	free_t_swap(w);
}
