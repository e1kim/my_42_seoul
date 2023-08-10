/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:46:47 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/09 21:33:32 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**ft_malloc(int length, int width)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	input = (char **)malloc((length + 1) * sizeof(char *));
	if (!input)
		exit (1);
	while (i < length + 1)
	{
		input[i] = (char *)malloc((width + 1) * sizeof(char));
		if (!input[i++])
			exit (1);
	}
	i = 0;
	while (i <= length)
	{
		j = 0;
		while (j <= width)
			input[i][j++] = 0;
		i++;
	}
	return (input);
}

void	map_init(char **map, char *buffer, int length)
{
	int		i;
	int		j;
	char	*ptr;

	i = 1;
	ptr = buffer;
	while (i < length + 1)
	{
		j = 1;
		while (*ptr != '\n')
		{
			if (i != 1)
			{
				map[i - 1][j] = *ptr;
			}
			ptr++;
			j++;
		}
		ptr++;
		i++;
	}
}

int	**ft_tab_malloc(int length, int width, char *print, char **map)
{
	int			i;
	int			j;
	int **const	tab = (int **)malloc(sizeof(int *) * (length + 1));

	if (!tab)
		return (0);
	i = 0;
	while (i < length + 1)
	{
		tab[i] = (int *)malloc(sizeof(int) * (width + 1));
		if (!tab[i])
			return (0);
		j = 0;
		while (j < width + 1)
		{
			if (map[i][j] == print[0])
				tab[i][j] = 1;
			else
				tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_malloc_and_init(t_data *data, t_map hint, char *buffer)
{
	int	len;
	int	wid;

	len = hint.length;
	wid = hint.width;
	data->map = ft_malloc(len + 1, wid + 1);
	map_init(data->map, buffer, len + 1);
	data->tab = ft_tab_malloc(len + 1, wid + 1, hint.print, data->map);
}
