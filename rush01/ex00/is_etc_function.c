/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_etc_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:21:48 by dyoon             #+#    #+#             */
/*   Updated: 2023/07/30 17:15:33 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free(int **input);
int		ft_complete(int **sky);
int		find_blank(int **sky, int flag);
int		valid_place(int **sky, int *row_and_col_flag, int value, int **input);
void	data_direction(char *direction);
int		is_visible(int **sky, int *row_and_col, int **input, char flag);

int	**ft_malloc(void)
{
	int		i;
	int		**input;

	i = 0;
	input = malloc(4 * sizeof(int *));
	while (i < 4)
	{
		input[i] = malloc(4 * sizeof(int));
		++i;
	}
	return (input);
}

void	ft_free(int **input)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		free(input[i]);
		++i;
	}
	free(input);
}

int	ft_complete(int **sky)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (sky[i][j] == 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	find_blank(int **sky, int flag)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (sky[i][j] == 0)
			{
				if (flag == 0)
					return (i);
				return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_place(int **sky, int *row_and_col_flag, int value, int **input)
{
	int		i;
	char	direction[4];

	data_direction(direction);
	i = 0;
	while (i++ < 5)
	{
		if (value == sky[row_and_col_flag[0]][i - 1])
			return (0);
	}
	i = 0;
	while (i++ < 4)
	{
		if (value == sky[i - 1][row_and_col_flag[1]])
			return (0);
	}
	i = 0;
	while (i < 4)
	{
		sky[row_and_col_flag[0]][row_and_col_flag[1]] = value;
		if (!is_visible(sky, row_and_col_flag, input, direction[i]))
			return (0);
		i++;
	}
	return (1);
}
