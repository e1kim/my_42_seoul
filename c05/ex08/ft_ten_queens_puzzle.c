/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:15:08 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/30 15:19:33 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ok(int *queens, int idx)
{
	int	i;
	int	flag;

	i = 0;
	while (i < idx)
	{
		if (queens[idx] == queens[i])
			return (0);
		if (queens[i] - queens[idx] < 0)
		{
			flag = (queens[idx] - queens[i] == idx - i);
		}
		else
		{
			flag = (queens[i] - queens[idx] == idx - i);
		}
		if (flag)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print(int *queens)
{
	int		j;
	char	p;

	j = 0;
	while (j < 10)
	{
		p = queens[j] + '0';
		write(1, &p, 1);
		j++;
	}
	write(1, "\n", 1);
}

void	solution(int *queens, int idx, int *count)
{
	int	i;

	i = 0;
	if (idx == 10)
	{
		(*count)++;
		ft_print(queens);
		return ;
	}
	while (i < 10)
	{
		queens[idx] = i;
		if (ok(queens, idx))
		{
			solution(queens, idx + 1, count);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 10)
	{
		queens[i] = 0;
		i++;
	}
	solution(queens, 0, &count);
	return (count);
}
