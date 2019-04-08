/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 08:33:47 by emeha             #+#    #+#             */
/*   Updated: 2019/04/08 09:14:09 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		serc_num(t_swap *w, int sr)
{
	int i;

	i = 0;
	while (i <= w->a->size)
	{
		if (w->a->num[i] == sr)
			return (i);
		i++;
	}
	return (-1);
}

int		serc_num_more(t_swap *w, int *num, int sr, int *res)
{
	int i;
	int j;

	i = 0;
	while (i <= w->a->size)
	{
		if (num[i] > sr)
		{
			j = 0;
			while (j <= w->a->size)
			{
				if (w->a->num[j] == num[i])
				{
					*res = num[i];
					return (j);
				}
				j++;
			}
		}
		i++;
	}
	return (-1);
}

int		serc_num_more_2(t_swap *w, int *num, int sr)
{
	int i;
	int j;

	i = 0;
	while (i <= w->a->size)
	{
		if (num[i] > sr)
		{
			j = 0;
			while (j <= w->a->size)
			{
				if (w->a->num[j] == num[i])
					return (j);
				j++;
			}
		}
		i++;
	}
	free(&num);
	return (-1);
}
