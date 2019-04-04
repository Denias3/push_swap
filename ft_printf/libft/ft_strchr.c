/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:49:55 by emeha             #+#    #+#             */
/*   Updated: 2018/12/02 12:47:28 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] || i == 0)
	{
		if (s[i + 1] == c && s[i + 1] == '\0')
			return ((char*)(&s[i + 1]));
		if (s[i] == c)
			return ((char*)(&s[i]));
		i++;
	}
	return (NULL);
}