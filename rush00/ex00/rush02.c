/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:20:17 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/22 14:20:19 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

char	change_to_special(int col, int row, int i, int j)
{
	char	space;

	space = ' ';
	if (i == 0 && j == 0)
		return ('A');
	if (i == 0 && j == col - 1)
		return ('A');
	if (i == row - 1 && j == 0)
		return ('C');
	if (i == row - 1 && j == col - 1)
		return ('C');
	if (i == 0 || i == row - 1)
		return ('B');
	if (j == 0 || j == col - 1)
		return ('B');
	return (space);
}

void	rush(int col, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			ft_putchar(change_to_special(col, row, i, j));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
