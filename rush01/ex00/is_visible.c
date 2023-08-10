/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_visible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:53:49 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/30 17:15:23 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_visible_left(int **sky, int **input, int row, int col);
int	is_visible_right(int **sky, int **input, int row, int col);
int	is_visible_top(int **sky, int **input, int row, int col);
int	is_visible_bottom(int **sky, int **input, int row, int col);

int	is_visible(int **sky, int *row_and_col, int **input, char flag)
{
	int		building_count;
	int		zero_count;
	int		max;

	building_count = 0;
	zero_count = 0;
	max = 0;
	if (flag == 'l')
		return (is_visible_left(sky, input, row_and_col[0], row_and_col[1]));
	else if (flag == 'r')
		return (is_visible_right(sky, input, row_and_col[0], row_and_col[1]));
	else if (flag == 't')
		return (is_visible_top(sky, input, row_and_col[0], row_and_col[1]));
	else
		return (is_visible_bottom(sky, input, row_and_col[0], row_and_col[1]));
	return (1);
}

int	is_visible_left(int **sky, int **input, int row, int col)
{
	int		i;
	int		zero_count;
	int		max;
	int		building_count;

	i = 0;
	zero_count = 0;
	max = 0;
	building_count = 0;
	while (i < 4)
	{
		if (sky[row][i] == 0)
			++zero_count;
		if (max < sky[row][i])
		{
			max = sky[row][i];
			++building_count;
		}
		++i;
	}
	sky[row][col] = 0;
	if (zero_count == 0)
		return (building_count == input[2][row]);
	return (-1);
}

int	is_visible_right(int **sky, int **input, int row, int col)
{
	int		i;
	int		zero_count;
	int		max;
	int		building_count;

	i = 3;
	zero_count = 0;
	max = 0;
	building_count = 0;
	while (i >= 0)
	{
		if (sky[row][i] == 0)
			++zero_count;
		if (max < sky[row][i])
		{
			max = sky[row][i];
			++building_count;
		}
		--i;
	}
	sky[row][col] = 0;
	if (zero_count == 0)
		return (building_count == input[3][row]);
	return (-1);
}

int	is_visible_top(int **sky, int **input, int row, int col)
{
	int		i;
	int		zero_count;
	int		max;
	int		building_count;

	i = 0;
	zero_count = 0;
	max = 0;
	building_count = 0;
	while (i < 4)
	{
		if (sky[i][col] == 0)
			++zero_count;
		if (max < sky[i][col])
		{
			max = sky[i][col];
			++building_count;
		}
		++i;
	}
	sky[row][col] = 0;
	if (zero_count == 0)
		return (building_count == input[0][col]);
	return (-1);
}

int	is_visible_bottom(int **sky, int **input, int row, int col)
{
	int		i;
	int		zero_count;
	int		max;
	int		building_count;

	i = 3;
	zero_count = 0;
	max = 0;
	building_count = 0;
	while (i >= 0)
	{
		if (sky[i][col] == 0)
			++zero_count;
		if (max < sky[i][col])
		{
			max = sky[i][col];
			++building_count;
		}
		--i;
	}
	sky[row][col] = 0;
	if (zero_count == 0)
		return (building_count == input[1][col]);
	return (-1);
}
