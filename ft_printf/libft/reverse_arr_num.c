/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_arr_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:07:25 by emeha             #+#    #+#             */
/*   Updated: 2019/03/28 18:40:42 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*reverse_arr_num(int *num, int len)
{
	int i;
	int tmp;

	tmp = 0;
	i = 0;
	while (i < len)
	{
		ft_swap(&num[i], &num[len]);
		i++;
		len--;
	}
	return (num);
}
