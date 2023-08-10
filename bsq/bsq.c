/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:13:31 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/09 21:33:32 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_min(int val1, int val2, int val3)
{
	int	ret;

	ret = val1;
	if (ret > val2)
		ret = val2;
	if (ret > val3)
		ret = val3;
	return (ret);
}

void	ft_update_max(int max, t_max *info, int row, int col)
{
	info->size = max;
	info->row = row;
	info->col = col;
}

void	ft_find_bsq(int length, int width, int **tab, t_max *info)
{
	int	i;
	int	j;
	int	max;
	int	min;

	i = 1;
	max = 0;
	ft_update_max(0, info, 1, 1);
	while (i <= length)
	{
		j = 1;
		while (j <= width)
		{
			min = ft_min(tab[i][j - 1], tab[i - 1][j - 1], tab[i - 1][j]);
			if (tab[i][j])
				tab[i][j] = min + 1;
			if (max < tab[i][j])
			{
				max = tab[i][j];
				ft_update_max(max, info, i, j);
			}
			j++;
		}
		i++;
	}
}

void	print_result(char **sol, int length, int width)
{
	int		i;
	int		j;

	i = 1;
	while (i < length)
	{
		j = 1;
		while (j < width)
		{
			write(1, &sol[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		++i;
	}
}

void	ft_print_sol(t_max info, char **sol, t_map hint)
{
	int	i;
	int	j;
	int	start_row;
	int	start_col;

	i = 0;
	start_row = info.row - info.size + 1;
	start_col = info.col - info.size + 1;
	while (i < info.size)
	{
		j = 0;
		while (j < info.size)
		{
			sol[i + start_row][j + start_col] = hint.print[2];
			j++;
		}
		i++;
	}
	print_result(sol, hint.length + 1, hint.width + 1);
}
