/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:33:06 by emeha             #+#    #+#             */
/*   Updated: 2019/04/08 10:30:11 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	distributor(t_swap *w, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		com_sa(w, 0);
	else if (ft_strcmp(line, "sb") == 0)
		com_sb(w, 0);
	else if (ft_strcmp(line, "ss") == 0)
		com_ss(w, 0);
	else if (ft_strcmp(line, "pa") == 0)
		com_pa(w, 0);
	else if (ft_strcmp(line, "pb") == 0)
		com_pb(w, 0);
	else if (ft_strcmp(line, "ra") == 0)
		com_ra(w, 0);
	else if (ft_strcmp(line, "rb") == 0)
		com_rb(w, 0);
	else if (ft_strcmp(line, "rr") == 0)
		com_rr(w, 0);
	else if (ft_strcmp(line, "rra") == 0)
		com_rra(w, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		com_rrb(w, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		com_rrr(w, 0);
	else
		return (1);
	return (0);
}

static void	free_arr(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	checker_2(t_swap *w, char *str, int flag)
{
	char	**arr_str;
	int		i;

	i = 0;
	arr_str = ft_strsplit(str, '\n');
	while (arr_str[i])
	{
		if (distributor(w, arr_str[i]) == 1)
		{
			ft_printf("Error\n");
			free_arr(arr_str);
			exit(1);
		}
		if (flag == 1)
			print_swap(w);
		i++;
	}
	free_arr(arr_str);
	if (validation_check(w) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

int			main(int argc, char **argv)
{
	t_swap	*w;
	char	*line;
	char	*str;
	int		flag;

	flag = 0;
	if (argc < 2)
		return (0);
	if (ft_strcmp(argv[1], "-v") == 0)
		flag = 1;
	w = create_t_swap(argc, argv, flag);
	str = ft_strnew(0);
	while (get_next_line(0, &line))
	{
		str = ft_strjoin_free(str, line, 1, 1);
		str = ft_strjoin_free(str, "\n", 1, 0);
	}
	checker_2(w, str, flag);
	free(str);
	free_t_swap(w);
	return (0);
}
