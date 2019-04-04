/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:29:08 by emeha             #+#    #+#             */
/*   Updated: 2019/03/29 16:43:55 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_swap(t_stack *st)
{
	if (st != NULL && st->size > 0)
		ft_swap(&st->num[st->size], &st->num[st->size - 1]);
}

void	operations_push(t_stack *st1, t_stack *st2)
{
	if (st1 != NULL && st2 != NULL && st1->size > -1)
	{
		(st2->size)++;
		st2->num[st2->size] = st1->num[st1->size];
		(st1->size)--;
	}
}

void	operations_rotate(t_stack *st)
{
	int i;
	int	*num2;

	i = 0;
	if (st != NULL && st->size > 0)
	{
		num2 = arr_numdup(st->num, st->max + 1);
		st->num[0] = num2[st->size];
		while (i < st->size)
		{
			st->num[i + 1] = num2[i];
			i++;
		}
		free(num2);
	}
}

void	operations_reverse_rotate(t_stack *st)
{
	int i;
	int	*num2;

	i = st->size;
	if (st != NULL && st->size > 0)
	{
		num2 = arr_numdup(st->num, st->max + 1);
		st->num[st->size] = num2[0];
		while (i > 0)
		{
			st->num[i - 1] = num2[i];
			i--;
		}
		free(num2);
	}
}
