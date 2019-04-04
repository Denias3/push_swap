/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:07:08 by emeha             #+#    #+#             */
/*   Updated: 2019/03/28 18:39:39 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_swap(t_swap *w)
{
	int s;

	if (w->a != NULL && w->b != NULL)
		s = (w->a->size > w->b->size) ? w->a->size : w->b->size;
	else if (w->a != NULL)
		s = w->a->size;
	else if (w->b != NULL)
		s = w->b->size;
	else
		s = 0;
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
		ft_printf("|%10c | %-10c|\n|%10c | %-10c|\n|-----------|-----------|\n", '-', '-', 'a', 'b');
	}
}
