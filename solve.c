/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:16:55 by emeha             #+#    #+#             */
/*   Updated: 2019/04/07 00:19:46 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_position(int *num, int size)
{
	int i;

	i = size;
	while (i >= 0)
	{
		ft_printf("%d\n", num[i]);
		i--;
	}
	ft_printf("\n");
}

int		serc_num(int *num, int size, int sr)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (num[i] == sr)
		{
			return (num[i]);
		}
		i++;
	}
	return (-1);
}

int		serc_num_more(t_swap *w, int *num, int size, int sr)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i <= size)
	{
		if (num[i] > sr)
		{
			j = 0;
			while (j <= size)
			{
				if (w->a->num[j] == num[i])
					return (j);
				j++;
			}
		}
		i++;
	}
	return (-1);
}

void	push_b(t_swap *w)
{
	int *posit;
	int i;

	i = w->a->size;
	posit = position(w->a);
	while (i >= 0)
	{
		if (w->a->size == 2)
			return ;
		if (posit[0] != w->a->num[w->a->size] &&
			posit[w->a->max] != w->a->num[w->a->size] &&
			posit[w->a->max / 2] != w->a->num[w->a->size])
		com_pb(w, 1);
		else
			com_ra(w, 1);
//		print_swap(w);
		i--;
	}
	free(posit);
}

void	check_three(t_swap *w)
{
	if (w->a->num[w->a->size] > w->a->num[w->a->size - 1] &&
		w->a->num[w->a->size] < w->a->num[0] &&
		w->a->num[w->a->size -1] < w->a->num[0])
		com_sa(w, 1);
	if (w->a->num[w->a->size] > w->a->num[w->a->size - 1] &&
		w->a->num[w->a->size] > w->a->num[0] &&
		w->a->num[w->a->size -1] > w->a->num[0])
		com_sa(w, 1);
	if (w->a->num[w->a->size] < w->a->num[w->a->size - 1] &&
		w->a->num[w->a->size] < w->a->num[0] &&
		w->a->num[w->a->size -1] > w->a->num[0])
		com_sa(w, 1);
}

void	solve(t_swap *w)
{
	int *posit;
	int sr_i;
	int sr;

	sr_i = 0;
	sr = 0;
//	print_swap(w);
	push_b(w);
	check_three(w);
//	print_swap(w);
	while (w->b->size != -1)
	{
		posit = position(w->a);
		if ((sr_i = serc_num_more(w ,posit, w->a->size, w->b->num[w->b->size])) != -1)
		{
			if ((sr = serc_num(w->a->num, w->a->size, w->a->num[sr_i])) != -1)
			{
				while (sr != w->a->num[w->a->size])
				{
					if ((w->a->size / 2) > sr_i)
						com_rra(w, 1);
					else
						com_ra(w, 1);
//					print_swap(w);
				}
				com_pa(w, 1);
//				print_swap(w);
			}
		}
		free(posit);
	}
	print_swap(w);
	posit = position(w->a);
	if ((sr_i = serc_num(w->a->num, w->a->size, posit[0])) != -1)
	{
		while (w->a->num[w->a->size] != posit[0])
		{
			if ((w->a->size / 2) <= sr_i)
				com_ra(w, 1);
			else
				com_rra(w, 1);
			print_swap(w);
		}
	}
	print_swap(w);
	reverse_arr_num(w->a->num, w->a->size);
	free(posit);
}
