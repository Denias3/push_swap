/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:07:07 by emeha             #+#    #+#             */
/*   Updated: 2019/04/08 02:30:41 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_number_space_2(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
		else if (str[*i] == ' ' && (str[(*i) - 1] >= '0' &&
			str[(*i) - 1] <= '9'))
			break ;
		else
			return (0);
	}
	return (1);
}

int			check_number_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == ' ')
		{
			if (str[i] == '-')
			{
				if (str[i - 1] >= '0' && str[i - 1] <= '9')
					return (0);
				i++;
				if (check_number_space_2(str, &i) == 0)
					return (0);
				if (str[i] == '\0' && str[i - 1] != '-')
					return (1);
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}
