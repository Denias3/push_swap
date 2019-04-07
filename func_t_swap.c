/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_t_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:34:31 by emeha             #+#    #+#             */
/*   Updated: 2019/04/06 21:13:09 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*create_t_swap(int ac, char **av, int start)
{
	t_stack	*a;
	t_stack	*b;
	t_swap	*new;
	int		*num;
	int		size;

	new = (t_swap*)malloc(sizeof(t_swap));
	num = check_arg(ac, av, &size, start);
	a = create_t_stack(num, size - 1);
	b = create_t_stack(NULL, size - 1);
	new->a = a;
	new->b = b;
	return (new);
}
