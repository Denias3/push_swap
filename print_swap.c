/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:07:08 by emeha             #+#    #+#             */
/*   Updated: 2019/04/08 08:26:48 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_swap_1(t_swap *w, int *s)
{
	if (w->a != NULL && w->b != NULL)
		*s = (w->a->size > w->b->size) ? w->a->size : w->b->size;
	else if (w->a != NULL)
		*s = w->a->size;
	else if (w->b != NULL)
		*s = w->b->size;
	else
		*s = 0;
}

void		print_swap(t_swap *w)
{
	int s;

	print_swap_1(w, &s);
	if (w->a != NULL || w->b != NULL)
	{
		ft_printf("\n|-----------|-----------|\n");
		while (s >= 0)
		{
			if (w->a != NULL && s <= w->a->size && w->a->num != NULL)
				ft_printf("|%10d ", w->a->num[s]);
			else
				ft_printf("|%10c ", ' ');
			if (w->b != NULL && s <= w->b->size && w->b->num != NULL)
				ft_printf("| %-10d|", w->b->num[s]);
			else
				ft_printf("| %-10c|", ' ');
			ft_putchar('\n');
			s--;
		}
		ft_printf("|%10c | %-10c|\n|%10c | %-10c|", '-', '-', 'a', 'b');
		ft_printf("\n|-----------|-----------|\n");
	}
}
