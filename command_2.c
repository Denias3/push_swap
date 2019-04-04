/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:28:07 by emeha             #+#    #+#             */
/*   Updated: 2019/04/04 18:57:08 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	com_rrr(t_swap *w, int pr)
{
	if (pr == 1)
		ft_printf("rrr\n");
	operations_reverse_rotate(w->a);
	operations_reverse_rotate(w->b);
}
