/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 01:39:49 by emeha             #+#    #+#             */
/*   Updated: 2019/04/07 01:58:48 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int max_elem_arr(int *arr, int size)
// {
// 	int num;
// 	int len;
// 	int i;
//
// 	len = 0;
// 	i = 0;
// 	num = arr[i];
// 	while (i <= size)
// 	{
// 		if (arr[i] > num)
// 		{
// 			num = arr[i];
// 			len = i;
// 		}
// 		i++;
// 	}
// 	return (len);
// }
//
static int min_elem_arr(int *arr, int size)
{
	int num;
	int len;
	int i;

	len = 0;
	i = 0;
	num = arr[i];
	while (i <= size)
	{
		if (arr[i] < num)
		{
			num = arr[i];
			len = i;
		}
		i++;
	}
	return (len);
}

static int position_elem_arr(t_stack *st, int min)
{
	int num;
	int len;
	int i;

	len = 0;
	i = 0;
	while (i <= st->size)
	{
		if (st->num[i] > st->num[min])
		{
			num = st->num[i];
			break ;
		}
		i++;
	}
	i = 0;
	while (i <= st->size)
	{
		if (st->num[i] < st->num[min] || i == min)
		{
			i++;
			continue ;
		}
		if (st->num[i] <= num)
		{
			num = st->num[i];
			len = i;
		}
		i++;
	}
	return (len);
}

int			*position(t_stack *st)
{
	int min;
	int len;
	int i;
	int *posit;

	posit = (int*)malloc(sizeof(int) * (st->size + 1));
	i = 0;
	min = min_elem_arr(st->num, st->size);
	posit[0] = st->num[min];
	if (st->size > 0)
	{
		len = position_elem_arr(st, min);
		posit[1] = st->num[len];
		i = 2;
		while (i <= st->size)
		{
			len = position_elem_arr(st, len);
			posit[i] = st->num[len];
			i++;
		}
		i = 0;
	}
	return (posit);
}
