/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:21:03 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/25 19:25:50 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex_write(unsigned int i, char a, char b)
{
	write(1, &a, 1);
	write(1, &b, 1);
	if (i % 2 == 1)
		write(1, &" ", 1);
}

void	ft_print_allow(void *a, unsigned int size, unsigned int index)
{
	int		i;
	char	*temp;

	temp = (char *)a;
	i = 0;
	while (i < 16 && index < size)
	{
		if (' ' <= *temp && *temp != 127)
			write(1, temp, 1);
		else
			write(1, ".", 1);
		temp++;
		index++;
		i++;
	}
	while (i != 16 && index < size)
	{
		if (' ' <= *temp && *temp != 127)
			write(1, temp, 1);
		else
			write(1, ".", 1);
		temp++;
		index++;
	}
}

void	ft_print_addr(void	*a)
{
	int						i;
	char					result[16];
	unsigned long long int	temp;
	char					*hex;	

	i = 15;
	hex = "0123456789abcdef";
	temp = (unsigned long long int)a;
	while (i >= 0)
	{
		result[i] = hex[temp % 16];
		temp /= 16;
		i--;
	}
	write(1, result, 16);
	write(1, &": ", 2);
}

void	ft_print_hex(void *addr, unsigned int size, unsigned int index)
{
	unsigned int	i;
	char			*hex;
	unsigned char	*test;

	i = 0;
	hex = "0123456789abcdef";
	test = (unsigned char *)addr;
	while (i < 16 && index < size)
	{
		ft_print_hex_write(i, hex[test[i] / 16], hex[test[i] % 16]);
		i++;
		(index)++;
	}
	while (i != 16 && index < size)
	{
		ft_print_hex_write(i, hex[test[i] / 16], hex[test[i] % 16]);
		i++;
		(index)++;
	}
	while (i < 16 && index >= size)
	{
		ft_print_hex_write(i, ' ', ' ');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void			*a;
	unsigned int	index;
	unsigned int	s;

	index = 0;
	a = addr;
	s = size;
	while (a < (addr + size))
	{
		ft_print_addr(a);
		ft_print_hex(a, size, index);
		ft_print_allow(a, size, index);
		a += 16;
		index += 16;
		write(1, &"\n", 1);
	}
	return (addr);
}
