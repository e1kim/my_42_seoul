/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:19:34 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/22 14:19:36 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

char	change_to_special(int col, int row, int i, int j)
{
	char	corner;
	char	rl;
	char	ud;
	char	space;

	corner = 'o';
	rl = '-';
	ud = '|';
	space = ' ';
	if ((i == 0 && j == 0) || (i == 0 && j == col - 1))
		return (corner);
	if ((i == row - 1 && j == 0) || (i == row - 1 && j == col - 1))
		return (corner);
	if (i == 0 || i == row - 1)
		return (rl);
	if (j == 0 || j == col - 1)
		return (ud);
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
