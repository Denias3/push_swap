/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_t_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:07:41 by emeha             #+#    #+#             */
/*   Updated: 2019/03/28 18:38:28 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_t_stack(int *num, int max)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->max = max;
	if (num == NULL)
	{
		num = (int*)malloc(sizeof(int) * (max + 1));
		new->size = -1;
	}
	else
		new->size = max;
	new->num = num;
	return (new);
}
