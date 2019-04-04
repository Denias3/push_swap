/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:22:24 by emeha             #+#    #+#             */
/*   Updated: 2019/04/04 18:57:52 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	com_ra(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("ra\n");
	operations_rotate(w->a);
}

void	com_rb(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("rb\n");
	operations_rotate(w->b);
}

void	com_rr(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("rr\n");
	operations_rotate(w->a);
	operations_rotate(w->b);
}

void	com_rra(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("rra\n");
	operations_reverse_rotate(w->a);
}

void	com_rrb(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("rrb\n");
	operations_reverse_rotate(w->b);
}
