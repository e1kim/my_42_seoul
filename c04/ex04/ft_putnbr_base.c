/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:10:36 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/27 18:05:58 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int n, char *base, int digit)
{
	char	mod;

	mod = base[n % digit];
	write(1, &mod, 1);
}

void	ft_putnbr(long long nbr, char *base, int digit)
{
	if (nbr < 0)
	{
		write(1, &"-", 1);
		ft_putnbr(-nbr, base, digit);
	}
	else
	{
		if (nbr >= digit)
		{
			ft_putnbr(nbr / digit, base, digit);
			ft_write(nbr % digit, base, digit);
		}
		else
		{
			ft_write(nbr, base, digit);
		}
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	digit;
	int	check_base[256];
	int	i;

	i = 0;
	digit = 0;
	while (i < 256)
	{
		check_base[i] = 0;
		i++;
	}
	while (base[digit] != '\0')
	{
		if (base[digit] == '+' || base[digit] == '-')
			return ;
		if (check_base[(int)base[digit]])
			return ;
		check_base[(int)base[digit]] = 1;
		digit++;
	}
	if (digit <= 1)
		return ;
	ft_putnbr(nbr, base, digit);
}
