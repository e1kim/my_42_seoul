/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:07 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/04 17:44:02 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	number;

	number = 0;
	while (str[number] != '\0')
	{
		number++;
	}
	return (number);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*result;
	int		i;

	i = 0;
	size = ft_strlen(src);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (0);
	while (i < size)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	t_stock_str			*result;

	i = 0;
	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
		if (!result[i].copy)
			return (0);
		i++;
	}
	result[i].str = 0;
	return (result);
}
