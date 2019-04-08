/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_t_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:34:31 by emeha             #+#    #+#             */
/*   Updated: 2019/04/08 09:54:21 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_t_swap(t_swap *w)
{
	free(w->a->num);
	free(w->a);
	free(w->b->num);
	free(w->b);
	free(w);
}

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
