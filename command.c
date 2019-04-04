/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:40:11 by emeha             #+#    #+#             */
/*   Updated: 2019/04/04 18:58:24 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	com_sa(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("sa\n");
	operations_swap(w->a);
}

void	com_sb(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("sb\n");
	operations_swap(w->b);
}

void	com_ss(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("ss\n");
	operations_swap(w->a);
	operations_swap(w->b);
}

void	com_pa(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("pa\n");
	operations_push(w->a, w->b);
}

void	com_pb(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("pb\n");
	operations_push(w->b, w->a);
}
