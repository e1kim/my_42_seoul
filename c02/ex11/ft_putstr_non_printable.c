/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:03:17 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/25 11:47:08 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(unsigned char n)
{
	char	div;
	char	mod;
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &"\\", 1);
	div = hex[n / 16];
	mod = hex[n % 16];
	write(1, &div, 1);
	write(1, &mod, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((0 < str[index] && str[index] < ' ') || str[index] == 127)
		{
			ft_write(str[index]);
		}
		else if (str[index] < 0)
		{
			ft_write(str[index]);
		}
		else
		{
			write(1, &str[index], 1);
		}
		index++;
	}
}
