/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:07:07 by emeha             #+#    #+#             */
/*   Updated: 2019/03/28 18:54:36 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_number_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			i++;
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (0);
			while (str[i])
			{
				if (!(str[i] >= '0' && str[i] <= '9'))
				{
					if (str[i] == ' ')
						break ;
					else
						return (0);
				}
				i++;
			}
			return (1);
		}
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}
