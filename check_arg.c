/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:32:11 by emeha             #+#    #+#             */
/*   Updated: 2019/04/08 11:32:03 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_num_stack(char **str, int *size)
{
	char	**str_spl;
	int		*num;
	int		i;
	int		ch;

	i = 0;
	ch = 0;
	str_spl = ft_strsplit(*str, ' ');
	free(*str);
	num = (int*)malloc(sizeof(int) * (*size));
	while (str_spl[i])
	{
		if (ft_ll_atoi(str_spl[i]) > 2147483647 ||
			ft_ll_atoi(str_spl[i]) < -2147483648 || ft_strlen(str_spl[i]) > 11)
			ch = 1;
		num[i] = ft_ll_atoi(str_spl[i]);
		ft_strdel(&str_spl[i++]);
	}
	free(str_spl);
	if (diff_num(num, *size) == 0 || ch)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	return (num);
}

static void	check_space(char *str)
{
	int i;
	int ch;

	ch = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			ch = 0;
		}
		i++;
	}
	if (ch)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

int			*check_arg(int arc, char **arg, int *size, int start)
{
	char	*str;
	int		i;

	str = ft_strnew(0);
	(*size) = arc;
	i = 1 + start;
	while (i < (*size))
	{
		if (check_number_space(arg[i]) == 0)
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i++;
	}
	i = 1 + start;
	while (i < (*size))
	{
		str = ft_strjoin_free(str, arg[i], 1, 0);
		str = ft_strjoin_free(str, " ", 1, 0);
		i++;
	}
	check_space(str);
	(*size) = num_delim(str, ' ');
	return (reverse_arr_num(create_num_stack(&str, size), *(size) - 1));
}
