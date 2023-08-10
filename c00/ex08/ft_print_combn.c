/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:10:41 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/24 15:36:19 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_sol(char *arr, int n)
{
	int	i;
	int	notlast;
	int	index;

	i = 0;
	notlast = 1;
	index = 0;
	while (index < n)
	{
		ft_putchar(arr[index] + '0');
		if (index == 0 && arr[index] == 10 - n + index)
		{
			notlast = 0;
		}
		index++;
	}
	if (notlast)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	solution(char *arr, int j, int n, int before)
{
	int	i;

	if (n == j)
	{
		print_sol(arr, n);
		return ;
	}
	else
	{	
		i = before + 1;
		while (i <= 10 - n + j)
		{
			arr[j] = i;
			solution(arr, j + 1, n, i);
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];
	int		i;
	int		temp;

	i = 0;
	temp = n;
	while (temp > 0)
	{
		arr[i] = i;
		i++;
		temp--;
	}
	solution(arr, 0, n, -1);
}
