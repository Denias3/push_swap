/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:10:40 by emeha             #+#    #+#             */
/*   Updated: 2019/03/29 19:36:21 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation_check(t_swap *w)
{
	int i;
	int n;

	i = w->a->size;
	n = w->a->num[i];
	if (w != NULL && w->a != NULL && w->b != NULL && w->b->size == -1)
	{
		while (i > 0)
		{
			if (n > w->a->num[i - 1])
				return (1);
			i--;
			n = w->a->num[i];
		}
		return (0);
	}
	return (1);
}
