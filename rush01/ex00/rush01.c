/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseong <eseong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:53:49 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/30 17:39:40 by eseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int **input);
void	print_result(int **sky);
int		**solution(int **sky, int **input);
int		**ft_malloc(void);
void	ft_free(int **input);
int		ft_complete(int **sky);
int		find_blank(int **sky, int flag);
int		valid_place(int **sky, int *row_and_col_flag, int value, int **input);

void	rush(int **input)
{
	int		**sky;
	int		i;
	int		j;

	sky = ft_malloc();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			sky[i][j] = 0;
			++j;
		}
		++i;
	}
	if (solution(sky, input))
		print_result(sky);
	else
		write(1, "Error\n", 6);
	ft_free(sky);
}

int	**solution(int **sky, int **input)
{
	int		row;
	int		col;
	int		value;
	int		row_and_col_flag[3];

	if (ft_complete(sky))
		return (sky);
	row = find_blank(sky, 0);
	col = find_blank(sky, 1);
	row_and_col_flag[0] = row;
	row_and_col_flag[1] = col;
	value = 1;
	while (value < 5)
	{
		if (valid_place(sky, row_and_col_flag, value, input))
		{
			sky[row][col] = value;
			if (solution(sky, input))
				return (sky);
			sky[row][col] = 0;
		}
		value++;
	}
	return (0);
}

void	print_result(int **sky)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			sky[i][j] += 48;
			write(1, &sky[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}
