/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:19:07 by emeha             #+#    #+#             */
/*   Updated: 2019/04/06 22:43:24 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_swap *w;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	w = create_t_swap(argc, argv, 0);
	solve(w);
	return (0);
}
